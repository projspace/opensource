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
  'title' => t('Article Poll Pane'),
  'description' => t('Prints the poll form or the result of the referenced poll from article, in a pane. Depending on the poll state'),
  'single' => TRUE,
  'content_types' => array('pollpane'),
  'render callback' => 'article_pollpane_render',
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
function article_pollpane_render($subtype, $conf, $args, $context) {

  $node = isset($context->data) ? $context->data : NULL;
  if(isset($node->field_related_poll)) {
    $pollnode = node_load($node->field_related_poll[LANGUAGE_NONE][0]['target_id']);
    // Checks if we are allowed to vote and we didn't already vote. Else show
    // the result.
    if (!empty($pollnode->allowvotes) && empty($pollnode->show_results)) {
      $form = drupal_get_form('poll_view_voting', $pollnode);
      $blockcontent = drupal_render($form);
    }
    else {
      $blockcontent = array('#markup' => poll_view_results($pollnode, 'full'));
      $total_votes = 0;
      foreach ($pollnode->choice as $choice) {
        if (isset($choice['chvotes'])) {
          $total_votes += $choice['chvotes'];
        }
      }
      if($total_votes == 0) {
        $blockcontent = ''; //Disabling block content becuase if no poll it present it shows "Total votes 0 text."
      }
    }
    $block = new stdClass();
    $block->title = "";
    $block->content = $blockcontent;
    return $block;
  }
}
