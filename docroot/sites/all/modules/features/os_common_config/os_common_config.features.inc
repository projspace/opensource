<?php
/**
 * @file
 * os_common_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function os_common_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "elysia_cron" && $api == "default_elysia_cron_rules") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_filter_default_formats_alter().
 */
function os_common_config_filter_default_formats_alter(&$data) {
  if (isset($data['panopoly_html_text'])) {
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_border-1']['border'] = 'border'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_border-1']['border-bottom'] = 'border-bottom'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_border-1']['border-bottom-width'] = 'border-bottom-width'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_border-1']['border-left'] = 'border-left'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_border-1']['border-left-width'] = 'border-left-width'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_border-1']['border-right'] = 'border-right'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_border-1']['border-right-width'] = 'border-right-width'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_border-1']['border-top'] = 'border-top'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_border-1']['border-top-width'] = 'border-top-width'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_border-1']['border-width'] = 'border-width'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_border-2']['border-bottom-color'] = 'border-bottom-color'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_border-2']['border-bottom-style'] = 'border-bottom-style'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_border-2']['border-color'] = 'border-color'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_border-2']['border-left-color'] = 'border-left-color'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_border-2']['border-left-style'] = 'border-left-style'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_border-2']['border-right-color'] = 'border-right-color'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_border-2']['border-right-style'] = 'border-right-style'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_border-2']['border-style'] = 'border-style'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_border-2']['border-top-color'] = 'border-top-color'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_border-2']['border-top-style'] = 'border-top-style'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_box']['margin'] = 'margin'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_box']['margin-bottom'] = 'margin-bottom'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_box']['margin-left'] = 'margin-left'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_box']['margin-right'] = 'margin-right'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_box']['margin-top'] = 'margin-top'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_box']['padding'] = 'padding'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_box']['padding-top'] = 'padding-top'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_color']['background'] = 'background'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_color']['background-attachment'] = 'background-attachment'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_color']['background-color'] = 'background-color'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_color']['background-image'] = 'background-image'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_color']['background-position'] = 'background-position'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_color']['background-repeat'] = 'background-repeat'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_dimension']['height'] = 'height'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_dimension']['line-height'] = 'line-height'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_dimension']['max-height'] = 'max-height'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_dimension']['max-width'] = 'max-width'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_dimension']['min-height'] = 'min-height'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_dimension']['min-width'] = 'min-width'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_dimension']['width'] = 'width'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_font']['font'] = 'font'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_layout']['clear'] = 'clear'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_layout']['display'] = 'display'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_positioning']['bottom'] = 'bottom'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_positioning']['clip'] = 'clip'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_positioning']['left'] = 'left'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_positioning']['overflow'] = 'overflow'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_positioning']['right'] = 'right'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_positioning']['top'] = 'top'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_positioning']['vertical-align'] = 'vertical-align'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_text']['letter-spacing'] = 'letter-spacing'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_text']['text-indent'] = 'text-indent'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['style_text']['text-transform'] = 'text-transform'; /* WAS: 0 */
    $data['panopoly_html_text']['filters']['wysiwyg']['settings']['valid_elements'] = 'a[!href|target<_blank|title|style|class],
        div[style|class|align<center?justify?left?right],
        br,em,i,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd,hr,
        span[style],p[style|class],
        h1[style|class],h2[style|class],h3[style|class],h4[style|class],h5[style|class],h6[style|class],
        img[!src|title|alt|style|width|height|class|hspace|vspace],
        dl[style|class|align<center?justify?left?right],
        @[style|class]'; /* WAS: 'a[!href|target<_blank|title|style|class],
    div[style|class|align<center?justify?left?right],
    br,em,i,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd,
    span[style],p[style|class],
    h1[style|class],h2[style|class],h3[style|class],h4[style|class],h5[style|class],h6[style|class],
    img[!src|title|alt|style|width|height|class|hspace|vspace],
    @[style|class|role|tabindex|aria-activedescendant|aria-atomic|aria-autocomplete|aria-busy|aria-checked|aria-controls|aria-describedby|aria-disabled|aria-dropeffect|aria-expanded|aria-flowto|aria-grabbed|aria-haspopup|aria-hidden|aria-invalid|aria-label|aria-labelledby|aria-level|aria-live|aria-multiline|aria-multiselectable|aria-owns|aria-posinset|aria-pressed|aria-readonly|aria-relevant|aria-required|aria-selected|aria-setsize|aria-sort|aria-valuemax|aria-valuemin|aria-valuenow|aria-valuetext]' */
  }
  if (isset($data['panopoly_wysiwyg_text'])) {
    $data['panopoly_wysiwyg_text']['filters']['wysiwyg']['settings']['style_box'] = array(
      'margin' => 'margin',
      'margin-bottom' => 'margin-bottom',
      'margin-left' => 'margin-left',
      'margin-right' => 'margin-right',
      'margin-top' => 'margin-top',
      'padding' => 'padding',
      'padding-bottom' => 'padding-bottom',
      'padding-left' => 'padding-left',
      'padding-right' => 'padding-right',
      'padding-top' => 'padding-top',
    ); /* WAS: '' */
    $data['panopoly_wysiwyg_text']['filters']['wysiwyg']['settings']['style_dimension'] = array(
      'height' => 'height',
      'line-height' => 'line-height',
      'max-height' => 'max-height',
      'max-width' => 'max-width',
      'min-height' => 0,
      'min-width' => 'min-width',
      'width' => 'width',
    ); /* WAS: '' */
    $data['panopoly_wysiwyg_text']['filters']['wysiwyg']['settings']['style_layout'] = array(
      'clear' => 0,
      'display' => 0,
      'float' => 'float',
      'position' => 0,
      'visibility' => 0,
    ); /* WAS: '' */
    $data['panopoly_wysiwyg_text']['filters']['wysiwyg']['settings']['style_user'] = array(
      'cursor' => 'cursor',
      'outline' => 0,
      'outline-color' => 0,
      'outline-style' => 0,
      'outline-width' => 0,
      'zoom' => 'zoom',
    ); /* WAS: '' */
    $data['panopoly_wysiwyg_text']['filters']['wysiwyg']['settings']['valid_elements'] = 'a[!href|target<_blank|title|style|class],
        div[style|class|align<center?justify?left?right],
        br,em,i,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd,hr,
        span[style],p[style|class],
        h1[style|class],h2[style|class],h3[style|class],h4[style|class],h5[style|class],h6[style|class],
        img[!src|title|alt|style|width|height|class|hspace|vspace],
        dl[style|class|align<center?justify?left?right],
        @[style|class]'; /* WAS: 'a[!href|target<_blank|title|style|class],
    div[style|class|align<center?justify?left?right],
    br,em,i,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd,
    span[style],p[style|class],
    h1[style|class],h2[style|class],h3[style|class],h4[style|class],h5[style|class],h6[style|class],
    img[!src|title|alt|style|width|height|class|hspace|vspace],
    @[style|class]' */
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

/**
 * Implements hook_flag_default_flags().
 */
function os_common_config_flag_default_flags() {
  $flags = array();
  // Exported flag: "Report As Spam".
  $flags['comment_abuse'] = array(
    'entity_type' => 'comment',
    'title' => 'Report As Spam',
    'global' => 1,
    'types' => array(
      0 => 'comment_node_article',
      1 => 'comment_node_poll',
    ),
    'flag_short' => 'Report abuse or spam',
    'flag_long' => 'Report Comment To Moderators',
    'flag_message' => '',
    'unflag_short' => 'Reported',
    'unflag_long' => 'Withdraw Report To Moderators',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'module' => 'os_common_config',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
