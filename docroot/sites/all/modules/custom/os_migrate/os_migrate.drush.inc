<?php
/**
 * @file
 * Drush support.
 */

/**
 * Implements hook_drush_command().
 */
function os_migrate_drush_command() {
  $items = array();

  // Generate the mediabrowser plus terms.
  $items['poll-choice-fix'] = array(
    'description' => 'Remove duplicate poll choices.',
    'options' => array(
      'idlist' => 'List node IDs which have to be processed.',
    ),
    'aliases' => array('pollchfix', 'pcf'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );
  return $items;
}

/**
 * Command callback for drush poll-choice-fix.
 */
function drush_os_migrate_poll_choice_fix() {
  $ids = drush_get_option('idlist');
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'poll')
    ->addMetaData('account', user_load(1)); // Run the query as user 1.
  $result = $query->execute();

  // Loop and destroy!
  if (!empty($result['node']) && drush_confirm(t('Are you sure you want to delete duplicate choices from !count polls?', array('!count' => count($result['node']))))) {
    foreach ($result['node'] as $node) {
      $node = node_load($node->nid);

      // Build a reference of all choices.
      $choices = array();
      foreach ($node->choice as $chid => $choice) {
        $choices[$choice['chtext']][] = $chid;
      }

      // Figure out which ones to delete.
      $ids_to_delete = array();
      foreach ($choices as $chtext => $chids) {
        if (count($chids) > 1) {
          $ids_to_delete[] = max($chids);
        }
      }

      // Delete.
      if (count($ids_to_delete)) {
        drush_log(t('Deleting !count choices from poll !id (@title)...', array('!count' => count($ids_to_delete), '@title' => $node->title, '!id' => $node->nid)));
        db_delete('poll_choice')
          ->condition('chid', $ids_to_delete)
          ->execute();
      }
    }
  }
  else {
    drush_print('There are no polls to process');
  }
}
