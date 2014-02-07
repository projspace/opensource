<?php
/**
 * @file
 * os_beans.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function os_beans_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-generic_block-field_body'
  $field_instances['bean-generic_block-field_body'] = array(
    'bundle' => 'generic_block',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Body text for the block body.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_body',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 11,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Body text for the block body.');

  return $field_instances;
}
