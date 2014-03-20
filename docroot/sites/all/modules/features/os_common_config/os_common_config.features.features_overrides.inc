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
  $overrides["filter.panopoly_html_text.filters|wysiwyg"]["DELETED"] = TRUE;
  $overrides["filter.panopoly_html_text.name"] = 'Full HTML';
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|rule_valid_classes"] = array(
    0 => 'a*',
    2 => 'b*',
    4 => 'c*',
    6 => 'd*',
    8 => 'e*',
    10 => 'f*',
    12 => 'g*',
    14 => 'h*',
    16 => 'i*',
    18 => 'j*',
    20 => 'k*',
    22 => 'l*',
    24 => 'm*',
    26 => 'n*',
    28 => 'o*',
    30 => 'p*',
    32 => 'q*',
    34 => 'r*',
    36 => 's*',
    38 => 't*',
    40 => 'u*',
    42 => 'v*',
    44 => 'w*',
    46 => 'x*',
    48 => 'y*',
    50 => 'z*',
    52 => 'A*',
    54 => 'B*',
    56 => 'C*',
    58 => 'D*',
    60 => 'E*',
    62 => 'F*',
    64 => 'G*',
    66 => 'H*',
    68 => 'I*',
    70 => 'J*',
    72 => 'K*',
    74 => 'L*',
    76 => 'M*',
    78 => 'N*',
    80 => 'O*',
    82 => 'P*',
    84 => 'Q*',
    86 => 'R*',
    88 => 'S*',
    90 => 'T*',
    92 => 'U*',
    94 => 'V*',
    96 => 'W*',
    98 => 'X*',
    100 => 'Y*',
    102 => 'Z*',
  );
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|style_border-1"] = array(
    'border' => 0,
    'border-bottom' => 0,
    'border-bottom-width' => 0,
    'border-left' => 0,
    'border-left-width' => 0,
    'border-right' => 0,
    'border-right-width' => 0,
    'border-top' => 0,
    'border-top-width' => 0,
    'border-width' => 0,
  );
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|style_border-2"] = array(
    'border-bottom-color' => 0,
    'border-bottom-style' => 0,
    'border-color' => 0,
    'border-left-color' => 0,
    'border-left-style' => 0,
    'border-right-color' => 0,
    'border-right-style' => 0,
    'border-style' => 0,
    'border-top-color' => 0,
    'border-top-style' => 0,
  );
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
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|style_color"] = array(
    'background' => 0,
    'background-attachment' => 0,
    'background-color' => 0,
    'background-image' => 0,
    'background-position' => 0,
    'background-repeat' => 0,
    'color' => 'color',
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
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|style_font"] = array(
    'font' => 0,
    'font-family' => 0,
    'font-size' => 0,
    'font-size-adjust' => 0,
    'font-stretch' => 0,
    'font-style' => 0,
    'font-variant' => 0,
    'font-weight' => 0,
  );
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|style_layout"] = array(
    'clear' => 0,
    'display' => 0,
    'float' => 'float',
    'position' => 0,
    'visibility' => 0,
  );
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|style_list"] = array(
    'list-style' => 0,
    'list-style-image' => 0,
    'list-style-position' => 0,
    'list-style-type' => 0,
  );
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|style_positioning"] = array(
    'bottom' => 0,
    'clip' => 0,
    'left' => 0,
    'overflow' => 0,
    'right' => 0,
    'top' => 0,
    'vertical-align' => 0,
    'z-index' => 0,
  );
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|style_table"] = array(
    'border-collapse' => 0,
    'border-spacing' => 0,
    'caption-side' => 0,
    'empty-cells' => 0,
    'table-layout' => 0,
  );
  $overrides["filter.panopoly_wysiwyg_text.filters|wysiwyg|settings|style_text"] = array(
    'direction' => 0,
    'letter-spacing' => 0,
    'text-align' => 'text-align',
    'text-decoration' => 'text-decoration',
    'text-indent' => 0,
    'text-transform' => 0,
    'unicode-bidi' => 0,
    'white-space' => 0,
    'word-spacing' => 0,
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
