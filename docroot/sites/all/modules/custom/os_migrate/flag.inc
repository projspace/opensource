<?php
/**
 * @file
 * Migration support for spotlighted user and flag.
 */

/**
 * Migrate support for Flags.
 */
class OsMigrateFlagMigration extends DrupalMigration {
  /**
   * Source Flag ID.
   */
  protected $sourceFlagId;

  /**
   * Destination Flag ID.
   */
  protected $destinationFlagId;

  /**
   * Constructor.
   */
  public function __construct($arguments) {
    $source_flag_name = $arguments['source_flag_name'];
    $destination_flag_name = $arguments['destination_flag_name'];
    if (!empty($arguments['user_migration'])) {
      $user_migration = $arguments['user_migration'];
      $this->dependencies[] = $user_migration;
    }
    if (!empty($arguments['content_migration'])) {
      $content_migration = $arguments['content_migration'];
      $this->dependencies[] = $content_migration;
    }
    parent::__construct($arguments);

    $this->sourceFlagId = Database::getConnection('default', $this->sourceConnection)
      ->select('flags', 'f')
      ->fields('f', array('fid'))
      ->condition('name', $source_flag_name)
      ->execute()
      ->fetchField();
    if (!$this->sourceFlagId) {
      throw new MigrateException('Flag @flag was not found in source.', array('@flag' => $source_flag_name));
    }

    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields,
      NULL, $this->sourceOptions);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'fcid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Flag Content ID',
          'alias' => 'f',
        ),
      ),
      MigrateDestinationFlagging::getKeySchema()
    );

    $this->destination = new MigrateDestinationFlagging($destination_flag_name);

    if (!$this->newOnly) {
      $this->highwaterField = array(
        'name' => 'timestamp',
        'alias' => 'f',
        'type' => 'int',
      );
    }

    $this->addFieldMapping('uid', 'uid')
         ->sourceMigration($user_migration);
    $this->addFieldMapping('entity_id', 'content_id')
         ->sourceMigration($content_migration);
    $this->addFieldMapping('entity_type', 'content_type');
    $this->addFieldMapping('timestamp', 'timestamp');
    $this->addUnmigratedSources(array('sid', 'fid'), t('DNM'));
    $this->addUnmigratedDestinations(array('fid'), t('DNM'));
  }

  /**
   * Query for the user points data.
   *
   * @return QueryConditionInterface
   *   Query to use for the source of migration.
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('flag_content', 'f')
             ->fields('f')
             ->condition('f.fid', $this->sourceFlagId)
             ->orderBy('f.timestamp');
    return $query;
  }
}

/**
 * Migrate Spotlighted User content type to flag.
 */
class OsMigrateSpotlightedUserMigration extends DrupalNode6Migration {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    // We need a different map and destination.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Source node ID',
          'alias' => 'n',
        ),
      ),
      MigrateDestinationFlagging::getKeySchema()
    );

    $flag = flag_get_flag('spotlight');
    $this->destination = new MigrateDestinationFlagging('spotlight');

    $this->addFieldMapping('fid')->defaultValue($flag->fid);
    $this->addFieldMapping('entity_type')->defaultValue('user');
    $this->addFieldMapping('entity_id', 'field_user')->sourceMigration('OsUser');
    $this->addFieldMapping('timestamp', 'changed', FALSE);

    $this->removeFieldMapping('changed');
    $this->removeFieldMapping('comment');
    $this->removeFieldMapping('created');
    $this->removeFieldMapping('daycount');
    $this->removeFieldMapping('is_new');
    $this->removeFieldMapping('language');
    $this->removeFieldMapping('log');
    $this->removeFieldMapping('path');
    $this->removeFieldMapping('pathauto');
    $this->removeFieldMapping('promote');
    $this->removeFieldMapping('revision');
    $this->removeFieldMapping('revision_uid');
    $this->removeFieldMapping('status');
    $this->removeFieldMapping('sticky');
    $this->removeFieldMapping('title');
    $this->removeFieldMapping('tnid');
    $this->removeFieldMapping('totalcount');
    $this->removeFieldMapping('translate');
  }

  /**
   * Perform post-save operations.
   */
  public function complete(stdClass $flag, stdClass $row) {
    // Add community description to the user.
    $target_user = user_load($flag->entity_id);
    $target_user->field_community_description[LANGUAGE_NONE][0]['value'] = $row->body;
    $target_user->field_community_description[LANGUAGE_NONE][0]['format'] = 'panopoly_wysiwyg_text';
    user_save($target_user);
  }
}
