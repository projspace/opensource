<?php
/**
 * @file
 * os_poll.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function os_poll_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-poll-field_channel'
  $field_instances['node-poll-field_channel'] = array(
    'bundle' => 'poll',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 0,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_channel',
    'label' => 'Channel',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Channel');

  return $field_instances;
}
