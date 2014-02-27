<?php
/**
 * @file
 * os_common_config.features.inc
 */

/**
 * Implements hook_filter_default_formats_alter().
 */
function os_common_config_filter_default_formats_alter(&$data) {
  if (isset($data['panopoly_html_text'])) {
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['valid_elements'] = 'a[!href|target<_blank|title|style|class],
    div[style|class|align<center?justify?left?right],
    br,em,i,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd,hr,
    span[style],p[style|class],
    h1[style|class],h2[style|class],h3[style|class],h4[style|class],h5[style|class],h6[style|class],
    img[!src|title|alt|style|width|height|class|hspace|vspace],
    @[style|class]'; /* WAS: 'a[!href|target<_blank|title|style|class],
    div[style|class|align<center?justify?left?right],
    br,em,i,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd,
    span[style],p[style|class],
    h1[style|class],h2[style|class],h3[style|class],h4[style|class],h5[style|class],h6[style|class],
    img[!src|title|alt|style|width|height|class|hspace|vspace],
    @[style|class|role|tabindex|aria-activedescendant|aria-atomic|aria-autocomplete|aria-busy|aria-checked|aria-controls|aria-describedby|aria-disabled|aria-dropeffect|aria-expanded|aria-flowto|aria-grabbed|aria-haspopup|aria-hidden|aria-invalid|aria-label|aria-labelledby|aria-level|aria-live|aria-multiline|aria-multiselectable|aria-owns|aria-posinset|aria-pressed|aria-readonly|aria-relevant|aria-required|aria-selected|aria-setsize|aria-sort|aria-valuemax|aria-valuemin|aria-valuenow|aria-valuetext]' */
  }
  if (isset($data['panopoly_wysiwyg_text'])) {
    unset($data['panopoly_wysiwyg_text']['filters']);
  }
}

/**
 * Implements hook_wysiwyg_default_profiles_alter().
 */
function os_common_config_wysiwyg_default_profiles_alter(&$data) {
  if (isset($data['panopoly_html_text'])) {
    $data['panopoly_html_text']['rdf_mapping'] = array(); /* WAS: '' */
  }
  if (isset($data['panopoly_wysiwyg_text'])) {
    $data['panopoly_wysiwyg_text']['rdf_mapping'] = array(); /* WAS: '' */
    $data['panopoly_wysiwyg_text']['settings']['buttons']['advhr'] = array(
      'advhr' => 1,
    ); /* WAS: '' */
    $data['panopoly_wysiwyg_text']['settings']['buttons']['default']['hr'] = 1; /* WAS: '' */
    $data['panopoly_wysiwyg_text']['settings']['buttons']['media'] = array(
      'media' => 1,
    ); /* WAS: '' */
  }
}
