<?php
/**
 * @file
 * os_workflow.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function os_workflow_default_rules_configuration() {
  $items = array();
  $items['rules_workflow_status_change_from_created_to_review'] = entity_import('rules_config', '{ "rules_workflow_status_change_from_created_to_review" : {
      "LABEL" : "Workflow status change from Published to Review",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "workflow" ],
      "REQUIRES" : [ "workflow_rules", "rules" ],
      "ON" : { "workflow_state_changed" : [] },
      "IF" : [
        { "workflow_check_state" : { "node" : [ "node" ], "workflow_state" : { "value" : { "2" : "2" } } } }
      ],
      "DO" : [ { "node_unpublish" : { "node" : [ "node" ] } } ]
    }
  }');
  $items['rules_workflow_status_change_from_review_to_published'] = entity_import('rules_config', '{ "rules_workflow_status_change_from_review_to_published" : {
      "LABEL" : "Workflow status change from Review to Published",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "workflow" ],
      "REQUIRES" : [ "workflow_rules", "rules" ],
      "ON" : { "workflow_state_changed" : [] },
      "IF" : [
        { "workflow_check_state" : { "node" : [ "node" ], "workflow_state" : { "value" : { "3" : "3" } } } }
      ],
      "DO" : [ { "node_publish" : { "node" : [ "node" ] } } ]
    }
  }');
  return $items;
}
