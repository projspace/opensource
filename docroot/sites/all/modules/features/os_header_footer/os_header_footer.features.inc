<?php
/**
 * @file
 * os_header_footer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_header_footer_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
