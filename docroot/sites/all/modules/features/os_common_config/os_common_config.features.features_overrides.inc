<?php
/**
 * @file
 * os_common_config.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function os_common_config_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: filter
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|valid_elements"] = 'a[!href|target<_blank|title|style|class],
  div[style|class|align<center?justify?left?right],
  br,em,i,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd,hr,
  span[style],p[style|class],
  h1[style|class],h2[style|class],h3[style|class],h4[style|class],h5[style|class],h6[style|class],
  img[!src|title|alt|style|width|height|class|hspace|vspace],
  @[style|class]';
  $overrides["filter.panopoly_wysiwyg_text.filters"]["DELETED"] = TRUE;

  // Exported overrides for: wysiwyg
  $overrides["wysiwyg.panopoly_html_text.rdf_mapping"] = array();
  $overrides["wysiwyg.panopoly_wysiwyg_text.rdf_mapping"] = array();
  $overrides["wysiwyg.panopoly_wysiwyg_text.settings|buttons|advhr"] = array(
    'advhr' => 1,
  );
  $overrides["wysiwyg.panopoly_wysiwyg_text.settings|buttons|default|hr"] = 1;
  $overrides["wysiwyg.panopoly_wysiwyg_text.settings|buttons|media"] = array(
    'media' => 1,
  );

 return $overrides;
}
