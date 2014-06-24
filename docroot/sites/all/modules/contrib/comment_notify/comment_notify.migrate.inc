<?php

/**
 * @file
 * Migration support for the Comment Notify module.
 */

/**
 * Field handler.
 */
class CommentNotifyMigrationHandler extends MigrateDestinationHandler {
  public function __construct() {
    $this->registerTypes(array('comment'));
  }

  /**
   * Make the destination field visible.
   */
  public function fields() {
    return array(
      'notify' => t('Comment Notify: Whether to send notifications for this comment'),
      'notified' => t('Comment Notify: Whether notifications have been sent for this comment'),
      'notify_hash' => t('Comment Notify: Hash representing this notification'),
    );
  }

  /**
   * Implements MigrateDestinationHandler::prepare().
   *
   * @param $comment
   *  The comment object being prepared for saving.
   * @param $row
   *  Raw source data for the migration - ignored.
   */
  public function prepare($comment, $row) {
    // By default, set notifications off
    if (!isset($comment->notify)) {
      $comment->notify = 0;
    }
    if (!isset($comment->notify_type)) {
      $comment->notify_type = 1;
    }
  }

  /**
   * Implements MigrateDestinationHandler::complete().
   *
   * @param $comment
   *  The comment object taht was just saved.
   * @param $row
   *  Raw source data for the migration - ignored.
   */
  public function complete($comment, $row) {
    if (!isset($comment->notified) || $comment->notified) {
      comment_notify_mark_comment_as_notified($comment);
    }
  }
}

/**
 * Field handler.
 */
class CommentNotifyUserSettingsMigrationHandler extends MigrateDestinationHandler {
  public function __construct() {
    $this->registerTypes(array('user'));
  }

  /**
   * Make the destination field visible.
   */
  public function fields() {
    return array(
      'node_notify' => t('Comment Notify: An integer indicating the default type of subscription: 0 means not subscribed, 1 means subscribed to all comments, and 2 means only subscribed to replies of this comment.'),
      'comment_notify' => t('Comment Notify: An integer indicating the default type of subscription: 0 means not subscribed, 1 means subscribed to all comments, and 2 means only subscribed to replies of this comment.'),
    );
  }

  /**
   * Implements MigrateDestinationHandler::prepare().
   *
   * @param $user
   *  The user object being prepared for saving.
   * @param $row
   *  Raw source data for the migration - ignored.
   */
  public function prepare($user, $row) {
    // By default, set notifications off
    if (!isset($user->node_notify)) {
      $user->node_notify = 0;
    }
    if (!isset($user->comment_notify)) {
      $user->comment_notify = 0;
    }
  }

  /**
   * Implements MigrateDestinationHandler::complete().
   *
   * @param $user
   *  The user object that was just saved.
   * @param $row
   *  Raw source data for the migration - ignored.
   */
  public function complete($user, $row) {
    comment_notify_set_user_notification_setting($user->uid, $user->node_notify, $user->comment_notify);
  }
}

/*
 * Implementats hook_migrate_api().
 */
function comment_notify_migrate_api() {
  $api = array(
    'api' => 2,
    'destination handlers' => array(
      'CommentNotifyMigrationHandler',
      'CommentNotifyUserSettingsMigrationHandler',
    ),
  );
  return $api;
}
