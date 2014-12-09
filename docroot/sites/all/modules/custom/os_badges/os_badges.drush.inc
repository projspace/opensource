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

  $items['assign-role-badges'] = array(
    'description' => 'Determine and assign role badges to specified users.',
    'arguments' => array(
      'users' => '',
    ),
    'aliases' => array('rolebadges'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  return $items;
}

/**
 * Callback for drush command assign-role-badges.
 */
function drush_os_badges_assign_role_badges($usernames = NULL) {
  // Retrieve all users except anonymous. Order by uid to keep the output
  // sequential.
  $query = db_select('users', 'u')
    ->fields('u', array('uid'))
    ->condition('uid', '0', '!=')
    ->orderBy('uid');

  // Load only specific users if specified.
  if ($usernames) {
    $query->condition('name', explode(',', $usernames));
  }

  $users = $query->execute()->fetchCol();
  drush_log(dt('Found @count users.', array('@count' => count($users))), 'success');

  foreach ($users as $uid) {
    os_badges_award_role_badge($uid);
    drush_log(dt('Processed role badges for user with id @uid', array('@uid' => $uid)), 'success');
  }
}
