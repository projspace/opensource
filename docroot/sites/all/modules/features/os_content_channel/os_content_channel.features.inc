<?php
/**
 * @file
 * os_content_channel.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_content_channel_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function os_content_channel_node_info() {
  $items = array(
    'channel' => array(
      'name' => t('Channel'),
      'base' => 'node_content',
      'description' => t('A <em>Channel</em> is a section of the site such as Business, Education, etc.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
