<?php
/**
 * @file
 * os_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function os_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'article_type' => array(
      'name' => 'Article Type',
      'machine_name' => 'article_type',
      'description' => '<em>Article Type</em> specifies the general type of article.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'sections' => array(
      'name' => 'Sections',
      'machine_name' => 'sections',
      'description' => 'A way to group our participation pages together.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => 'Use tags to group articles on similar topics into categories.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
