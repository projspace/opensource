<?php
/**
 * @file
 * os_common_components.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_common_components_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  if ($module == "pm_existing_pages" && $api == "pm_existing_pages") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function os_common_components_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
