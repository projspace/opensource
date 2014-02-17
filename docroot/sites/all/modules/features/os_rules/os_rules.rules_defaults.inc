<?php
/**
 * @file
 * os_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function os_rules_default_rules_configuration() {
  $items = array();
  $items['rules_award_points_comment'] = entity_import('rules_config', '{ "rules_award_points_comment" : {
      "LABEL" : "Award points on comment",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "comment", "points" ],
      "REQUIRES" : [ "userpoints_rules", "comment" ],
      "ON" : { "comment_insert" : [] },
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "comment:author" ],
            "points" : "5",
            "tid" : "0",
            "entity" : [ "comment" ],
            "description" : "New Comment",
            "operation" : "Insert",
            "display" : 1,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_award_points_getting_voted_comment'] = entity_import('rules_config', '{ "rules_award_points_getting_voted_comment" : {
      "LABEL" : "Award points on getting voted on comment",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "comment", "vote" ],
      "REQUIRES" : [ "rules", "userpoints_rules", "voting_rules" ],
      "ON" : { "voting_rules_insert_comment" : [] },
      "IF" : [ { "data_is" : { "data" : [ "vote:value" ], "value" : "1" } } ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "comment:author" ],
            "points" : "1",
            "tid" : "0",
            "entity" : [ "comment" ],
            "description" : "Got voted on a comment.",
            "operation" : "Vote",
            "display" : 0,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_award_points_poll'] = entity_import('rules_config', '{ "rules_award_points_poll" : {
      "LABEL" : "Award points on voting on poll",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "points", "poll" ],
      "REQUIRES" : [ "userpoints_rules", "os_rules_support" ],
      "ON" : { "os_rules_support_poll_vote" : [] },
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "site:current-user" ],
            "points" : "1",
            "tid" : "0",
            "entity" : [ "poll" ],
            "description" : "Voted on poll",
            "operation" : "Vote",
            "display" : 0,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_award_points_rate_article'] = entity_import('rules_config', '{ "rules_award_points_rate_article" : {
      "LABEL" : "Award points on rating article",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "points", "rate" ],
      "REQUIRES" : [ "rules", "userpoints_rules", "voting_rules" ],
      "ON" : { "voting_rules_insert_node" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "article" : "article" } } } }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "vote:user" ],
            "points" : "1",
            "tid" : "0",
            "entity" : [ "node" ],
            "description" : "Rated an article.",
            "operation" : "Vote",
            "display" : 0,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_award_points_user_login'] = entity_import('rules_config', '{ "rules_award_points_user_login" : {
      "LABEL" : "Award point on user login",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "points", "user" ],
      "REQUIRES" : [ "userpoints_rules", "rules" ],
      "ON" : { "user_login" : [] },
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "account" ],
            "points" : "1",
            "tid" : "0",
            "entity" : [ "" ],
            "description" : "User Login",
            "operation" : "Login",
            "display" : 0,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_award_points_vote_comment'] = entity_import('rules_config', '{ "rules_award_points_vote_comment" : {
      "LABEL" : "Award points on voting on comment",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "comment", "vote" ],
      "REQUIRES" : [ "userpoints_rules", "voting_rules" ],
      "ON" : { "voting_rules_insert_comment" : [] },
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "vote:user" ],
            "points" : "1",
            "tid" : "0",
            "entity" : [ "comment" ],
            "description" : "Voted on a comment.",
            "operation" : "Vote",
            "display" : 0,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_redirect_user_after_registration'] = entity_import('rules_config', '{ "rules_redirect_user_after_registration" : {
      "LABEL" : "Redirect user after registration",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "user" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "DO" : [ { "redirect" : { "url" : "user\\/thank-you" } } ]
    }
  }');
  return $items;
}
