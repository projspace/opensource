<?php
/**
 * @file
 * os_content_group_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_content_group_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function os_content_group_page_node_info() {
  $items = array(
    'group_page' => array(
      'name' => t('Group Page'),
      'base' => 'node_content',
      'description' => t('A <em>Group Page</em> can be used for about pages for channels/groups.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
