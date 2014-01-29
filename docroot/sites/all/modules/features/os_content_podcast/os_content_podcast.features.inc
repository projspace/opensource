<?php
/**
 * @file
 * os_content_podcast.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_content_podcast_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function os_content_podcast_node_info() {
  $items = array(
    'podcast' => array(
      'name' => t('Podcast'),
      'base' => 'node_content',
      'description' => t('A podcast, similar in form to an article, is ideal for creating content that informs or engages website visitors via an audio file. This content type will allow RedHat to group all the podcasts together as a single content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
