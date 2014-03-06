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
}
