<?php
/**
 * @file
 * os_beans.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function os_beans_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'generic_block';
  $bean_type->label = 'Generic Block';
  $bean_type->options = '';
  $bean_type->description = 'Generic bean block for the opensource.com';
  $export['generic_block'] = $bean_type;

  return $export;
}
