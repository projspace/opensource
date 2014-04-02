<?php
/**
 * @file
 * Migration support for nodes.
 */

/**
 * Common mappings for Page content types.
 */
abstract class OsMigrateContentBase extends DrupalNode6Migration {
  /**
   * Constructor.
   *
   * Set default and common field mappings necessary for all migrations.
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('body:format', NULL, FALSE)->defaultValue('panopoly_html_text');

    // Metatags mappings.
    $this->addFieldMapping('metatag_title', 'page_title');
    $this->addFieldMapping('metatag_abstract', 'meta_abstract');
    $this->addFieldMapping('metatag_copyright', 'meta_copyright');
    $this->addFieldMapping('metatag_description', 'meta_description');
    $this->addFieldMapping('metatag_keywords', 'meta_keywords');
    $this->addFieldMapping('metatag_revisit-after', 'meta_revisit-after');
    $this->addFieldMapping('metatag_robots', 'meta_robots');
    $this->addFieldMapping('metatag_canonical', 'meta_canonical');
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

    $source_id = $row->nid;

    // Retrieve all nodewords.
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('nodewords', 'n')
      ->fields('n', array('name', 'content'))
      ->condition('n.id', $source_id, '=');
    $results = $query->execute();

    foreach ($results as $metadata) {
      $n = "meta_" . $metadata->name;
      $value = (unserialize($metadata->content));
      $row->{$n} = $value['value'];
    }

    // Retrieve page title.
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('page_title', 't')
      ->fields('t', array('page_title'))
      ->condition('t.id', $source_id)
      ->condition('t.type', 'node');
    if ($page_title = $query->execute()->fetchField()) {
      $row->page_title = $page_title;
    }

    // Retrieve workflow settings for the node.
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('workflow_node', 'n')
      ->fields('n', array('sid', 'stamp'))
      ->condition('n.nid', $source_id, '=');
    $result = $query->execute()->fetchAssoc();
    if (!empty($result)) {
      $sid_map = array(1 => 1, 6 => 2, 11 => 3);
      $row->workflow = $sid_map[$result['sid']];
      $row->workflow_stamp = $result['stamp'];
    }
    else {
      $row->workflow = 3;
      $row->workflow_stamp = time();
    }

    return TRUE;
  }

  /**
   * Setup mappings for image fields.
   */
  protected function addFileMappings($args) {
    $types = array('article', 'poll', 'resource');
    if (in_array($args['destination_type'], $types)) {
      $this->addFieldMapping('field_lead_image', 'image')
        ->sourceMigration(array('OsFile', 'OsImageFieldFile'));
      $this->addFieldMapping('field_lead_image:file_class')->defaultValue('MigrateFileFid');

      $this->addFieldMapping('field_lead_image:alt', 'image_alt');
      $this->addFieldMapping('field_lead_image:title', 'image_title');
    }

    $types = array('article', 'page', 'poll', 'resource');
    if (in_array($args['destination_type'], $types)) {
      $this->addFieldMapping('field_attachments', 'files')
        ->sourceMigration('OsFile');
      $this->addFieldMapping('field_attachments:description', 'file_description');
      $this->addFieldMapping('field_attachments:preserve_files')->defaultValue(TRUE);
      $this->addFieldMapping('field_attachments:file_class')->defaultValue('MigrateFileFid');
    }

    $this->dependencies[] = 'OsFile';
    $this->dependencies[] = 'OsImageFieldFile';
  }

  /**
   * Setup mappings for channel.
   */
  protected function addChannelMappings() {
    $this->addFieldMapping('field_channel', 'field_channel');
    $this->addFieldMapping('field_channel:source_type')->defaultValue('tid');
  }

  /**
   * Process data row to retrieve the appropriate image to use.
   */
  protected function prepareRowFiles($row) {
    if (!empty($row->field_lead_image)) {
      $row->image = $row->field_lead_image;
      $row->image_alt = $row->{'field_lead_image:alt'};
      $row->image_title = $row->{'field_lead_image:title'};
    }
    elseif (!empty($row->field_image)) {
      $row->image = $row->field_image;
      $row->image_alt = $row->{'field_image:alt'};
      $row->image_title = '';
    }

    foreach (array('field_attachments', 'upload') as $field) {
      if (count($row->$field) == 1 && $row->$field[0] == NULL) {
        $row->$field = array();
        $row->{$field . ':description'} = array();
      }
    }

    $row->files = array_merge((array) $row->field_attachments, (array) $row->upload);
    $row->file_description = array_merge((array) $row->{'field_attachments:description'}, (array) $row->{'upload:description'});
    return TRUE;
  }

  /**
   * Process data row to set the channel tid.
   */
  protected function prepareRowChannel($row) {
    // Get the channel - based on the OG audience.
    // SELECT title FROM node n, og_ancestry oa where oa.nid = 5774
    // AND oa.group_nid = n.nid;
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('node', 'n')
      ->fields('n', array('title'))
      ->condition('oa.nid', $row->nid, '=');
    $query->join('og_ancestry', 'oa', 'oa.group_nid = n.nid');
    $field_channel_name = $query->execute()->fetchField();

    $row->field_channel = $this->getTid($field_channel_name, 'channel');
    return TRUE;
  }

  /**
   * Prepare the destination before save.
   */
  public function prepare($entity, stdClass $row) {
    $entity->path['pathauto'] = 0;
  }

  /**
   * Perform post-save operations.
   */
  public function complete(stdClass $entity, stdClass $row) {
    $node = node_load($entity->nid);

    // Skip if this type has workflow association.
    if (workflow_get_workflow_type_map_by_type($node->type)) {
      $old_sid = 1;
      $data = array(
        'nid' => $node->nid,
        'sid' => $row->workflow,
        'uid' => 1,
        'stamp' => REQUEST_TIME,
      );

      workflow_update_workflow_node($data, $old_sid);

      $data2 = array(
        'entity_type' => 'node',
        'nid' => $node->nid,
        'field_name' => '',
        'language' => 'und',
        'delta' => '',
        'old_sid' => $old_sid,
        'sid' => $row->workflow,
        'uid' => 1,
        'stamp' => REQUEST_TIME,
        'comment' => '',
      );
      drupal_write_record('workflow_node_history', $data2);
    }
  }

  /**
   * Get the TID for a term.
   */
  protected function getTid($term_name, $vocab_name = 'channel') {
    static $tid_cache = array();
    if (empty($tid_cache[$term_name])) {
      $term = taxonomy_get_term_by_name($term_name, $vocab_name);
      $term_ids = array_keys($term);
      $tid_cache[$term_name] = reset($term_ids);
    }

    return $tid_cache[$term_name];
  }
}

/**
 * Mappings for migration of Page content.
 */
class OsMigratePageMigration extends OsMigrateContentBase {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);
    $this->addFileMappings($args);

    $this->addFieldMapping('field_section', '7')->sourceMigration('OsVocabSections');
    $this->addFieldMapping('field_section:source_type')->defaultValue('tid');
  }

  /**
   * Review a data row after fetch, returning FALSE to skip it.
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    if ($this->prepareRowFiles($row) === FALSE) {
      return FALSE;
    }

    return TRUE;
  }
}

/**
 * Mappings for migration of Article-type content types.
 */
class OsMigrateArticleMigration extends OsMigrateContentBase {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);
    $this->addFileMappings($args);
    $this->addChannelMappings();

    $this->addFieldMapping('field_tags', '6')->sourceMigration('OsVocabTags');
    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');

    $this->addFieldMapping('field_article_type', 'field_article_type');
    $this->addFieldMapping('field_article_type:source_type')->defaultValue('tid');

    $this->addFieldMapping('field_default_license', 'field_default_license');

    $this->addFieldMapping('field_rating', 'rating')
      ->defaultValue('50')
      ->description('Not used, actual rating is migrated in complete handler.');
    $this->addFieldMapping('field_rating:target')->defaultValue('');

    $this->addFieldMapping('promote', 'homepage_listing_timestamp', FALSE)->defaultValue(0);

    // Mapping to set the related poll field to a poll migrated in
    // OsContentPoll migration.
    $this->addFieldMapping('field_related_poll', 'related_poll')->sourceMigration('OsContentPoll');
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

    if ($this->prepareRowFiles($row) === FALSE) {
      return FALSE;
    }

    if ($this->prepareRowChannel($row) === FALSE) {
      return FALSE;
    }

    // Handle license.
    if (!empty($row->field_default_license[0])) {
      if ($row->field_default_license[0] == 'Use the default CC license.') {
        $row->field_default_license[0] = 'CC-BY-SA 3.0';
      }
      elseif ($row->field_default_license[0] == 'Use the alternative license.'
        && !empty($row->field_alternative_license[0])) {
        $row->field_default_license = $row->field_alternative_license;
      }
    }

    // Handle mapping for poll field.
    if (!empty($row->field_poll[0]) && $row->field_poll[0] != "' '") {
      $row->related_poll = array($row->nid);
    }

    // Set the correct article type.
    $row->field_article_type = $this->getArticleTypeTid($this->sourceType);

    // Handle homepage_listing flag.
    $row->homepage_listing_timestamp = $row->homepage_listing_timestamp ? 1 : 0;

    return TRUE;
  }

  /**
   * Get the TID in destination for Article type for the source node type.
   */
  protected function getArticleTypeTid($type) {
    $type_map = array(
      'post' => 'Article',
      'video' => 'Video',
      'podcast' => 'Podcast',
    );
    return $this->getTid($type_map[$type], 'article_type');
  }

  /**
   * Query.
   */
  protected function query() {
    $query = parent::query();
    // Flag ID for homepage_listing in source is 6.
    $query->leftJoin('flag_content', 'flag', 'flag.content_id = n.nid AND flag.content_type = :flag_content_type AND flag.fid = :flag_fid', array(
        ':flag_content_type' => 'node',
        ':flag_fid' => 6,
      ));
    $query->addField('flag', 'timestamp', 'homepage_listing_timestamp');
    return $query;
  }
}

/**
 * Mappings for Article -> Poll content type.
 */
class OsMigratePollMigration extends OsMigrateContentBase {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);
    $this->addFileMappings($args);
    $this->addChannelMappings();

    $this->addFieldMapping('field_tags', '6')->sourceMigration('OsVocabTags');
    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');

    $this->addFieldMapping('poll_homepage', 'homepage_poll_timestamp')->defaultValue(0);

    // Poll field mappings.
    $this->addFieldMapping('active', 'field_poll:active');
    $this->addFieldMapping('runtime', 'field_poll:runtime');
    $this->addFieldMapping('choice', 'field_poll:choice');
    $this->addFieldMapping('votes', 'field_poll:votes');
  }

  /**
   * Query.
   */
  protected function query() {
    $query = parent::query();
    $query->innerJoin('content_field_poll', 'p', 'p.vid = n.vid');
    $query->isNotNull('p.field_poll_question');
    $query->condition('p.field_poll_question', "' '", '<>');

    // Flag ID for homepage_poll in source is 31.
    $query->leftJoin('flag_content', 'flag', 'flag.content_id = n.nid AND flag.content_type = :flag_content_type AND flag.fid = :flag_fid', array(
        ':flag_content_type' => 'node',
        ':flag_fid' => 31,
      ));
    $query->addField('flag', 'timestamp', 'homepage_poll_timestamp');

    return $query;
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

    if ($this->prepareRowFiles($row) === FALSE) {
      return FALSE;
    }

    if ($this->prepareRowChannel($row) === FALSE) {
      return FALSE;
    }

    // Retrieve the title from the poll, instead of the post.
    $row->title = $row->field_poll[0];

    $choices = array();
    $weight = 0;
    foreach ($row->{'field_poll:choice'} as $choice_ser) {
      $choice_unser = unserialize($choice_ser);
      foreach ($choice_unser as $choice) {
        if (!empty($choice['choice'])) {
          $choices[] = array(
            'chtext' => $choice['choice'],
            // We'll calculate the number of votes later.
            'chvotes' => 0,
            'weight' => $weight,
          );
          $weight++;
        }
      }
    }

    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('pollfield_votes', 'pv');
    $query->fields('pv', array('hostname', 'uid', 'delta', 'cookie'))
      ->condition('pv.nid', $row->nid, '=');
    $results = $query->execute();

    $votes = array();
    foreach ($results as $vote) {
      if ($vote->delta == -1) {
        continue;
      }

      if ($vote->cookie) {
        $cookie = unserialize($vote->cookie);
        $timestamp = substr($cookie['cookie_value'], 2);
        $hostname = $vote->hostname . '#' . uniqid() . $timestamp;
      }
      else {
        // We don't have any information for votes by registered users
        // or in same cases, even for anonymous users.
        // Assume sensible or random defaults.
        $hostname = '#os-migrate-random-' . uniqid();
        $timestamp = $row->changed;
      }

      $choices[$vote->delta]['chvotes']++;
      $votes[] = array(
        'chtext' => $choices[$vote->delta],
        'uid' => $vote->uid,
        'hostname' => $hostname,
        'timestamp' => (int) $timestamp,
      );
    }
    $row->{'field_poll:choice'} = $row->choice = $choices;
    $row->{'field_poll:votes'} = $row->votes = $votes;

    // Simplify the active and runtime flag.
    $row->{'field_poll:active'} = $row->{'field_poll:active'}[0];
    $row->{'field_poll:runtime'} = $row->{'field_poll:runtime'}[0];

    return TRUE;
  }

  /**
   * Runs after the node is saved.
   */
  public function complete($entity, stdClass $row) {
    parent::complete($entity, $row);

    // Poll module sets active to 1 if the migration is running under
    // no user. Make sure we set the active flag correctly.
    db_update('poll')
      ->fields(array('active' => $row->{'field_poll:active'}))
      ->condition('nid', $entity->nid)
      ->execute();
  }
}

/**
 * Mappings for migration of Group Page content.
 */
class OsMigrateGroupPageMigration extends OsMigrateContentBase {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);
    $this->addChannelMappings();
  }

  /**
   * Review a data row after fetch, returning FALSE to skip it.
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    if ($this->prepareRowChannel($row) === FALSE) {
      return FALSE;
    }
  }
}

/**
 * Mappings for migration of Resource content.
 */
class OsMigrateResourceMigration extends OsMigrateContentBase {
  /**
   * Constructor.
   */
  public function __construct(array $args) {
    parent::__construct($args);
    $this->addFileMappings($args);
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

    if ($this->prepareRowFiles($row) === FALSE) {
      return FALSE;
    }

    return TRUE;
  }
}

/**
 * Mappings for migration of Event content.
 */
class OsMigrateEventMigration extends OsMigrateContentBase {
  /**
   * Map event related fields.
   */
  public function __construct(array $args) {
    parent::__construct($args);

    $this->addFieldMapping('field_event_submitter_name', 'field_event_submitter_name');
    $this->addFieldMapping('field_event_submitter_email', 'field_event_submitter_email');
    $this->addFieldMapping('field_event_start_date', 'field_event_start_date');
    $this->addFieldMapping('field_event_location', 'field_event_location');
    $this->addFieldMapping('field_event_website', 'field_event_website');
    $this->addFieldMapping('field_event_summary', 'field_event_summary');
  }
}
