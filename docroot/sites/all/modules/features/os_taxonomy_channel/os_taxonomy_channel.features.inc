<?php
/**
 * @file
 * os_taxonomy_channel.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_taxonomy_channel_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
