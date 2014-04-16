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
  $items['rules_article_published'] = entity_import('rules_config', '{ "rules_article_published" : {
      "LABEL" : "Award points for published article",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "article", "points", "workflow" ],
      "REQUIRES" : [ "rules", "workflow_rules", "userpoints_rules" ],
      "ON" : { "workflow_state_changed" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "article" : "article" } }
          }
        },
        { "workflow_check_state" : { "node" : [ "node" ], "workflow_state" : { "value" : { "3" : "3" } } } }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "30",
            "tid" : "0",
            "entity" : [ "node" ],
            "description" : "Published Article",
            "operation" : "Publish",
            "display" : 1,
            "moderate" : "default"
          }
        }
      ]
    }
  }');
  $items['rules_award_points_comment'] = entity_import('rules_config', '{ "rules_award_points_comment" : {
      "LABEL" : "Award points on comment",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "comment", "points" ],
      "REQUIRES" : [ "rules", "userpoints_rules", "comment" ],
      "ON" : { "comment_insert" : [] },
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        }
      ],
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
  $items['rules_award_points_top_contributor'] = entity_import('rules_config', '{ "rules_award_points_top_contributor" : {
      "LABEL" : "Award points to top contributor",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "flag", "points", "spotlight", "user" ],
      "REQUIRES" : [ "userpoints_rules", "flag" ],
      "ON" : { "flag_flagged_spotlight" : [] },
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "flagged-user" ],
            "points" : "50",
            "tid" : "0",
            "entity" : [ "flagging" ],
            "description" : "User Spotlighted",
            "operation" : "Spotlighted",
            "display" : 1,
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
  $items['rules_event_published'] = entity_import('rules_config', '{ "rules_event_published" : {
      "LABEL" : "Award points and send notification on event getting published",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "event", "points", "workflow" ],
      "REQUIRES" : [ "rules", "workflow_rules", "userpoints_rules" ],
      "ON" : { "workflow_state_changed" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "event" : "event" } }
          }
        },
        { "workflow_check_state" : { "node" : [ "node" ], "workflow_state" : { "value" : { "3" : "3" } } } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:field-event-submitter-email" ],
            "subject" : "Your event has been approved",
            "message" : "We have approved your event: [node:title]\\r\\n\\r\\nPlease visit our calendar at http:\\/\\/opensource.com\\/resources\\/conferences-and-events-monthly to view your event listing.\\r\\n\\r\\nThanks,\\r\\nopensource.com team",
            "from" : "osdc-admin@redhat.com",
            "language" : [ "" ]
          }
        },
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "10",
            "tid" : "0",
            "entity" : [ "node" ],
            "description" : "Publishing Event",
            "operation" : "Publish",
            "display" : 1,
            "moderate" : "default"
          }
        }
      ]
    }
  }');
  $items['rules_poll_published'] = entity_import('rules_config', '{ "rules_poll_published" : {
      "LABEL" : "Award points for published poll",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "points", "poll", "workflow" ],
      "REQUIRES" : [ "rules", "workflow_rules", "userpoints_rules" ],
      "ON" : { "workflow_state_changed" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "poll" : "poll" } }
          }
        },
        { "workflow_check_state" : { "node" : [ "node" ], "workflow_state" : { "value" : { "3" : "3" } } } }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : "15",
            "tid" : "0",
            "entity" : [ "node" ],
            "description" : "Published Poll",
            "operation" : "Publish",
            "display" : 1,
            "moderate" : "default"
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
  $items['rules_send_notifications_event_creation'] = entity_import('rules_config', '{ "rules_send_notifications_event_creation" : {
      "LABEL" : "Send notifications on event creation",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "event" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--event" : { "bundle" : "event" } },
      "DO" : [
        { "mail" : {
            "to" : "osdc-mail@redhat.com",
            "subject" : "New event submitted",
            "message" : "A new event has been submitted. Please visit http:\\/\\/opensource.com\\/moderation-queue\\/events\\/all to approve.\\r\\n\\r\\nEvent title: [node:title]\\r\\nBy: [node:author:user]",
            "from" : "osdc-mail@redhat.com",
            "language" : [ "" ]
          }
        },
        { "mail" : {
            "to" : [ "node:field-event-submitter-email" ],
            "subject" : "Thanks for submitting your event",
            "message" : "Our admins will review your submission and approve your event if it fits within our guidelines. We will contact you if there are any questions.\\r\\n\\r\\nThanks,\\r\\nopensource.com team",
            "from" : "osdc-mail@redhat.com",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_user_awarded_role_badge'] = entity_import('rules_config', '{ "rules_user_awarded_role_badge" : {
      "LABEL" : "User is awarded a role badge",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "badge" ],
      "REQUIRES" : [ "rules", "os_badges" ],
      "ON" : { "user_badges_role_badge_given" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "site:current-user:field-profile-point-notification" ],
            "value" : 1
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[user:mail]",
            "subject" : " opensource.com badge added.",
            "message" : "[user:name],\\r\\n\\r\\nCongratulations! You\\u0027ve been promoted.\\r\\nYou\\u0027ve gained enough points by participating at opensource.com to move up and join a new role.\\r\\n\\r\\nAs a new !rolename, you\\u0027re now cooler than you were just five minutes ago. We extend our warmest thanks for your contributions and participation.\\r\\n\\r\\nBadge : [badge-name:value]\\r\\n\\r\\nQuestions about our roles and badges system? Get more details here:\\r\\nhttp:\\/\\/opensource.com\\/points-and-badges\\r\\n\\r\\nThank you,\\r\\nthe opensource.com team",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
