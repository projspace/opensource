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
  $environment->url = 'http://localhost:8983/solr';
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_access_always_add_grants' => 0,
    'apachesolr_direct_commit' => 1,
    'apachesolr_index_last' => array(
      'node' => array(
        'last_changed' => '1393929790',
        'last_entity_id' => '2',
      ),
    ),
    'apachesolr_index_updated' => 1393943670,
    'apachesolr_last_optimize' => 1393941785,
    'apachesolr_read_only' => '0',
    'apachesolr_search_changed_boost' => '8:700.0',
    'apachesolr_search_comment_boost' => '8:1000.0',
    'apachesolr_search_date_boost' => '10:2000.0',
    'apachesolr_search_facet_pages' => '',
    'apachesolr_search_promote_boost' => '13.0',
    'apachesolr_search_sticky_boost' => '13.0',
    'apachesolr_search_type_boosts' => array(
      'article' => '21.0',
      'page' => '21.0',
      'panopoly_page' => '0',
      'event' => '13.0',
      'group_page' => '0',
      'poll' => '13.0',
      'resource' => '0',
      'webform' => '0',
    ),
    'apachesolr_soft_commit' => 1,
    'field_bias' => array(
      'content' => '1.0',
      'label' => '5.0',
      'tags_a' => '0',
      'tags_h1' => '5.0',
      'tags_h2_h3' => '3.0',
      'tags_h4_h5_h6' => '2.0',
      'tags_inline' => '1.0',
      'taxonomy_names' => '2.0',
      'tos_content_extra' => '0.1',
      'tos_name' => '3.0',
      'ts_comments' => '0.5',
    ),
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
      7 => 'webform',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
