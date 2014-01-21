<?php
// $Id: context_og_condition_group_type.inc,v 1.1 2010/07/12 23:17:21 marcp Exp $

/**
 * Expose organic groups group types as a context condition.
 */
class context_og_condition_group_type extends context_condition {
  function condition_values() {
    $values = array();
    $og_types = og_get_types('group');
    foreach (node_get_types() as $type) {
      if (in_array($type->type, $og_types)) {
        $values[$type->type] = $type->name;
      }
    }
    return $values;
  }

  function options_form($context) {
    $defaults = $this->fetch_from_context($context, 'options');
    return array(
      'node_form' => array(
        '#title' => t('Set on node form'),
        '#type' => 'checkbox',
        '#description' => t('Set this context on node forms'),
        '#default_value' => isset($defaults['node_form']) ? $defaults['node_form'] : TRUE,
      ),
    );
  }

  function execute($group) {
    if (isset($group)) {
      $node_form = ((arg(0) == 'node') && ((is_numeric(arg(1)) && (arg(2) == 'edit')) || (arg(1) == 'add')));
      $contexts = $this->get_contexts($group->type);
      $this->values[$group->type] = array();
      foreach ($contexts as $context) {
        $options = $this->fetch_from_context($context, 'options');
        // The condition is met unless we are looking at a node form
        // and the "Set on node form" option is unchecked.
        if (!$node_form || !empty($options['node_form'])) {
          $this->condition_met($context, $group->type);
        }
      }
    }
  }
}
