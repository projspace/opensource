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
      MigrateDestinationFlagSimple::getKeySchema()
    );

    $this->destination = new MigrateDestinationFlagSimple();

    $this->addFieldMapping('entity_type', 'content_type');
    $this->addSimpleMappings(array(
      'value',
      'value_type',
      'tag',
      'timestamp',
      'vote_source',
    ));
  }
}
