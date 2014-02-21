<?php
/**
 * @file
 * os_channel_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_channel_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function os_channel_pages_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_page_manager_handlers_alter().
 */
function os_channel_pages_default_page_manager_handlers_alter(&$data) {
  if (isset($data['term_view_panelizer'])) {
    $data['term_view_panelizer']->weight = 0; /* WAS: -100 */
  }
}
