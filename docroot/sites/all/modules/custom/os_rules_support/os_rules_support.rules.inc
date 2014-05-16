<?php
/**
 * @file
 * Provides rules support to add different events, conditions and event
 * properties for use in rules.
 */

/**
 * Implements hook_rules_event_info().
 */
function os_rules_support_rules_event_info() {
  return array(
    'os_rules_support_poll_vote' => array(
      'label' => t('User casts a poll vote'),
      'help' => t('Triggers when users are casting votes on polls.'),
      'group' => t('OpenSource Rules Support'),
      'variables' => array(
        'poll' => array(
          'type' => 'node',
          'label' => t('Poll node'),
          'description' => t('Voted poll node.'),
        ),
      ),
    ),
  );
}
