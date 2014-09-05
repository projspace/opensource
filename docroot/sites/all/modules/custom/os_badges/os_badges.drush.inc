<?php
/**
 * @file
 * Drush integration for OpenSource Badges
 */

/**
 * Implements hook_drush_command().
 */
function os_badges_drush_command() {
  $items = array();

  $items['award-role-badges'] = array(
    'description' => 'Determine and award role badges to specified users.',
    'arguments' => array(
      'users' => '',
    ),
    'aliases' => array('arb'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  return $items;
}

/**
 * Callback for drush command award-role-badges.
 */
function drush_os_badges_award_role_badges($users = NULL) {
  if (!$users) {
    $entities = entity_load('user');
    $users = array_keys($entities['user']);
  }
  else {
    $usernames = explode(',', $users);
    $users = array();
    foreach ($usernames as $name) {
      $users[] = user_load_by_name($name)->uid;
    }
  }

  foreach ($users as $uid) {
    os_badges_award_role_badge($uid);
    drush_log(dt('Processed role badges for user with id @uid', array('@uid' => $uid)));
  }
}
