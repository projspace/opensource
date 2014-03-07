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
        'last_changed' => '1394165255',
        'last_entity_id' => '9',
      ),
    ),
    'apachesolr_index_updated' => 1394165406,
    'apachesolr_last_optimize' => 1394160000,
    'apachesolr_read_only' => '0',
    'apachesolr_soft_commit' => 0,
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'article',
      1 => 'event',
      2 => 'group_page',
      3 => 'page',
      4 => 'panopoly_page',
      5 => 'poll',
      6 => 'resource',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
