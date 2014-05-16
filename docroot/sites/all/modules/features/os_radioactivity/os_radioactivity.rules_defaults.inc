<?php
/**
 * @file
 * os_radioactivity.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function os_radioactivity_default_rules_configuration() {
  $items = array();
  $items['rules_radioactivity_article_comment_submitted'] = entity_import('rules_config', '{ "rules_radioactivity_article_comment_submitted" : {
      "LABEL" : "Radioactivity Article comment Submitted",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "radioactivity" ],
      "REQUIRES" : [ "rules", "radioactivity", "comment" ],
      "ON" : { "comment_insert--comment_node_article" : { "bundle" : "comment_node_article" } },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "comment:node" ], "type" : "node" } },
        { "node_is_of_type" : {
            "node" : [ "comment:node" ],
            "type" : { "value" : { "article" : "article" } }
          }
        },
        { "AND" : [] },
        { "data_is" : { "data" : [ "comment:status" ], "value" : "1" } }
      ],
      "DO" : [
        { "radioactivity_emit" : { "data" : [ "comment:node:field-energy-level" ], "value" : "20" } }
      ]
    }
  }');
  $items['rules_radioactivity_article_comment_submitted_and_unpublished'] = entity_import('rules_config', '{ "rules_radioactivity_article_comment_submitted_and_unpublished" : {
      "LABEL" : "Radioactivity Article comment Submitted and Unpublished",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "radioactivity" ],
      "REQUIRES" : [ "rules", "radioactivity", "comment" ],
      "ON" : { "comment_insert--comment_node_article" : { "bundle" : "comment_node_article" } },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "comment:node" ], "type" : "node" } },
        { "node_is_of_type" : {
            "node" : [ "comment:node" ],
            "type" : { "value" : { "article" : "article" } }
          }
        },
        { "AND" : [] },
        { "data_is" : { "data" : [ "comment:status" ], "value" : "0" } }
      ],
      "DO" : [
        { "radioactivity_emit" : { "data" : [ "comment:node:field-energy-level" ], "value" : "10" } }
      ]
    }
  }');
  $items['rules_radioactivity_article_node_view'] = entity_import('rules_config', '{ "rules_radioactivity_article_node_view" : {
      "LABEL" : "Radioactivity Article Node View",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "radioactivity" ],
      "REQUIRES" : [ "rules", "radioactivity" ],
      "ON" : { "node_view--article" : { "bundle" : "article" } },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1", "2" : "2", "3" : "3", "4" : "4" } }
          }
        }
      ],
      "DO" : [
        { "radioactivity_emit" : { "data" : [ "node:field-energy-level" ], "value" : "100" } }
      ]
    }
  }');
  $items['rules_radioactivity_article_submitted'] = entity_import('rules_config', '{ "rules_radioactivity_article_submitted" : {
      "LABEL" : "Radioactivity Article Submitted",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "radioactivity" ],
      "REQUIRES" : [ "radioactivity", "rules" ],
      "ON" : { "node_insert--article" : { "bundle" : "article" } },
      "DO" : [
        { "radioactivity_emit" : { "data" : [ "node:field-energy-level" ], "value" : "5" } }
      ]
    }
  }');
  $items['rules_radioactivity_comment_vote_down'] = entity_import('rules_config', '{ "rules_radioactivity_comment_vote_down" : {
      "LABEL" : "Radioactivity Comment Vote Down",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "radioactivity" ],
      "REQUIRES" : [ "rules", "voting_rules", "radioactivity" ],
      "ON" : { "voting_rules_insert_comment" : [] },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "comment:node" ], "type" : "node" } },
        { "node_is_of_type" : {
            "node" : [ "comment:node" ],
            "type" : { "value" : { "article" : "article" } }
          }
        },
        { "AND" : [] },
        { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "value" : "-1" } }
      ],
      "DO" : [
        { "radioactivity_emit" : { "data" : [ "comment:node:field-energy-level" ], "value" : "5" } }
      ]
    }
  }');
  $items['rules_radioactivity_comment_vote_up'] = entity_import('rules_config', '{ "rules_radioactivity_comment_vote_up" : {
      "LABEL" : "Radioactivity Comment Vote Up",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "radioactivity" ],
      "REQUIRES" : [ "rules", "voting_rules", "radioactivity" ],
      "ON" : { "voting_rules_insert_comment" : [] },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "comment:node" ], "type" : "node" } },
        { "node_is_of_type" : {
            "node" : [ "comment:node" ],
            "type" : { "value" : { "article" : "article" } }
          }
        },
        { "AND" : [] },
        { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "value" : "1" } }
      ],
      "DO" : [
        { "radioactivity_emit" : { "data" : [ "comment:node:field-energy-level" ], "value" : "5" } }
      ]
    }
  }');
  $items['rules_radioactivity_rate_article_five_star'] = entity_import('rules_config', '{ "rules_radioactivity_rate_article_five_star" : {
      "LABEL" : "Radioactivity Rate Article five star",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "radioactivity" ],
      "REQUIRES" : [ "rules", "voting_rules", "radioactivity" ],
      "ON" : { "voting_rules_insert_node" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "article" : "article" } } } },
        { "AND" : [] },
        { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "value" : "100" } }
      ],
      "DO" : [
        { "radioactivity_emit" : { "data" : [ "node:field-energy-level" ], "value" : "10" } }
      ]
    }
  }');
  $items['rules_radioactivity_rate_article_four_star'] = entity_import('rules_config', '{ "rules_radioactivity_rate_article_four_star" : {
      "LABEL" : "Radioactivity Rate Article four star",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "radioactivity" ],
      "REQUIRES" : [ "rules", "voting_rules", "radioactivity" ],
      "ON" : { "voting_rules_insert_node" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "article" : "article" } } } },
        { "AND" : [] },
        { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "value" : "80" } }
      ],
      "DO" : [
        { "radioactivity_emit" : { "data" : [ "node:field-energy-level" ], "value" : "10" } }
      ]
    }
  }');
  $items['rules_radioactivity_rate_article_one_star'] = entity_import('rules_config', '{ "rules_radioactivity_rate_article_one_star" : {
      "LABEL" : "Radioactivity Rate Article one Star",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "radioactivity" ],
      "REQUIRES" : [ "rules", "voting_rules", "radioactivity" ],
      "ON" : { "voting_rules_insert_node" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "article" : "article" } } } },
        { "AND" : [] },
        { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "value" : "20" } }
      ],
      "DO" : [
        { "radioactivity_emit" : { "data" : [ "node:field-energy-level" ], "value" : "10" } }
      ]
    }
  }');
  $items['rules_radioactivity_rate_article_three_star'] = entity_import('rules_config', '{ "rules_radioactivity_rate_article_three_star" : {
      "LABEL" : "Radioactivity Rate Article three star",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "radioactivity" ],
      "REQUIRES" : [ "rules", "voting_rules", "radioactivity" ],
      "ON" : { "voting_rules_insert_node" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "article" : "article" } } } },
        { "AND" : [] },
        { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "value" : "60" } }
      ],
      "DO" : [
        { "radioactivity_emit" : { "data" : [ "node:field-energy-level" ], "value" : "10" } }
      ]
    }
  }');
  $items['rules_radioactivity_rate_article_two_star'] = entity_import('rules_config', '{ "rules_radioactivity_rate_article_two_star" : {
      "LABEL" : "Radioactivity Rate Article two Star",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "radioactivity" ],
      "REQUIRES" : [ "rules", "voting_rules", "radioactivity" ],
      "ON" : { "voting_rules_insert_node" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "article" : "article" } } } },
        { "AND" : [] },
        { "voting_rules_condition_check_vote_value" : { "vote" : [ "vote" ], "value" : "40" } }
      ],
      "DO" : [
        { "radioactivity_emit" : { "data" : [ "node:field-energy-level" ], "value" : "10" } }
      ]
    }
  }');
  return $items;
}
