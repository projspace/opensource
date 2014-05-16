<?php
/**
 * @file
 * os_mollom.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function os_mollom_defaultconfig_features() {
  return array(
    'os_mollom' => array(
      'default_mollom_form' => 'default_mollom_form',
    ),
  );
}

/**
 * Implements hook_defaultconfig_default_mollom_form().
 */
function os_mollom_defaultconfig_default_mollom_form() {
  $export = array();

  $mollom_form = new stdClass();
  $mollom_form->disabled = FALSE; /* Edit this to true to make a default mollom_form disabled initially */
  $mollom_form->api_version = 1;
  $mollom_form->form_id = 'comment_node_article_form';
  $mollom_form->entity = 'comment';
  $mollom_form->bundle = 'comment_node_article';
  $mollom_form->mode = 2;
  $mollom_form->checks = array(
    0 => 'spam',
  );
  $mollom_form->unsure = 'captcha';
  $mollom_form->discard = FALSE;
  $mollom_form->moderation = TRUE;
  $mollom_form->enabled_fields = array(
    0 => 'subject',
    1 => 'comment_body',
  );
  $mollom_form->strictness = 'normal';
  $mollom_form->module = 'comment';
  $export['comment_node_article_form'] = $mollom_form;

  $mollom_form = new stdClass();
  $mollom_form->disabled = FALSE; /* Edit this to true to make a default mollom_form disabled initially */
  $mollom_form->api_version = 1;
  $mollom_form->form_id = 'comment_node_poll_form';
  $mollom_form->entity = 'comment';
  $mollom_form->bundle = 'comment_node_poll';
  $mollom_form->mode = 2;
  $mollom_form->checks = array(
    0 => 'spam',
  );
  $mollom_form->unsure = 'captcha';
  $mollom_form->discard = FALSE;
  $mollom_form->moderation = TRUE;
  $mollom_form->enabled_fields = array(
    0 => 'subject',
    1 => 'comment_body',
  );
  $mollom_form->strictness = 'normal';
  $mollom_form->module = 'comment';
  $export['comment_node_poll_form'] = $mollom_form;

  $mollom_form = new stdClass();
  $mollom_form->disabled = FALSE; /* Edit this to true to make a default mollom_form disabled initially */
  $mollom_form->api_version = 1;
  $mollom_form->form_id = 'contact_personal_form';
  $mollom_form->entity = '';
  $mollom_form->bundle = '';
  $mollom_form->mode = 2;
  $mollom_form->checks = array(
    0 => 'spam',
  );
  $mollom_form->unsure = 'captcha';
  $mollom_form->discard = TRUE;
  $mollom_form->moderation = FALSE;
  $mollom_form->enabled_fields = array(
    0 => 'subject',
    1 => 'message',
  );
  $mollom_form->strictness = 'normal';
  $mollom_form->module = 'contact';
  $export['contact_personal_form'] = $mollom_form;

  $mollom_form = new stdClass();
  $mollom_form->disabled = FALSE; /* Edit this to true to make a default mollom_form disabled initially */
  $mollom_form->api_version = 1;
  $mollom_form->form_id = 'contact_site_form';
  $mollom_form->entity = '';
  $mollom_form->bundle = '';
  $mollom_form->mode = 2;
  $mollom_form->checks = array(
    0 => 'spam',
  );
  $mollom_form->unsure = 'captcha';
  $mollom_form->discard = TRUE;
  $mollom_form->moderation = FALSE;
  $mollom_form->enabled_fields = array(
    0 => 'subject',
    1 => 'message',
  );
  $mollom_form->strictness = 'normal';
  $mollom_form->module = 'contact';
  $export['contact_site_form'] = $mollom_form;

  $mollom_form = new stdClass();
  $mollom_form->disabled = FALSE; /* Edit this to true to make a default mollom_form disabled initially */
  $mollom_form->api_version = 1;
  $mollom_form->form_id = 'user_register_form';
  $mollom_form->entity = 'user';
  $mollom_form->bundle = 'user';
  $mollom_form->mode = 2;
  $mollom_form->checks = array(
    0 => 'spam',
  );
  $mollom_form->unsure = 'captcha';
  $mollom_form->discard = TRUE;
  $mollom_form->moderation = TRUE;
  $mollom_form->enabled_fields = array(
    0 => 'field_display_name',
  );
  $mollom_form->strictness = 'normal';
  $mollom_form->module = 'user';
  $export['user_register_form'] = $mollom_form;

  return $export;
}
