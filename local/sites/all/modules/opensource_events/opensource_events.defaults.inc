<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _opensource_events_content_default_fields() {
  $fields = array();

  // Exported field: field_event_location
  $fields[] = array(
    'field_name' => 'field_event_location',
    'type_name' => 'event',
    'display_settings' => array(
      'weight' => '36',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_event_location][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Event location (city, state/country)',
      'weight' => '36',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_event_start_date
  $fields[] = array(
    'field_name' => 'field_event_start_date',
    'type_name' => 'event',
    'display_settings' => array(
      'weight' => '34',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'short',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'short',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => 'required',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'blank',
      'default_value_code2' => '',
      'input_format' => 'm/d/Y - H:i',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-0:+3',
      'label_position' => 'above',
      'label' => 'Event start date',
      'weight' => '34',
      'description' => '',
      'type' => 'date_popup',
      'module' => 'date',
    ),
  );

  // Exported field: field_event_submitter_email
  $fields[] = array(
    'field_name' => 'field_event_submitter_email',
    'type_name' => 'event',
    'display_settings' => array(
      'weight' => '32',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'email',
    'required' => '1',
    'multiple' => '0',
    'module' => 'email',
    'active' => '1',
    'widget' => array(
      'size' => '60',
      'default_value' => NULL,
      'default_value_php' => 'global $user;
return array(
  0 => array(\'email\' => $user->mail),
);',
      'label' => 'Your e-mail address',
      'weight' => '32',
      'description' => '',
      'type' => 'email_textfield',
      'module' => 'email',
    ),
  );

  // Exported field: field_event_submitter_name
  $fields[] = array(
    'field_name' => 'field_event_submitter_name',
    'type_name' => 'event',
    'display_settings' => array(
      'weight' => '31',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => NULL,
      'default_value_php' => 'global $user;
return array(
  0 => array(\'value\' => $user->name),
);',
      'label' => 'Your name',
      'weight' => '31',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_event_summary
  $fields[] = array(
    'field_name' => 'field_event_summary',
    'type_name' => 'event',
    'display_settings' => array(
      'weight' => '38',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '3',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_event_summary][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Event Summary',
      'weight' => '38',
      'description' => '<ul><li>Web page addresses and e-mail addresses turn into links automatically.</li>
<li>Allowed HTML tags: &lt;a&gt; &lt;em&gt; &lt;strong&gt; &lt;cite&gt; &lt;code&gt; &lt;ul&gt; &lt;ol&gt; &lt;li&gt; &lt;dl&gt; &lt;dt&gt; &lt;dd&gt; &lt;h3&gt; &lt;h4&gt; &lt;u&gt; </li>
<li>Lines and paragraphs break automatically.</li></ul>',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_event_website
  $fields[] = array(
    'field_name' => 'field_event_website',
    'type_name' => 'event',
    'display_settings' => array(
      'weight' => '37',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '1',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => 'default',
      'rel' => '',
      'class' => '',
      'title' => '',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'none',
    'title_value' => '',
    'enable_tokens' => 0,
    'validate_url' => 1,
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'title' => '',
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Event website',
      'weight' => '37',
      'description' => '',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Translatables
  array(
    t('Event Summary'),
    t('Event location (city, state/country)'),
    t('Event start date'),
    t('Event website'),
    t('Your e-mail address'),
    t('Your name'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_rules_defaults().
 */
function _opensource_events_rules_defaults() {
  return array(
    'rules' => array(
      'opensource_events_1' => array(
        '#type' => 'rule',
        '#set' => 'event_node_insert',
        '#label' => 'Send notification to admin upon event creation',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'opensource_events',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              'type' => array(
                'event' => 'event',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_type',
            '#info' => array(
              'label' => 'Created content is Event',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#info' => array(
              'label' => 'Send a mail to an arbitrary mail address',
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
                '3' => 'to',
              ),
            ),
            '#name' => 'rules_action_mail',
            '#settings' => array(
              'to' => '[node:field_event_submitter_email-formatted]',
              'from' => 'osdc-mail@redhat.com',
              'subject' => 'New event submitted',
              'message' => 'A new event has been submitted. Please visit http://opensource.devel.axelerant.com/moderation-queue/events/all to approve.

Thanks,
All mighty Drupal',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'subject' => array(
                    '0' => ':global',
                  ),
                  'message' => array(
                    '0' => ':global',
                  ),
                  'from' => array(
                    '0' => ':global',
                  ),
                  'to' => array(
                    '0' => 'node',
                    '1' => ':global',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'opensource_events_4' => array(
        '#type' => 'rule',
        '#set' => 'event_workflow_state_changed',
        '#label' => 'Send notification to author of event on event getting published',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'opensource_events',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Check workflow transition from Any state to Published',
              'arguments' => array(
                'old_state' => array(
                  'type' => 'workflow_state',
                  'label' => 'Old workflow state',
                ),
                'new_state' => array(
                  'type' => 'workflow_state',
                  'label' => 'New workflow state',
                ),
              ),
              'module' => 'Workflow',
            ),
            '#name' => 'workflow_check_transition',
            '#settings' => array(
              'from_state' => array(
                'ANY' => 'ANY',
              ),
              'to_state' => array(
                '11' => '11',
              ),
              '#argument map' => array(
                'old_state' => 'old_state',
                'new_state' => 'new_state',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#type' => 'action',
            '#settings' => array(
              'to' => '[node:field_event_submitter_email-formatted]',
              'from' => 'osdc-admin@redhat.com',
              'subject' => 'Your event has been approved',
              'message' => 'We have approved your event, please visit our calendar to view your event listing.

Thanks,
opensource.com team',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'subject' => array(
                    '0' => ':global',
                  ),
                  'message' => array(
                    '0' => ':global',
                  ),
                  'from' => array(
                    '0' => ':global',
                  ),
                  'to' => array(
                    '0' => 'node',
                    '1' => ':global',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_mail',
            '#info' => array(
              'label' => 'Send a mail to an arbitrary mail address',
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
                '3' => 'to',
              ),
            ),
          ),
        ),
        '#version' => 6003,
      ),
      'opensource_events_5' => array(
        '#type' => 'rule',
        '#set' => 'event_node_insert',
        '#label' => 'Send notification to author of event upon event creation',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'opensource_events',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Created content is Event',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'event' => 'event',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'to' => '[node:field_event_submitter_email-formatted]',
              'from' => 'osdc-mail@redhat.com',
              'subject' => 'Thanks for submitting your event',
              'message' => 'Our admins will review your submission and approve your event if it fits within our guidelines. We will contact you if there are any questions.

Thanks,
opensource.com team',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'subject' => array(
                    '0' => ':global',
                  ),
                  'message' => array(
                    '0' => ':global',
                  ),
                  'from' => array(
                    '0' => ':global',
                  ),
                  'to' => array(
                    '0' => 'node',
                    '1' => ':global',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_mail',
            '#info' => array(
              'label' => 'Send a mail to an arbitrary mail address',
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
                '3' => 'to',
              ),
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'opensource_events_2' => array(
        '#type' => 'rule',
        '#set' => 'rules_mark_events_review',
        '#label' => 'Mark events "Review"',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'events',
          'opensource_events' => 'opensource_events',
        ),
        '#status' => 'default',
        '#conditions' => array(),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'module' => 'Workflow',
              'arguments' => array(
                'node' => array(
                  'label' => 'Content',
                  'type' => 'node',
                ),
              ),
              'label' => 'Change workflow state of content to new state',
              'base' => 'rules_core_action_execute',
              'action_name' => 'workflow_select_given_state_action',
              'configurable' => TRUE,
            ),
            '#name' => 'rules_core_workflow_select_given_state_action',
            '#settings' => array(
              'target_sid' => '6',
              'state_name' => 'Review',
              'force' => 0,
              'workflow_comment' => 'Action set %title to %state.',
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'opensource_events_3' => array(
        '#type' => 'rule',
        '#set' => 'rules_mark_events_published',
        '#label' => 'Mark events "Published"',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'events',
          'opensource_events' => 'opensource_events',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Content is Event',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'event' => 'event',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'target_sid' => '11',
              'state_name' => 'Published',
              'force' => 0,
              'workflow_comment' => 'Action set %title to %state.',
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_core_workflow_select_given_state_action',
            '#info' => array(
              'module' => 'Workflow',
              'arguments' => array(
                'node' => array(
                  'label' => 'Content',
                  'type' => 'node',
                ),
              ),
              'label' => 'Change workflow state of content to new state',
              'base' => 'rules_core_action_execute',
              'action_name' => 'workflow_select_given_state_action',
              'configurable' => TRUE,
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'opensource_events_6' => array(
        '#type' => 'rule',
        '#set' => 'rules_mark_events_published',
        '#label' => 'Mark events "Published"',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'events',
          'opensource_events' => 'opensource_events',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Content is Event',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'event' => 'event',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'target_sid' => '11',
              'state_name' => 'Published',
              'force' => 0,
              'workflow_comment' => 'Action set %title to %state.',
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_core_workflow_select_given_state_action',
            '#info' => array(
              'module' => 'Workflow',
              'arguments' => array(
                'node' => array(
                  'label' => 'Content',
                  'type' => 'node',
                ),
              ),
              'label' => 'Change workflow state of content to new state',
              'base' => 'rules_core_action_execute',
              'action_name' => 'workflow_select_given_state_action',
              'configurable' => TRUE,
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'opensource_events_7' => array(
        '#type' => 'rule',
        '#set' => 'rules_mark_events_review',
        '#label' => 'Mark events "Review"',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'events',
          'opensource_events' => 'opensource_events',
        ),
        '#status' => 'default',
        '#conditions' => array(),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'module' => 'Workflow',
              'arguments' => array(
                'node' => array(
                  'label' => 'Content',
                  'type' => 'node',
                ),
              ),
              'label' => 'Change workflow state of content to new state',
              'base' => 'rules_core_action_execute',
              'action_name' => 'workflow_select_given_state_action',
              'configurable' => TRUE,
            ),
            '#name' => 'rules_core_workflow_select_given_state_action',
            '#settings' => array(
              'target_sid' => '6',
              'state_name' => 'Review',
              'force' => 0,
              'workflow_comment' => 'Action set %title to %state.',
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'opensource_events_8' => array(
        '#type' => 'rule',
        '#set' => 'event_workflow_state_changed',
        '#label' => 'Award a registered user 10 points after an event the submitted is published',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'opensource_events',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Updated content is Event',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'event' => 'event',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
          '1' => array(
            '#type' => 'condition',
            '#settings' => array(
              'from_state' => array(
                'ANY' => 'ANY',
              ),
              'to_state' => array(
                '11' => '11',
              ),
              '#argument map' => array(
                'old_state' => 'old_state',
                'new_state' => 'new_state',
              ),
            ),
            '#name' => 'workflow_check_transition',
            '#info' => array(
              'label' => 'Check workflow transition from Any state to Published',
              'arguments' => array(
                'old_state' => array(
                  'type' => 'workflow_state',
                  'label' => 'Old workflow state',
                ),
                'new_state' => array(
                  'type' => 'workflow_state',
                  'label' => 'New workflow state',
                ),
              ),
              'module' => 'Workflow',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Grant points to a user',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User',
                ),
              ),
              'module' => 'Userpoints',
              'eval input' => array(
                '0' => 'points',
                '1' => 'entity_id',
              ),
            ),
            '#name' => 'userpoints_action_grant_points',
            '#settings' => array(
              'points' => '10',
              'description' => '',
              'operation' => '',
              'entity_type' => '',
              'entity_id' => '',
              'tid' => '',
              '#argument map' => array(
                'user' => 'user',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'points' => array(
                    '0' => ':global',
                  ),
                  'entity_id' => array(
                    '0' => ':global',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
    ),
  );
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _opensource_events_user_default_permissions() {
  $permissions = array();

  // Exported permission: create event content
  $permissions[] = array(
    'name' => 'create event content',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  return $permissions;
}
