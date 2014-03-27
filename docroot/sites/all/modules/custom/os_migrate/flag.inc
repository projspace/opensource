<?php
/**
 * @file
 * Migration support for spotlighted user and flag.
 */

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
