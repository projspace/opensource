<?php
/**
 * @file
 * os_radioactivity.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_radioactivity_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "radioactivity" && $api == "radioactivity_decay_profile") {
    return array("version" => "1");
  }
}
