<?php
/**
 * @file
 * Migration support for nodes.
 */

/**
 * Common mappings for Article-type content types.
 */
class OsContentArticleMigration extends DrupalNode6Migration {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);


// field mappings
    $this->addImageMappings();
    /*$this->addFieldMapping('field_lead_image', 'field_lead_image')
    ->arguments(array('preserve_files' => TRUE))
    ->sourceMigration('OSFile');
    */

    $this->addFieldMapping('field_lead_image', 'field_image')
    ->arguments(array('preserve_files' => TRUE))
    ->sourceMigration('OSFile');

    $this->addFieldMapping('field_default_license', 'field_default_license');
    $this->addFieldMapping('field_alternative_license', 'field_alternative_license');

    $this->addFieldMapping('field_attachments', 'field_attachments')
    ->arguments(array('preserve_files' => TRUE))
    ->sourceMigration('OSFile');

    $this->addFieldMapping('field_tags', '6')
    ->sourceMigration('OsVocabTags')
    ->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('field_article_type', 'field_article_type');
    $this->addFieldMapping('field_channel', 'field_channel');

    //poll
    $this->addFieldMapping('field_related_poll', 'nid')->sourceMigration('OsContentPoll');

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

  public function prepareRow($row){
    $source_id = $row->nid;

    $query = Database::getConnection('default', $this->sourceConnection)
    ->select('nodewords', 'n')
    ->fields('n', array('name', 'content'))
    ->condition('n.id', $source_id, '=');
    $results = $query->execute();

    foreach ($results as $metaData) {
      $row->meta_{$metaData->name} = $metaData->content;
    }

    // get the tid for article type
    $term = taxonomy_get_term_by_name('Article', 'article_type');
    $row->field_article_type = $term->tid;

    // get the tid for channel - based on the OG audience
    //select title from node n, og_ancestry oa where oa.nid = 5774 AND oa.group_nid = n.nid;
    $query = Database::getConnection('default', $this->sourceConnection)
    ->select('node', 'n')
    ->fields('n', array('title'))
    ->innerJoin('og_ancestry', 'oa', 'oa.group_nid = n.nid')
    ->condition('oa.nid', $source_id, '=');
    $results = $query->execute();

    foreach ($results as $metaData) {
      $field_channel_name = $metaData->title;
    }
    // get the tid
    $term2 = taxonomy_get_term_by_name($field_channel_name, 'channel');
    $row->field_channel = $term2->tid;
  }

}

/**
 * Mappings for Article -> Poll content type.
 */
class OsContentPollMigration extends OsContentArticleMigration {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);
    $this->addImageMappings();
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

    return TRUE;
  }

  /**
   * Query.
   */
  protected function query() {
    $query = parent::query();
    $query->leftJoin('content_field_poll', 'p', 'p.vid = n.vid');
    $query->condition('p.field_poll_question', "' '", '<>');

    return $query;
  }
}


/**
 * Common mappings for Resource content types.
 */
class OsContentResourceMigration extends DrupalNode6Migration {

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

  public function prepareRow($row){
    parent::prepareRow($row);

    $source_id = $row->nid;

    $query = Database::getConnection('default', $this->sourceConnection)
    ->select('nodewords', 'n')
    ->fields('n', array('name', 'content'))
    ->condition('n.id', $source_id, '=');
    $results = $query->execute();

    foreach ($results as $metaData) {
      $row->meta_{$metaData->name} = $metaData->content;
    }
  }

}

class OsContentPageMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('body:summary', 'teaser');
    $this->addFieldMapping('body:format')->defaultValue('panopoly_wysiwyg_text');
    $this->addFieldMapping('body:language');

    if ($this->moduleExists('path')) {
      $this->addFieldMapping('path', 'path')
      ->description('Handled in prepareRow');
    }

    $this->addFieldMapping('workflow','workflow');
    $this->addFieldMapping('workflow_stamp','workflow_stamp');

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

  public function prepare(&$row) {
  $row->path['pathauto'] = 0;
  }

  public function prepareRow($row){
    parent::prepareRow($row);

    $source_id = $row->nid;

    $query = Database::getConnection('default', $this->sourceConnection)
    ->select('nodewords', 'n')
    ->fields('n', array('name', 'content'))
    ->condition('n.id', $source_id, '=');
    $results = $query->execute();

    foreach ($results as $metaData) {
      $row->meta_{$metaData->name} = $metaData->content;
    }

    $query = Database::getConnection('default', $this->sourceConnection)
    ->select('workflow_node', 'n')
    ->fields('n', array('sid', 'workflow_stamp'))
    ->condition('n.nid', $source_id, '=');
    $results = $query->execute();

    foreach ($results as $result) {
      $sid = $result->sid;
      $row->workflow_stamp = $result->workflow_stamp;
    }

    $array_sids = array(
      1 => 1,
      6 => 2,
      11 => 3
      );

    $row->workflow = $array_sids[$sid];
  }
}
