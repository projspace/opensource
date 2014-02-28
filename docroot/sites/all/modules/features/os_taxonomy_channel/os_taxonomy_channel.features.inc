<?php
/**
 * @file
 * os_taxonomy_channel.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_taxonomy_channel_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
