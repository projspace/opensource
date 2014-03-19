<?php
/**
 * @file
 * os_solr_search.apachesolr_environments.inc
 */

/**
 * Implements hook_apachesolr_environments().
 */
function os_solr_search_apachesolr_environments() {
  $export = array();

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'solr';
  $environment->name = 'localhost server';
  $environment->url = 'http://ec2-54-81-62-45.compute-1.amazonaws.com/solr/';
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_access_always_add_grants' => 0,
    'apachesolr_direct_commit' => 0,
    'apachesolr_index_last' => array(
      'node' => array(
        'last_changed' => '1394608017',
        'last_entity_id' => '5',
      ),
    ),
    'apachesolr_index_updated' => 1395122122,
    'apachesolr_last_optimize' => 1395122122,
    'apachesolr_read_only' => '0',
    'apachesolr_soft_commit' => 0,
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'article',
      1 => 'event',
      2 => 'page',
      3 => 'panopoly_page',
      4 => 'poll',
      5 => 'resource',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
