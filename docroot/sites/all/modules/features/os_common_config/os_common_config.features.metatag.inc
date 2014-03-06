<?php
/**
 * @file
 * os_common_config.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function os_common_config_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: global.
  $config['global'] = array(
    'instance' => 'global',
    'config' => array(
      'title' => array(
        'value' => '[current-page:title] | [site:name]',
      ),
      'generator' => array(
        'value' => 'Drupal 7 (http://drupal.org)',
      ),
      'canonical' => array(
        'value' => '[current-page:url:absolute]',
      ),
      'shortlink' => array(
        'value' => '[current-page:url:unaliased]',
      ),
    ),
  );

  // Exported Metatag config instance: global:403.
  $config['global:403'] = array(
    'instance' => 'global:403',
    'config' => array(
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
    ),
  );

  // Exported Metatag config instance: global:404.
  $config['global:404'] = array(
    'instance' => 'global:404',
    'config' => array(
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
    ),
  );

  // Exported Metatag config instance: global:frontpage.
  $config['global:frontpage'] = array(
    'instance' => 'global:frontpage',
    'config' => array(
      'title' => array(
        'value' => '[site:name]',
      ),
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
    ),
  );

  // Exported Metatag config instance: node.
  $config['node'] = array(
    'instance' => 'node',
    'config' => array(
      'title' => array(
        'value' => '[node:title] | [site:name]',
      ),
      'description' => array(
        'value' => '[node:summary]',
      ),
    ),
  );

  // Exported Metatag config instance: node:article.
  $config['node:article'] = array(
    'instance' => 'node:article',
    'config' => array(
      'description' => array(
        'value' => 'Explore how the principles behind open source--collaboration, transparency, and rapid prototyping--are proven catalysts for innovation.',
      ),
      'revisit-after' => array(
        'value' => 1,
        'period' => 'day',
      ),
    ),
  );

  // Exported Metatag config instance: node:group_page.
  $config['node:group_page'] = array(
    'instance' => 'node:group_page',
    'config' => array(
      'description' => array(
        'value' => 'Explore how the principles behind open source--collaboration, transparency, and rapid prototyping--are proven catalysts for innovation.',
      ),
      'revisit-after' => array(
        'value' => 1,
        'period' => 'day',
      ),
    ),
  );

  // Exported Metatag config instance: node:page.
  $config['node:page'] = array(
    'instance' => 'node:page',
    'config' => array(
      'description' => array(
        'value' => 'Explore how the principles behind open source--collaboration, transparency, and rapid prototyping--are proven catalysts for innovation.',
      ),
      'revisit-after' => array(
        'value' => 1,
        'period' => 'day',
      ),
    ),
  );

  // Exported Metatag config instance: node:panopoly_page.
  $config['node:panopoly_page'] = array(
    'instance' => 'node:panopoly_page',
    'config' => array(
      'description' => array(
        'value' => 'Explore how the principles behind open source--collaboration, transparency, and rapid prototyping--are proven catalysts for innovation.',
      ),
      'revisit-after' => array(
        'value' => 1,
        'period' => 'day',
      ),
    ),
  );

  // Exported Metatag config instance: node:resource.
  $config['node:resource'] = array(
    'instance' => 'node:resource',
    'config' => array(
      'description' => array(
        'value' => 'Explore how the principles behind open source--collaboration, transparency, and rapid prototyping--are proven catalysts for innovation.',
      ),
      'revisit-after' => array(
        'value' => 1,
        'period' => 'day',
      ),
    ),
  );

  // Exported Metatag config instance: node:webform.
  $config['node:webform'] = array(
    'instance' => 'node:webform',
    'config' => array(
      'description' => array(
        'value' => 'Explore how the principles behind open source--collaboration, transparency, and rapid prototyping--are proven catalysts for innovation.',
      ),
      'revisit-after' => array(
        'value' => 1,
        'period' => 'day',
      ),
    ),
  );

  // Exported Metatag config instance: taxonomy_term.
  $config['taxonomy_term'] = array(
    'instance' => 'taxonomy_term',
    'config' => array(
      'title' => array(
        'value' => '[term:name] | [site:name]',
      ),
      'description' => array(
        'value' => '[term:description]',
      ),
    ),
  );

  // Exported Metatag config instance: user.
  $config['user'] = array(
    'instance' => 'user',
    'config' => array(
      'title' => array(
        'value' => '[user:name] | [site:name]',
      ),
    ),
  );

  return $config;
}
