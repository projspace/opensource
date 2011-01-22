<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _contributor_spotlight_node_info() {
  $items = array(
    'spotlighted_user' => array(
      'name' => t('Spotlighted User'),
      'module' => 'features',
      'description' => t('Allows for the spotlighting of a user/contributor.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
