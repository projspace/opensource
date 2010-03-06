<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _feedtweaks_node_info() {
  $items = array(
    'reading' => array(
      'name' => t('Reading'),
      'module' => 'features',
      'description' => t('<em>Reading</em> is what we are reading now. It contains a description (e.g., the name of the site) and a link and title to the article.'),
      'has_title' => '1',
      'title_label' => t('Description'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
