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
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_border-1|border"] = 'border';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_border-1|border-bottom"] = 'border-bottom';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_border-1|border-bottom-width"] = 'border-bottom-width';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_border-1|border-left"] = 'border-left';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_border-1|border-left-width"] = 'border-left-width';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_border-1|border-right"] = 'border-right';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_border-1|border-right-width"] = 'border-right-width';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_border-1|border-top"] = 'border-top';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_border-1|border-top-width"] = 'border-top-width';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_border-1|border-width"] = 'border-width';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_border-2|border-bottom-color"] = 'border-bottom-color';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_border-2|border-bottom-style"] = 'border-bottom-style';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_border-2|border-color"] = 'border-color';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_border-2|border-left-color"] = 'border-left-color';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_border-2|border-left-style"] = 'border-left-style';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_border-2|border-right-color"] = 'border-right-color';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_border-2|border-right-style"] = 'border-right-style';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_border-2|border-style"] = 'border-style';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_border-2|border-top-color"] = 'border-top-color';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_border-2|border-top-style"] = 'border-top-style';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_box|margin"] = 'margin';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_box|margin-bottom"] = 'margin-bottom';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_box|margin-left"] = 'margin-left';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_box|margin-right"] = 'margin-right';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_box|margin-top"] = 'margin-top';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_box|padding"] = 'padding';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_box|padding-top"] = 'padding-top';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_color|background"] = 'background';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_color|background-attachment"] = 'background-attachment';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_color|background-color"] = 'background-color';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_color|background-image"] = 'background-image';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_color|background-position"] = 'background-position';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_color|background-repeat"] = 'background-repeat';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_dimension|height"] = 'height';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_dimension|line-height"] = 'line-height';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_dimension|max-height"] = 'max-height';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_dimension|max-width"] = 'max-width';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_dimension|min-height"] = 'min-height';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_dimension|min-width"] = 'min-width';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_dimension|width"] = 'width';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_font|font"] = 'font';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_layout|clear"] = 'clear';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_layout|display"] = 'display';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_positioning|bottom"] = 'bottom';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_positioning|clip"] = 'clip';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_positioning|left"] = 'left';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_positioning|overflow"] = 'overflow';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_positioning|right"] = 'right';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_positioning|top"] = 'top';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_positioning|vertical-align"] = 'vertical-align';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_text|letter-spacing"] = 'letter-spacing';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_text|text-indent"] = 'text-indent';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|style_text|text-transform"] = 'text-transform';
  $overrides["filter.panopoly_html_text.filters|wysiwyg|settings|valid_elements"] = 'a[!href|target<_blank|title|style|class],
  div[style|class|align<center?justify?left?right],
  br,em,i,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd,hr,
  span[style],p[style|class],
  h1[style|class],h2[style|class],h3[style|class],h4[style|class],h5[style|class],h6[style|class],
  img[!src|title|alt|style|width|height|class|hspace|vspace],
  dl[style|class|align<center?justify?left?right],
  @[style|class]';
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|style_box"] = array(
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
  );
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|style_dimension"] = array(
    'height' => 'height',
    'line-height' => 'line-height',
    'max-height' => 'max-height',
    'max-width' => 'max-width',
    'min-height' => 0,
    'min-width' => 'min-width',
    'width' => 'width',
  );
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|style_layout"] = array(
    'clear' => 0,
    'display' => 0,
    'float' => 'float',
    'position' => 0,
    'visibility' => 0,
  );
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|style_user"] = array(
    'cursor' => 'cursor',
    'outline' => 0,
    'outline-color' => 0,
    'outline-style' => 0,
    'outline-width' => 0,
    'zoom' => 'zoom',
  );
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|valid_elements"] = 'a[!href|target<_blank|title|style|class],
  div[style|class|align<center?justify?left?right],
  br,em,i,strong,cite,code,blockquote,ul,ol,li,dl,dt,dd,hr,
  span[style],p[style|class],
  h1[style|class],h2[style|class],h3[style|class],h4[style|class],h5[style|class],h6[style|class],
  img[!src|title|alt|style|width|height|class|hspace|vspace],
  dl[style|class|align<center?justify?left?right],
  @[style|class]';

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
