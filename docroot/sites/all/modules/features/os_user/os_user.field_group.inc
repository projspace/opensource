<?php
/**
 * @file
 * os_user.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function os_user_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_account_info|user|user|form';
  $field_group->group_name = 'group_account_info';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Account Information',
    'weight' => '0',
    'children' => array(
      0 => 'account',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Account Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-account-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_account_info|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_picture|user|user|form';
  $field_group->group_name = 'group_user_picture';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Picture',
    'weight' => '2',
    'children' => array(
      0 => 'field_user_picture',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Picture',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-user-picture field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_user_picture|user|user|form'] = $field_group;

  return $export;
}
