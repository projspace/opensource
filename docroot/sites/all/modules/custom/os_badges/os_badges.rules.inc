<?php
/**
 * @file
 * Rules information for OpenSource Badges.
 */

/**
 * Implements hook_rules_event_info().
 */
function os_badges_rules_event_info() {
  $variables = array(
    'user' => array(
      'type' => 'user',
      'label' => t('user receiving the badge'),
    ),
    'badge_id' => array(
      'type' => 'integer',
      'label' => t('badge id'),
    ),
    'badge_weight' => array(
      'type' => 'integer',
      'label' => t('badge weight'),
    ),
    'badge_name' => array(
      'type' => 'text',
      'label' => t('badge name'),
    ),
  );
  $items = array(
    'user_badges_role_badge_given' => array(
      'group' => t('User'),
      'label' => t('User was awarded a role badge'),
      'variables' => $variables,
      'access callback' => 'user_badges_rules_integration_access',
    ),
  );
  return $items;
}
