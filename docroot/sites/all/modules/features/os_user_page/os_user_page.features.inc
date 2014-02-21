<?php
/**
 * @file
 * os_user_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_user_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "pm_existing_pages" && $api == "pm_existing_pages") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function os_user_page_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_page_manager_handlers_alter().
 */
function os_user_page_default_page_manager_handlers_alter(&$data) {
  if (isset($data['user_view_panelizer'])) {
    $data['user_view_panelizer']->weight = 0; /* WAS: -100 */
  }
}
