<?php
/**
 * @file
 * os_article.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function os_article_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'file-image-field_file_image_caption'
  $field_instances['file-image-field_file_image_caption'] = array(
    'bundle' => 'image',
    'default_value' => array(
      0 => array(
        'value' => '<p>opensource.com</p>',
        'format' => 'panopoly_wysiwyg_text',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'link' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'preview' => array(
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
    'entity_type' => 'file',
    'field_name' => 'field_file_image_caption',
    'label' => 'Caption',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
      'wysiwyg_override' => 1,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 2,
      ),
      'type' => 'text_textarea',
      'weight' => -2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Caption');

  return $field_instances;
}
