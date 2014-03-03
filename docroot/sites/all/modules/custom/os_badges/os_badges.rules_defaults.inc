<?php
/**
 * @file
 * Rules definitions for OpenSource Badges.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function os_badges_default_rules_configuration() {
  $year = date('Y') - 1;
  $defs = array(
    "Conversation Starter Award $year" => array(
      'badge' => 'conversation_starter',
      'points' => 50,
    ),
    "Social Sharer Award $year" => array(
      'badge' => 'social_sharer',
      'points' => 50,
    ),
    "Moderator's Choice Award $year" => array(
      'badge' => 'moderators_choice',
      'points' => 100,
    ),
    "People's Choice Award $year" => array(
      'badge' => 'peoples_choice',
      'points' => 100,
    ),
  );

  $badges = os_badges_get_badges(array_keys($defs), 'name');

  $items = array();
  foreach ($defs as $name => $info) {
    if (!empty($badges[$name]->bid)) {
      $rules_config = _os_badges_rules_config($badges[$name]->bid, $info['badge'], $name, $info['points']);
      $items['rules_award_points_' . $info['badge'] . '_badge'] = entity_import('rules_config', $rules_config);
    }
  }

  return $items;
}

/**
 * Helper function to generate rule configuration.
 */
function _os_badges_rules_config($badge_id, $badge_machine_name, $badge_name, $points) {
  return <<<RULE
{ "rules_award_points_{$badge_machine_name}_badge" : {
      "LABEL" : "Award points on awarded $badge_name Badge",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "badge", "points", "user" ],
      "REQUIRES" : [ "rules", "userpoints_rules", "user_badges" ],
      "ON" : { "user_badges_badge_given" : [] },
      "IF" : [ { "data_is" : { "data" : [ "badge-id" ], "value" : "$badge_id" } } ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "user" ],
            "points" : "$points",
            "tid" : "0",
            "entity" : [ "user" ],
            "description" : "Awarded $badge_name Badge",
            "operation" : "Award",
            "display" : 1,
            "moderate" : "default"
          }
        }
      ]
    }
  }
RULE;
}
