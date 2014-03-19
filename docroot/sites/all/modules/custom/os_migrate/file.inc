<?php
/**
 * @file
 * Implement support for file migrations.
 */

class OsMigrateFieldImceImageMigration extends DrupalPicture6Migration {
  /**
   * Constructor.
   */
  public function __construct(array $args) {
    parent::__construct($args);

    $this->highwaterField = array();

    // Add more legacy paths to filter out.
    $this->legacyPath = array(
      'http://opensource.com/',
      'http://opensource.prod.acquia-sites.com/',
      'http://174.129.231.240/',
      $this->legacyPath,
    );
  }

  /**
   * We override the query to get paths from the content_field_image table.
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('content_field_image', 'f');
    // Return the field name the file migration expects.
    $query->addField('f', 'field_image_imceimage_path', 'filepath');
    $query->condition('f.field_image_imceimage_path', '', '<>');
    return $query;
  }

  /**
   * Field mapping callback: Replace %20 with a space.
   */
  protected function fixUri($uri) {
    $result = parent::fixUri($uri);
    $result = str_replace('%20', ' ', $result);
    return $result;
  }
}
