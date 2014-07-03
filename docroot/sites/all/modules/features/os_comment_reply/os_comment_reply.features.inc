<?php
/**
 * @file
 * os_comment_reply.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_comment_reply_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
