<?php
/**
 * @file
 * Migration support for ratings and other miscellaneous items.
 */

/**
 * Migrate legal conditions.
 */
class OsMigrateLegalConditionsMigration extends DrupalMigration {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields,
      NULL, $this->sourceOptions);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'tc_id' => array(
          'type' => 'int',
          'unsigned' => FALSE,
          'not null' => TRUE,
          'description' => 'Source legal condition ID',
          'alias' => 'r',
        ),
      ),
      MigrateDestinationTable::getKeySchema('legal_conditions')
    );

    $this->destination = new MigrateDestinationTable('legal_conditions');

    $this->addSimpleMappings(array(
      'version',
      'revision',
      'language',
      'conditions',
      'date',
      'extras',
      'changes',
    ));
    $this->addUnmigratedSources(array('tc_id'), t('DNM'));
    $this->addUnmigratedDestinations(array('tc_id'), t('DNM'));
  }

  /**
   * Query for the user points data.
   *
   * @return QueryConditionInterface
   *   Query to use for the source of migration.
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('legal_conditions', 'l')
      ->fields('l');
    return $query;
  }
}

/**
 * Migrate legal accepted records.
 */
class OsMigrateLegalAcceptedMigration extends DrupalMigration {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields,
      NULL, $this->sourceOptions);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'legal_id' => array(
          'type' => 'int',
          'unsigned' => FALSE,
          'not null' => TRUE,
          'description' => 'Source legal accepted ID',
          'alias' => 'r',
        ),
      ),
      MigrateDestinationTable::getKeySchema('legal_accepted')
    );

    $this->destination = new MigrateDestinationTable('legal_accepted');

    $this->addFieldMapping('uid', 'uid')->sourceMigration('OsUser');
    $this->addSimpleMappings(array(
      'version',
      'revision',
      'language',
      'accepted',
    ));
    $this->addUnmigratedSources(array('legal_id'), t('DNM'));
    $this->addUnmigratedDestinations(array('legal_id'), t('DNM'));
  }

  /**
   * Query for the user points data.
   *
   * @return QueryConditionInterface
   *   Query to use for the source of migration.
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('legal_accepted', 'l')
      ->fields('l');
    return $query;
  }
}

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
 * Migration for ratings for nodes.
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
      'OsPollComments',
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

/**
 * Migrate Path redirect to Redirect module.
 */
class OsMigrateRedirectMigration extends DrupalMigration {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    $this->sourceFields += array(
      'source_options' => 'Placeholder field for source options (query)',
      'redirect_options' => 'Placeholder field for redirect options (query)',
    );

    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields,
      NULL, $this->sourceOptions);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'rid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Source redirect ID',
          'alias' => 'r',
        ),
      ),
      MigrateDestinationRedirect::getKeySchema()
    );

    $this->destination = new MigrateDestinationRedirect();

    $this->addFieldMapping('status_code', 'type');
    $this->addFieldMapping('access', 'last_used');
    $this->addFieldMapping('type')->defaultValue('redirect');
    $this->addFieldMapping('uid')->defaultValue(0);
    $this->addFieldMapping('source_options', 'source_options')->defaultValue(array());
    $this->addFieldMapping('redirect_options', 'redirect_options')->defaultValue(array());
    $this->addFieldMapping('count')->defaultValue(0);
    $this->addSimpleMappings(array(
      'source',
      'redirect',
      'language',
    ));
    $this->addUnmigratedSources(array('query', 'fragment'), t('DNM'));
    $this->addUnmigratedDestinations(array('hash'), t('DNM'));
  }

  /**
   * Review a data row after fetch, returning FALSE to skip it.
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    if ($row->query) {
      $url = $row->redirect . '?' . $row->query;
      $parsed = drupal_parse_url($url);
      $row->source_options = array(
        'query' => $parsed['query'],
      );
    }

    if (substr($row->redirect, 0, '5') == 'node/') {
      // Translate nid to the destination.
      $nid = substr($row->redirect, 5);
      $content_migrations = array(
        'post' => 'OsContentArticle',
        'podcast' => 'OsContentPodcast',
        'video' => 'OsContentVideo',
        'page' => 'OsContentPage',
        'group_page' => 'OsContentGroupPage',
        'resource' => 'OsContentResource',
        'event' => 'OsContentEvent',
      );

      // Find the node type and use the appropriate migration.
      $query = Database::getConnection('default', $this->sourceConnection)
        ->select('node', 'n')
        ->fields('n', array('type'))
        ->condition('n.nid', $nid);
      $node_type = $query->execute()->fetchField();

      // This will create a stub if the node is not already present.
      $nid = $this->handleSourceMigration($content_migrations[$node_type], $nid, NULL, $this);
      $row->redirect = 'node/' . $nid;
    }

    return TRUE;
  }

  /**
   * Query for the user points data.
   *
   * @return QueryConditionInterface
   *   Query to use for the source of migration.
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('path_redirect', 'r')
      ->fields('r');
    return $query;
  }
}

/**
 * Migrate selected menu links.
 */
class OsMigrateMenuLinksMigration extends DrupalMenuLinks6Migration {
  /**
   * Query only for the menus we are interested in.
   */
  protected function query() {
    $menus = array(
      'menu-about-menu',
      'menu-footer',
    );

    $query = parent::query();
    $query->condition('m.menu_name', $menus);
    return $query;
  }
}
