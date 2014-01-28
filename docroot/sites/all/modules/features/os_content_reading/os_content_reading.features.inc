<?php
/**
 * @file
 * os_content_reading.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_content_reading_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function os_content_reading_node_info() {
  $items = array(
    'reading' => array(
      'name' => t('Reading'),
      'base' => 'node_content',
      'description' => t('<em>Reading</em> is what we are reading now. It contains a description (e.g., the name of the site) and a link and title to the article.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
