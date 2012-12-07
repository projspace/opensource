<?php
/**
 * @file: drush functionality for the OpenSource.com Points module
 */

/**
 * Implementation of hook_drush_help().
 */
function opensource_points_drush_help($section) {
  switch ($section) {
    case 'drush:osp-audit-badges':
      return dt('Audit user badges and roles.');
  }
}

/**
 * Implementation of hook_drush_command().
 */
function opensource_points_drush_command() {
  static $commands = FALSE;

  $items['osp-audit-badges'] = array(
    'description' => 'Audit user badges and roles.',
    'options' => array(
        'show-failures'   => 'Show info about each failure',
        'show-debug'      => 'Lots of debug output',
        'quiet'           => 'Suppress all output',
        'repair'          => 'Repair any problems which are found',
        'no-logging'      => 'Do not log to watchdog',
      ),
    'arguments' => array(
        'limit'   => 'Only process the first X items',
      ),
    'aliases' => array('osp-ab'),
  );
  return $items;
}

/**
 * command to audit userpoints, badges and roles
 * @see Acquia Support ticket 15066-34469
 */ 
function drush_opensource_points_osp_audit_badges($limit = NULL) {
  
  // prepare some info for the audit
  $earned_roles = _osp_ab_earned_roles();
  $userpoints_goals = _osp_ab_userpoints_goals();
  $all_badges = _osp_ab_all_badges();
  
  // stats collection
  $failures = array();
  $stats = array(
    'highest_badge_failures'  => 0,
    'earned_roles_failures'   => 0,
    'users_with_failures'     => 0,
    'total_users_audited'     => 0,
    'problem_roles'           => array(),
    'problem_badges'          => array(),
  );
  
  $option_show_debug        = drush_get_option('show-debug', FALSE);
  $option_show_failures     = drush_get_option('show-failures', FALSE);
  $option_quiet             = drush_get_option('quiet', FALSE);
  $option_repair            = drush_get_option('repair', FALSE);
  $option_no_logging        = drush_get_option('no-logging', FALSE);
  
  if (!empty($limit) && is_numeric($limit)) {
    $limit_clause = ' LIMIT %d';
  }
  else {
    $limit_clause = '';
  }
  
  // for each user
  //  compare userpoints, roles and badges
  $query = 'SELECT uid FROM {users} ORDER BY uid' . $limit_clause;
  $result = db_query($query, $limit);
  while ($row = db_fetch_object($result)) {
    $stats['total_users_audited'] ++;
    $uid = $row->uid;
    // todo: this could be expensive; perhaps look at just loading what we need?
    //  which would be badges, roles and userpoints?
    $user = user_load($uid);
    $audit = array();
    
    $audit['user'] = $uid . ' (' . $user->name . ')';

    // userpoints don't get loaded onto the user object by hook_user
    $audit['userpoints'] = userpoints_get_current_points($uid, 'all'); // all badges seem to have tid = 0
    
    // simplify the info we have about this user's badges
    if (is_array($user->badges)) {
      foreach($user->badges as $bid => $badge) {
        $audit['badges'][$bid] = $badge->name;
      }
    }    

    // check if they have the badge(s) they should have earned
    $highest_badge = NULL;
    foreach ($userpoints_goals as $bid => $goal) {
      if ($audit['userpoints'] > $goal) {
        // the user should have earned this badge (but may still have a 'higher' badge)
        //  n.b. userpoints_goals should be ORDER BY goal ASC
        $highest_badge = $bid;
      }
    }
    $audit['highest_badge'] = $highest_badge;
    
    if ($audit['highest_badge'] > 0) {
      if (isset($audit['badges'][$audit['highest_badge']])) {
        $audit['results']['highest_badge'] = 'User has the highest badge they should have, according to userpoints and goals';
      }
      else {
        $audit['results']['highest_badge'] = 'User DOES NOT have the highest badge they should have, according to userpoints and goals';
        if (!isset($failures[$uid])) {
          $stats['users_with_failures'] ++;
        }
        $stats['highest_badge_failures'] ++;
        $stats['problem_badges'][$audit['highest_badge']] ++;
        $failures[$uid]['highest_badge'] = $audit['results']['highest_badge'];
        if ($option_repair) {
          _osp_ab_repair_badge($user, $highest_badge);
          // we have to assume that this has worked for the purposes of checking
          //  that the user has the roles that correspond to their badges
          // it's important here that the value be the correct badge name, as that's how it's matched with a role
          $audit['badges'][$highest_badge] = $all_badges[$highest_badge];
        }
      }
    }
    else {
      $audit['results']['highest_badge'] = 'User is yet to earn any badges';
    }
    
    // check the roles this user has against their badges
    $audit['roles'] = $user->roles;
    
    if (is_array($audit['badges'])) {
      foreach ($audit['badges'] as $bid => $badge) {
        
        // looks like we should only be doing this check for the highest badge
        //  todo: this could be refactored as we don't really need to loop over badges at all
        if ($bid != $audit['highest_badge']) {
          continue;
        }
        
        // does this badge match an earned role? - bit weak that this is based on names matching, but that seems to be how it works
        if (($rid = array_search($badge, $earned_roles)) > 0) {
          if (isset($user->roles[$rid])) {
            $audit['results']['earned_roles'][$rid] = 'User has the role they have earned by earning the relevant badge';
          }
          else {
            $audit['results']['earned_roles'][$rid] = 'User DOES NOT have the role they have earned by earning the relevant badge';
            if (!isset($failures[$uid])) {
              $stats['users_with_failures'] ++;
            }            
            $stats['earned_roles_failures'] ++;
            $stats['problem_roles'][$rid] ++;
            $failures[$uid]['earned_roles'][$rid] = $audit['results']['earned_roles'][$rid];
            if ($option_repair) {
              _osp_ab_repair_role($user, $rid);
            }
          }
        }
      }
    }
    
    if (!$option_quiet && $option_show_debug) {
      drush_print_r($audit);
    }
  }
  
  // deal with outputting / logging feedback
  if (!$option_quiet && $option_show_failures) {
    drush_print_r($failures);
  }
  if (!$option_quiet && $option_repair) {
    drush_print('N.B. results are gathered during the repair process. To check that repairs worked, run the audit again.');
  }

  //  n.b. quiet shouldn't affect logging
  if (!$option_no_logging) {
    // this will output $stats to stdout (or is it stderr?), so no need to drush_print_r them again
    if (count($failures) > 0) {
      watchdog('opensource_points.drush', 'osp_audit_badges found one or more problems: !stats', 
        array('!stats' => print_r($stats, TRUE)), WATCHDOG_WARNING); 
    }
    else {
      watchdog('opensource_points.drush', 'osp_audit_badges ran but found no problems: !stats', 
        array('!stats' => print_r($stats, TRUE)), WATCHDOG_INFO);
    }
  }
  else if (!$option_quiet) {
    drush_print_r($stats);
  }
}

/**
 * helper to fetch an array of badge bids (keys) and the userpoints_goals (vals) for each badge
 */
function _osp_ab_userpoints_goals() {
  $userpoints_goals = array();
  $query = 'SELECT * FROM {userpoints_badges} ORDER BY userpoints_goal ASC';
  $result = db_query($query);
  while ($row = db_fetch_object($result)) {
    $userpoints_goals[$row->bid] = $row->userpoints_goal;
  }
  return $userpoints_goals;
}

/**
 * helper to fetch an array of badge bids (keys) and their names (vals)
 */
function _osp_ab_all_badges() {
  $badges = array();
  $badge_data = user_badges_get_badges('all');
  foreach($badge_data as $bid => $badge) {
    $badges[$bid] = $badge->name;
  }
  return $badges;  
}

/**
 * helper to fetch an array of role rids (keys) and the names (vals) for each earned role
 */
function _osp_ab_earned_roles() {
  $earned_roles = array();
  $role_names = opensource_points_earned_roles();
  $query = "SELECT rid FROM {role} WHERE name = '%s'";
  foreach ($role_names as $name) {
    $row = db_fetch_object(db_query($query, $name));
    if ($row->rid > 0) {
      $earned_roles[$row->rid] = $name;
    }
  }
  return $earned_roles;
}

/**
 * helper to repair a user missing a badge
 */ 
function _osp_ab_repair_badge($user, $bid) {
  $type = "Userpoints $bid";
  user_badges_user_add_badge($user->uid, $bid, $type);
  
  $message = 'Attempted to repair User uid = !uid by adding badge bid = !bid';
  $variables = array('!uid' => $user->uid, '!bid' => $bid);
  if (!drush_get_option('quiet', FALSE)) {
    drush_print(dt($message, $variables));
  }
  if (!drush_get_option('no-logging', FALSE)) {
    watchdog('opensource_points', $message, $variables, WATCHDOG_INFO);
  }
}

/**
 * helper to repair a user missing a role
 */ 
function _osp_ab_repair_role($user, $rid) { 
  _osp_ab_add_user_to_role($user->uid, $rid);
  
  $message = 'Attempted to repair User uid = !uid by adding role rid = !rid';
  $variables = array('!uid' => $user->uid, '!rid' => $rid);
  if (!drush_get_option('quiet', FALSE)) {
    drush_print(dt($message, $variables));
  }
  if (!drush_get_option('no-logging', FALSE)) {
    watchdog('opensource_points', $message, $variables, WATCHDOG_INFO);
  }
}

/**
 * borrowed from install_profile_api
 * 
 * Add a user to a role.
 */
function _osp_ab_add_user_to_role($uid, $rid) {
  if ($uid <= 0 || $rid <= 0) {
    return FALSE;
  }

  $count = db_result(db_query("SELECT COUNT(uid) FROM {users_roles} WHERE uid = %d AND rid = %d", $uid, $rid));
  if ($count == 0) {
    return db_query("INSERT INTO {users_roles} (uid, rid) VALUES (%d, %d)", $uid, $rid);
  }

  return FALSE;
}
