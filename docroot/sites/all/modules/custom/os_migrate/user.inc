<?php
/**
 * @file
 * User migration support for OpenSource.com.
 */

/**
 * Mappings for profile -> fields on OpenSource.com user.
 */
class OsMigrateUserMigration extends DrupalUser6Migration {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    $this->addFieldMapping('field_display_name', 'profile_display_name');
    $this->addFieldMapping('field_location', 'profile_location');
    $this->addFieldMapping('field_website', 'profile_website');
    $this->addFieldMapping('field_user_about', 'profile_bio');
    $this->addFieldMapping('field_user_about:format')
         ->defaultValue('panopoly_wysiwyg_text');

    $this->addFieldMapping('role_names', 'role_names', FALSE);

    // Picture migration.
    $this->addFieldMapping('field_user_picture', 'picture', FALSE)
         ->sourceMigration('OsUserPicture');
    $this->addFieldMapping('field_user_picture:file_class')
         ->defaultValue('MigrateFileFid');

    // Force the user files to be preserved even if users were rolled-back.
    // This should probably be removed in final run.
    // Alternatively, this can remain but migrate entries in file_usage
    // should be cleaned up.
    $this->addFieldMapping('field_user_picture:preserve_files')
         ->defaultValue(TRUE);

    // Make sure the picture does not get migrated to the native object.
    $this->addFieldMapping('picture', NULL, FALSE);

    // Comment Notify User Settings Migration.
    $this->addSimpleMappings(array(
      'node_notify',
      'comment_notify',
    ));
  }

  /**
   * Review a data row after fetch, returning FALSE to skip it.
   *
   * @param object $row
   *   Data Row to prepare.
   *
   * @return bool
   *   FALSE to skip this row.
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Role replacements.
    $role_replacements = array(
      'admin' => 'administrator',
      'editor 1' => 'editor',
    );

    // Prepare list of roles for this user.
    $row->role_names = array();
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('users_roles', 'ur')
             ->fields('r', array('name'))
             ->condition('uid', $row->uid);
    $query->leftJoin('role', 'r', '(ur.rid=r.rid)');
    foreach ($query->execute() as $role_row) {
      // Substitute role names with our defined replacements.
      // We can't use str_replace as we need to match entire strings.
      $role = $role_row->name;
      if (!empty($role_replacements[$role])) {
        $role = $role_replacements[$role];
      }
      if ($role) {
        $row->role_names[] = $role;
      }
    }

    return TRUE;
  }

  /**
   * Query.
   */
  protected function query() {
    $query = parent::query();
    $query->leftJoin('comment_notify_user_settings', 'cnu', 'cnu.uid = u.uid');
    $query->fields('cnu', array('node_notify', 'comment_notify'));
    return $query;
  }
}

/**
 * Migration for User Points.
 */
class OsMigrateUserPointsMigration extends DrupalMigration {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields,
      NULL, $this->sourceOptions);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'txn_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Source userpoint transaction ID',
          'alias' => 'u',
        ),
      ),
      MigrateDestinationUserpoints::getKeySchema()
    );

    $this->destination = new MigrateDestinationUserpoints();

    if (!$this->newOnly) {
      $this->highwaterField = array(
        'name' => 'changed',
        'alias' => 'u',
        'type' => 'int',
      );
    }

    $this->addFieldMapping('uid', 'uid')
         ->sourceMigration('OsUser');
    $this->addFieldMapping('tid', 'tid')
         ->defaultValue(0);
    $this->addSimpleMappings(array(
      'points',
      'moderate',
      'time_stamp',
      'operation',
      'expirydate',
      'description',
      'reference',
      'display',
      'entity_id',
      'entity_type',
    ));
  }

  /**
   * Query for the user points data.
   *
   * @return QueryConditionInterface
   *   Query to use for the source of migration.
   */
  protected function query() {
    // Do not attempt to migrate the anonymous user row.
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('userpoints_txn', 'u')
             ->fields('u')
             ->condition('u.uid', 0, '>')
             ->orderBy('u.changed');
    return $query;
  }
}

/**
 * Migration for User Badges.
 */
class OsMigrateUserBadgesMigration extends DrupalMigration {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields,
      NULL, $this->sourceOptions);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'uid' => array(
          'description' => 'User ID',
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
        'bid' => array(
          'description' => 'Badge ID',
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
        'type' => array(
          'description' => "Whether set as part of the role, or individually assigned ('user', 'role')",
          'type' => 'varchar',
          'length' => 20,
          'not null' => TRUE,
          'default' => '',
        ),
      ),
      MigrateDestinationTable::getKeySchema('user_badges_user')
    );

    $this->destination = new MigrateDestinationTable('user_badges_user');

    $this->addFieldMapping('uid', 'uid')
         ->sourceMigration('OsUser');
    $this->addSimpleMappings(array(
      'bid',
      'type',
      'userweight',
    ));
    $this->addUnmigratedDestinations(array('name'));
  }

  /**
   * Review a data row after fetch, returning FALSE to skip it.
   *
   * @param object $row
   *   Data Row to prepare.
   *
   * @return bool
   *   FALSE to skip this row.
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    static $badge_ids = array();
    if (empty($badge_ids[$row->name])) {
      // Get the badge for the $row->name.
      $badge = os_badges_get_badges($row->name, 'name');
      if (empty($badge[$row->name]->bid)) {
        // Log an error.
        $this->saveMessage(t('Cannot find badge %badge for UID %uid', array('%badge' => $row->name, '%uid' => $row->uid)), MigrationBase::MESSAGE_ERROR);
        return FALSE;
      }

      $badge_ids[$row->name] = $badge[$row->name]->bid;
    }

    $row->bid = $badge_ids[$row->name];
    return TRUE;
  }

  /**
   * Query for the user badges data.
   *
   * @return QueryConditionInterface
   *   Query to use for the source of migration.
   */
  protected function query() {
    // Do not attempt to migrate role based badges, which have a weight
    // higher than 192 in the source database.
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('user_badges_user', 'u')
             ->fields('u')
             ->fields('b', array('name'))
             ->condition('b.weight', 192, '<')
             ->condition('u.type', 'role', '<>');
    $query->leftJoin('user_badges_badges', 'b', '(u.bid = b.bid)');
    return $query;
  }
}
