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
    // TODO: Fix the metatag_title mapping.
    $this->addFieldMapping('metatag_title', 'title');
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

    // Retrieve workflow settings for the node.
    // TODO: This block can be probably removed.
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('workflow_node', 'n')
      ->fields('n', array('sid', 'stamp'))
      ->condition('n.nid', $source_id, '=');
    $results = $query->execute();

    foreach ($results as $result) {
      $sid = $result->sid;
      $row->workflow_stamp = $result->stamp;
    }

    $sid_map = array(
      1 => 1,
      6 => 2,
      11 => 3,
    );
    if (!empty($sid)) {
      $row->workflow = $sid_map[$sid];
    }
    else {
      $row->workflow = 3;
      $row->workflow_stamp = time();
    }
    // TODO: End block which can probably be removed.

    return TRUE;
  }

  /**
   * Setup mappings for image fields.
   */
  protected function addImageMappings() {
    $this->addFieldMapping('field_lead_image', 'image')
      ->sourceMigration(array('OsFile', 'OsImageFieldFile'));

    $this->addFieldMapping('field_lead_image:alt', 'image_alt');
    $this->addFieldMapping('field_lead_image:title', 'image_title');
    $this->dependencies[] = 'OsFile';
    $this->dependencies[] = 'OsImageFieldFile';
  }

  /**
   * Process data row to retrieve the appropriate image to use.
   */
  protected function prepareRowFieldImages($row) {
    if (!empty($row->field_lead_image)) {
      $row->image = $row->field_lead_image;
      $row->image_alt = $row->{'field_lead_image:alt'};
      $row->image_title = $row->{'field_lead_image:title'};
    }
    else {
      $row->image = $row->field_image;
      $row->image_alt = $row->{'field_image:alt'};
      $row->image_title = '';
    }
    return TRUE;
  }

  /**
   * Prepare the destination before save.
   */
  public function prepare($entity, stdClass $row) {
    $entity->path['pathauto'] = 0;
    // TODO: Move this block to prepareRow, where it can be handled better.
    if (!empty($row->field_default_license[0])) {
      if ($row->field_default_license[0] == 'Use the default CC license.') {
        $entity->field_default_license[LANGUAGE_NONE][0]['value'] = 'CC-BY-SA 3.0';
      }
      elseif ($row->field_default_license[0] == 'Use the alternative license.'
        && !empty($row->field_alternative_license[0])) {
        $entity->field_default_license[LANGUAGE_NONE][0]['value'] = $row->field_alternative_license;
      }
    }
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
}

/**
 * Common mappings for Article-type content types.
 */
class OsMigrateArticleMigration extends OsMigrateContentBase {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    $this->addImageMappings();

    $this->addFieldMapping('field_attachments', 'field_attachments')
      ->arguments(array('preserve_files' => TRUE))
      ->sourceMigration('OSFile');

    $this->addFieldMapping('field_tags', '6')
      ->sourceMigration('OsVocabTags')
      ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('tmp_field_article_type', 'field_article_type');
    $this->addFieldMapping('tmp_field_channel', 'field_channel');

    // Mapping to set the related poll field to a poll migrated in
    // OsContentPoll migration.
    // $this->addFieldMapping('field_related_poll', 'nid')->sourceMigration('OsContentPoll');
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

    if ($this->prepareRowFieldImages($row) === FALSE) {
      return FALSE;
    }

    $row->field_article_type = $this->getArticleTypeTid($row->type);

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
   * Prepare the node before save.
   */
  public function prepare($node, stdClass $row) {
    parent::prepare($node, $row);

    // TODO: This should be done in prepareRow and via field mappings.
    if (isset($node->tmp_field_channel)) {
      $node->field_channel[LANGUAGE_NONE][0]['tid'] = $node->tmp_field_channel;
    }
    if (isset($node->tmp_field_article_type)) {
      $node->field_article_type[LANGUAGE_NONE][0]['tid'] = $node->tmp_field_article_type;
    }
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

    $this->addFieldMapping('field_attachments', 'field_attachments')
    ->arguments(array('preserve_files' => TRUE))
    ->sourceMigration('OSFile');

    $this->addFieldMapping('field_tags', '6')
    ->sourceMigration('OsVocabTags')
    ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('tmp_field_channel', 'tmp_field_channel');

    // Vote field mappings.
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

    $source_id = $row->nid;
    $term = taxonomy_get_term_by_name('Video', 'article_type');
    $term_type = array_keys($term);
    $row->field_article_type = $term_type[0];

    // TODO: Refactor the following in a base class common to all og nodes.
    // Get the tid for channel - based on the OG audience
    // Select title from node n, og_ancestry oa where oa.nid = 5774
    // AND oa.group_nid = n.nid;
    $query = Database::getConnection('default', $this->sourceConnection)
    ->select('node', 'n');
    $query->join('og_ancestry', 'oa', 'oa.group_nid = n.nid');
    $query->fields('n', array('title'))
    ->condition('oa.nid', $source_id, '=');
    $results = $query->execute();

    foreach ($results as $metadata) {
      $field_channel_name = $metadata->title;
    }
    $term2 = taxonomy_get_term_by_name($field_channel_name, 'channel');
    $term_type = array_keys($term2);
    $row->field_channel = $term_type[0];

    return TRUE;
  }

  /**
   * Runs just before node is saved and after prepareRow.
   */
  public function prepare($node, stdClass $row) {

    parent::prepare($node, $row);

    $node->title = $row->field_poll[0];

    $choices = array();
    $weight = 0;
    foreach ($row->{'field_poll:choice'} as $choice_ser) {
      $choice_unser = unserialize($choice_ser);
      foreach ($choice_unser as $choice) {
        if (!empty($choice['choice'])) {
          $chvotes = 0;
          if (!empty($choice['votes']) && is_int($choice['votes'])) {
            $chvotes = $choice['votes'];
          }
          $choices[] = array(
            'chtext' => $choice['choice'],
            'chvotes' => $chvotes,
            'weight' => $weight,
          );
          $weight++;
        }
      }
    }
    $node->choice = $choices;
    $row->choice = $choices;

    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('pollfield_votes', 'pv');
    $query->fields('pv', array('hostname', 'uid', 'delta', 'cookie'))
      ->condition('pv.nid', $row->nid, '=');
    $results = $query->execute();

    $votes = array();
    foreach ($results as $vote) {
      $votes[] = array(
        'chtext' => $choices[$vote->delta],
        'uid' => $vote->uid,
        'hostname' => "{$vote->hostname}",
        'timestamp' => time(),
      );
    }
    $row->votes = $votes;
    $node->votes = $votes;

    if (isset($node->tmp_field_channel)) {
      $node->field_channel[LANGUAGE_NONE][0]['tid'] = $node->tmp_field_channel;
    }
    if (isset($node->tmp_field_article_type)) {
      $node->field_article_type[LANGUAGE_NONE][0]['tid'] = $node->tmp_field_article_type;
    }
  }
}

/**
 * Mappings for migration of Group Page content.
 */
class OsMigrateGroupPageMigration extends OsMigrateContentBase {
}

/**
 * Common mappings for Resource content types.
 */
class OsMigrateResourceMigration extends OsMigrateContentBase {

  /**
   * Constructor.
   */
  public function __construct(array $args) {
    parent::__construct($args);

    $this->addFieldMapping('field_lead_image', 'field_lead_image')
      ->arguments(array('preserve_files' => TRUE))
      ->sourceMigration('OSFile');

    $this->addFieldMapping('field_attachments', 'field_attachments')
      ->arguments(array('preserve_files' => TRUE))
      ->sourceMigration('OSFile');
  }
}

/**
 * Common mappings for Event content types.
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
