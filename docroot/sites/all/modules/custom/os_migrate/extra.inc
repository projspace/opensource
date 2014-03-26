<?php
/**
 * @file
 * Migration support for ratings and other miscellaneous items.
 */

/**
 * Handling specific to a Drupal 6 source for votingapi.
 */
abstract class OsMigrateVotingapiMigration extends DrupalMigration {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields,
      NULL, $this->sourceOptions);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'vote_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Source votingapi_vote ID',
          'alias' => 'v',
        ),
      ),
      MigrateDestinationVotingapi::getKeySchema()
    );

    $this->destination = new MigrateDestinationVotingapi();

    if (!$this->newOnly) {
      $this->highwaterField = array(
        'name' => 'timestamp',
        'alias' => 'v',
        'type' => 'int',
      );
    }

    $this->addFieldMapping('entity_type', 'content_type');
    $this->addSimpleMappings(array(
      'value',
      'value_type',
      'tag',
      'timestamp',
      'vote_source',
    ));
  }

  /**
   * Query for the user points data.
   *
   * @return QueryConditionInterface
   *   Query to use for the source of migration.
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('votingapi_vote', 'v')
      ->fields('v')
      ->orderBy('v.timestamp');
    return $query;
  }
}

/**
 * Handling specific to a Drupal 6 source for votingapi.
 */
class OsMigrateNodeRatingMigration extends OsMigrateVotingapiMigration {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    $content_migrations = array(
      'OsContentArticle',
      'OsContentPodcast',
      'OsContentVideo',
    );
    $this->addFieldMapping('entity_type', 'content_type', FALSE)
         ->defaultValue('node');
    $this->addFieldMapping('entity_id', 'content_id')
         ->sourceMigration($content_migrations);
    $this->addFieldMapping('uid', 'uid')
         ->sourceMigration('OsUser');
  }

  /**
   * Query for the user points data.
   *
   * @return QueryConditionInterface
   *   Query to use for the source of migration.
   */
  protected function query() {
    $query = parent::query();
    $query->condition('v.content_type', 'node');
    // Make sure that the content actually exists.
    $query->join('node', 'n', 'v.content_id = n.nid');
    return $query;
  }
}

/**
 * Migration for ratings for comments.
 */
class OsMigrateCommentRatingMigration extends OsMigrateVotingapiMigration {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    $content_migrations = array(
      'OsArticleComments',
      'OsPodcastComments',
      'OsVideoComments',
      'OsEventComments',
    );
    $this->addFieldMapping('entity_type', 'content_type', FALSE)
         ->defaultValue('comment');
    $this->addFieldMapping('entity_id', 'content_id')
         ->sourceMigration($content_migrations);
    $this->addFieldMapping('uid', 'uid')
         ->sourceMigration('OsUser');
  }

  /**
   * Query for the user points data.
   *
   * @return QueryConditionInterface
   *   Query to use for the source of migration.
   */
  protected function query() {
    $query = parent::query();
    $query->condition('v.content_type', 'comment');
    // Make sure that the content actually exists.
    $query->join('comments', 'c', 'v.content_id = c.cid');
    return $query;
  }
}
