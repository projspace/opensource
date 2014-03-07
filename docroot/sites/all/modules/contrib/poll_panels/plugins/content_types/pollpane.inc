<?php

/**
 * @file
 * Creating a custom content pane which renders a poll into a pane.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Poll Pane'),
  'description' => t('Prints the poll form or the result in a pane. Depending on the poll state'),
  'single' => TRUE,
  'content_types' => array('pollpane'),
  'render callback' => 'pollpane_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(),
  'category' => array(t('Node'), -9),
);

/**
 * Run-time rendering of the body of the block.
 *
 * @param $subtype
 * @param $conf
 *   Configuration as done at admin time.
 * @param $args
 * @param $context
 *   Context
 *
 * @return
 *   An object with at least title and content members.
 */
function pollpane_render($subtype, $conf, $args, $context) {

  $node = isset($context->data) ? $context->data : NULL;

  // Checks if we are allowed to vote and we didn't already vote. Else show
  // the result.
  if (!empty($node->allowvotes) && empty($node->show_results)) {
    $blockcontent = drupal_render(drupal_get_form('poll_view_voting', $node));
  }
  else {
    $blockcontent = array('#markup' => poll_view_results($node, 'full'));
  }

  $block = new stdClass();
  $block->title = "";
  $block->content = $blockcontent;
  return $block;

}
