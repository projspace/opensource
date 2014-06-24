<?php
/**
 * @file
 * os_header_footer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_header_footer_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
