<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _opensource_events_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'module' => 'features',
      'description' => t('To create Conferences & Events'),
      'has_title' => '1',
      'title_label' => t('Event Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
