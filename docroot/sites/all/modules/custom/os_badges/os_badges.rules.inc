<?php

/**
 * Implements hook_rules_event_info().
 */
function os_badges_rules_event_info() {
  $variables = array(
    'user' => array(
      'type' => 'user',
      'label' => t('User before receiving badge'),
    ),
    'badge_id' => array(
      'type' => 'text',
      'label' => t("The given Badge's ID"),
    ),
    'badge_weight' => array(
      'type' => 'text',
      'label' => t('Badge Weight'),
    ),
    'badge_name' => array(
      'type' => 'text',
      'label' => t('Badge Name'),
    )
  );
  $items = array(
    'user_badges_badge_given_via_role' => array(
      'group' => t('User'),
      'label' => t('User was given a badge via role'),
      'variables' => $variables,
      'access callback' => 'user_badges_rules_integration_access'
    ),
  );
  return $items;
}
