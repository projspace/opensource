<?php
/**
 * @file
 * os_poll.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_poll_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function os_poll_flag_default_flags() {
  $flags = array();
  // Exported flag: "Poll on Homepage".
  $flags['poll_homepage'] = array(
    'entity_type' => 'node',
    'title' => 'Poll on Homepage',
    'global' => 1,
    'types' => array(
      0 => 'poll',
    ),
    'flag_short' => 'Promote poll on homepage',
    'flag_long' => 'The latest promoted poll will be shown on homepage in the sidebar',
    'flag_message' => '',
    'unflag_short' => 'Remove poll from homepage',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'featured' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'module' => 'os_poll',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
