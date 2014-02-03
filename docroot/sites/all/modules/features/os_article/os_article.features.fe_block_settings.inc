<?php
/**
 * @file
 * os_article.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function os_article_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-author_info-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'author_info-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'opensource' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opensource',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-related_articles-block_1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'related_articles-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'opensource' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'opensource',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
