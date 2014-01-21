<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _contributor_spotlight_content_default_fields() {
  $fields = array();

  // Exported field: field_user
  $fields[] = array(
    'field_name' => 'field_user',
    'type_name' => 'spotlighted_user',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'userreference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'userreference',
    'active' => '1',
    'referenceable_roles' => array(
      '2' => 2,
      '16' => 0,
      '11' => 0,
      '31' => 0,
      '21' => 0,
      '26' => 0,
      '41' => 0,
      '36' => 0,
      '42' => 0,
    ),
    'referenceable_status' => '1',
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'reverse_link' => 0,
      'default_value' => array(
        '0' => array(
          'uid' => NULL,
          '_error_element' => 'default_value_widget][field_user][0][uid][uid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'User',
      'weight' => '-2',
      'description' => '',
      'type' => 'userreference_autocomplete',
      'module' => 'userreference',
    ),
  );

  // Translatables
  array(
    t('User'),
  );

  return $fields;
}
