<?php

/**
 * Form defination
 */
function loginlogout_settings() {
  $form = array();

  $form['loginlogout_urls'] = array(
    '#type' => 'textarea',
    '#title' => t('Urls'),
    '#default_value' => variable_get('loginlogout_urls', LOGINLOGOUT_DEFAULT_URLS),
    '#description' => t('One per line, Lists URLS that should have destination added to them (or remove URLS that should not)'),
  );

  return system_settings_form($form);
}
