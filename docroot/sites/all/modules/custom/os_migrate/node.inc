<?php
/**
 * @file
 * Migration support for nodes.
 */

/**
 * Common mappings for Page content types.
 */
class OsContentPageMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('body:summary', 'teaser');
    $this->addFieldMapping('body:format')->defaultValue('panopoly_html_text');

    if ($this->moduleExists('path')) {
      $this->addFieldMapping('path', 'path')
      ->description('Handled in prepareRow');
    }

    //TBD - not working
    //$this->addFieldMapping('workflow','workflow');
    //$this->addFieldMapping('workflow_stamp','workflow_stamp');

  // metatags
    $this->addFieldMapping('metatag_title','title');
    $this->addFieldMapping('metatag_abstract','meta_abstract');
    $this->addFieldMapping('metatag_copyright','meta_copyright');
    $this->addFieldMapping('metatag_description','meta_description');
    $this->addFieldMapping('metatag_keywords','meta_keywords');
    $this->addFieldMapping('metatag_revisit-after','meta_revisit-after');
    $this->addFieldMapping('metatag_robots','meta_robots');
    $this->addFieldMapping('metatag_canonical','meta_canonical');
  }

  public function prepare($entity, $row) {

    $entity->path['pathauto'] = 0;
    if (isset($row->field_default_license[0])) {
      if ($row->field_default_license[0] == 'Use the default CC license.') {
        $entity->field_default_license[LANGUAGE_NONE][0]['value'] = 'CC-BY-SA 3.0';
      } elseif ($row->field_default_license[0] == 'Use the alternative license'
        && !empty($row->field_alternative_license[0])) {
        $entity->field_default_license[LANGUAGE_NONE][0]['value'] =
          check_markup($row->field_alternative_license, 7, FALSE);
      }
    }
  }

  public function complete(stdClass $entity, stdClass $row) {
    $node = node_load($entity->nid);

    // Check if this type has workflow association
    $type = $node->type;
    // Skip if there are no workflows.
    if ($workflow = workflow_get_workflow_type_map_by_type($node->type)) {

      $old_sid = 1;
      $data = array(
        'nid' => $node->nid,
        'sid' => $row->workflow,
        'uid' => 1,
        'stamp' => REQUEST_TIME,
      );

      workflow_update_workflow_node($data, $old_sid, $comment);

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
   * Review a data row after fetch, returning FALSE to skip it.
   *
   * @param object $row
   *   Data Row to prepare.
   *
   * @return bool
   *   FALSE to skip this row.
   */
  public function prepareRow($row){
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $source_id = $row->nid;

    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('nodewords', 'n')
      ->fields('n', array('name', 'content'))
      ->condition('n.id', $source_id, '=');
    $results = $query->execute();

    foreach ($results as $metaData) {
      $n = "meta_" . $metaData->name;
      $value = (unserialize($metaData->content));
      $row->{$n} = $value['value'];
    }

    $query = Database::getConnection('default', $this->sourceConnection)
    ->select('workflow_node', 'n')
    ->fields('n', array('sid', 'stamp'))
    ->condition('n.nid', $source_id, '=');
    $results = $query->execute();

    foreach ($results as $result) {
      $sid = $result->sid;
      $row->workflow_stamp = $result->stamp;
    }

    $array_sids = array(
      1 => 1,
      6 => 2,
      11 => 3
    );
    if (isset($sid)) {
      $row->workflow = $array_sids[$sid];
    }
    else {
      $row->workflow = 3;
      $row->workflow_stamp = time();
    }
    return TRUE;
  }
}

/**
 * Common mappings for Article-type content types.
 */
class OsContentArticleMigration extends OsContentPageMigration {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);

    // field mappings
    $this->addImageMappings();

    $this->addFieldMapping('field_lead_image', 'field_image')
      ->arguments(array('preserve_files' => TRUE))
      ->sourceMigration(array('OsFile', 'OsImageFieldFile'));

    $this->dependencies[] = 'OsFile';
    $this->dependencies[] = 'OsImageFieldFile';

    $this->addFieldMapping('field_attachments', 'field_attachments')
      ->arguments(array('preserve_files' => TRUE))
      ->sourceMigration('OSFile');

    $this->addFieldMapping('field_tags', '6')
      ->sourceMigration('OsVocabTags')
      ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('tmp_field_article_type', 'field_article_type');
    $this->addFieldMapping('tmp_field_channel', 'field_channel');

    //poll
    //$this->addFieldMapping('field_related_poll', 'nid')->sourceMigration('OsContentPoll');
  }

  /**
   * Setup mappings for image fields.
   */
  protected function addImageMappings() {

    $this->addFieldMapping('field_lead_image', 'image')
      ->arguments(array('preserve_files' => TRUE))
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

    $source_id = $row->nid;
    $term = taxonomy_get_term_by_name('Article', 'article_type');
    $term_type = array_keys($term);
    $row->field_article_type = $term_type[0];

    // get the tid for channel - based on the OG audience
    //select title from node n, og_ancestry oa where oa.nid = 5774 AND oa.group_nid = n.nid;
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('node', 'n');
    $query->join('og_ancestry', 'oa', 'oa.group_nid = n.nid');
    $query->fields('n', array('title'))
     ->condition('oa.nid', $source_id, '=');
    $results = $query->execute();

    foreach ($results as $metaData) {
      $field_channel_name = $metaData->title;
    }

    // get the tid
    $term2 = taxonomy_get_term_by_name($field_channel_name, 'channel');
    $term_type = array_keys($term2);
    $row->field_channel = $term_type[0];

    return TRUE;
  }

  public function prepare($node, $row) {

    parent::prepare($node,$row);

    if (isset($node->tmp_field_channel)){
      $node->field_channel[LANGUAGE_NONE][0]['tid'] = $node->tmp_field_channel;
    }
    if (isset($node->tmp_field_article_type)) {
      $node->field_article_type[LANGUAGE_NONE][0]['tid'] = $node->tmp_field_article_type;
    }
  }
}

/**
 * Mappings for Article -> Poll content type.
 */
class OsContentPollMigration extends OsContentPageMigration {

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

    // Vote field mappings
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

    // get the tid for channel - based on the OG audience
    //select title from node n, og_ancestry oa where oa.nid = 5774 AND oa.group_nid = n.nid;
    $query = Database::getConnection('default', $this->sourceConnection)
    ->select('node', 'n');
    $query->join('og_ancestry', 'oa', 'oa.group_nid = n.nid');
    $query->fields('n', array('title'))
    ->condition('oa.nid', $source_id, '=');
    $results = $query->execute();

    foreach ($results as $metaData) {
      $field_channel_name = $metaData->title;
    }
    // get the tid
    $term2 = taxonomy_get_term_by_name($field_channel_name, 'channel');
    $term_type = array_keys($term2);
    $row->field_channel = $term_type[0];

    return TRUE;
  }

  /**
   * Implements Migration::prepare().
   * Runs just before node is saved and after prepareRow.
   *
   * @param $node
   *   The destination entity.
   * @param $row
   *   The source row.
   */
  public function prepare($node, $row) {

    parent::prepare($node,$row);

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
          $choices[] = array('chtext' => $choice['choice'], 'chvotes' => $chvotes, 'weight' => $weight);
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
      $votes[] = array('chid' => $vote->delta, 'uid' => $vote->uid,
        'hostname' => $vote->hostname, 'timestamp' => '1335939007');
    }
    $row->votes = $votes;


    if (isset($node->tmp_field_channel)) {
      $node->field_channel[LANGUAGE_NONE][0]['tid'] = $node->tmp_field_channel;
    }
    if (isset($node->tmp_field_article_type)) {
      $node->field_article_type[LANGUAGE_NONE][0]['tid'] = $node->tmp_field_article_type;
    }
  }
}

/**
 * Common mappings for Resource content types.
 */
class OsContentResourceMigration extends OsContentPageMigration {

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
 * Common mappings for Group Page content types.
 */
class OsContentGroupPageMigration extends OsContentPageMigration {

  public function __construct(array $args) {
    parent::__construct($args);
  }
}
/**
 * Common mappings for Podcast content types.
 */
class OsContentPodcastMigration extends OsContentPageMigration {

  public function __construct(array $args) {
    parent::__construct($args);

    $this->addFieldMapping('field_lead_image', 'field_lead_image')
      ->arguments(array('preserve_files' => TRUE))
      ->sourceMigration('OSFile');

    $this->addFieldMapping('field_lead_image', 'field_image')
      ->arguments(array('preserve_files' => TRUE))
      ->sourceMigration('OSFile');

    $this->addFieldMapping('tmp_field_article_type', 'field_article_type');
    $this->addFieldMapping('tmp_field_channel', 'field_channel');
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $source_id = $row->nid;
    $term = taxonomy_get_term_by_name('Podcast', 'article_type');
    $term_type = array_keys($term);
    $row->field_article_type = $term_type[0];

    // get the tid for channel - based on the OG audience
    //select title from node n, og_ancestry oa where oa.nid = 5774 AND oa.group_nid = n.nid;
    $query = Database::getConnection('default', $this->sourceConnection)
    ->select('node', 'n');
    $query->join('og_ancestry', 'oa', 'oa.group_nid = n.nid');
    $query->fields('n', array('title'))
    ->condition('oa.nid', $source_id, '=');
    $results = $query->execute();

    foreach ($results as $metaData) {
      $field_channel_name = $metaData->title;
    }
    // get the tid
    $term2 = taxonomy_get_term_by_name($field_channel_name, 'channel');
    $term_type = array_keys($term2);
    $row->field_channel = $term_type[0];

    return TRUE;
  }

  public function prepare ($node, $row) {

    if (isset($node->tmp_field_channel)) {
      $node->field_channel[LANGUAGE_NONE][0]['tid'] = $node->tmp_field_channel;
    }

    if (isset($node->tmp_field_article_type)) {
      $node->field_article_type[LANGUAGE_NONE][0]['tid'] = $node->tmp_field_article_type;
    }

  }
}

/**
 * Common mappings for Video content types.
 */
class OsContentVideoMigration extends OsContentPageMigration {

  public function __construct(array $args) {
    parent::__construct($args);

    $this->addFieldMapping('field_lead_image', 'field_lead_image')
      ->arguments(array('preserve_files' => TRUE))
      ->sourceMigration('OSFile');

    $this->addFieldMapping('field_lead_image', 'field_image')
      ->arguments(array('preserve_files' => TRUE))
      ->sourceMigration('OSFile');

    $this->addFieldMapping('field_attachments', 'field_attachments')
      ->arguments(array('preserve_files' => TRUE))
      ->sourceMigration('OSFile');

    $this->addFieldMapping('tmp_field_article_type', 'field_article_type');
    $this->addFieldMapping('tmp_field_channel', 'field_channel');
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $source_id = $row->nid;
    $term = taxonomy_get_term_by_name('Video', 'article_type');
    $term_type = array_keys($term);
    $row->field_article_type = $term_type[0];

    // get the tid for channel - based on the OG audience
    //select title from node n, og_ancestry oa where oa.nid = 5774 AND oa.group_nid = n.nid;
    $query = Database::getConnection('default', $this->sourceConnection)
    ->select('node', 'n');
    $query->join('og_ancestry', 'oa', 'oa.group_nid = n.nid');
    $query->fields('n', array('title'))
    ->condition('oa.nid', $source_id, '=');
    $results = $query->execute();

    foreach ($results as $metaData) {
      $field_channel_name = $metaData->title;
    }
    // get the tid
    $term2 = taxonomy_get_term_by_name($field_channel_name, 'channel');
    $term_type = array_keys($term2);
    $row->field_channel = $term_type[0];

    return TRUE;
  }

  public function prepare ($node, $row) {
    parent::prepare($node,$row);
    if (isset($node->tmp_field_channel)) {

    }
    $node->field_channel[LANGUAGE_NONE][0]['tid'] = $node->tmp_field_channel;

    if (isset($node->tmp_field_article_type)) {
      $node->field_article_type[LANGUAGE_NONE][0]['tid'] = $node->tmp_field_article_type;
    }
  }
}

/**
 * Common mappings for Event content types.
 */
class OsContentEventMigration extends OsContentPageMigration {

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


