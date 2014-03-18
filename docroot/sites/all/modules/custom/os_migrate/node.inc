<?php
/**
 * @file
 * Migration support for nodes.
 */

/**
 * Common mappings for Article-type content types.
 */
abstract class OsMigrateCommonArticleMigration extends DrupalNode6Migration {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);
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
}

/**
 * Mappings for Article -> Poll content type.
 */
class OsMigratePollMigration extends OsMigrateCommonArticleMigration {
  /**
   * Constructor.
   */
  public function __construct($args) {
    parent::__construct($args);
    $this->addImageMappings();
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
