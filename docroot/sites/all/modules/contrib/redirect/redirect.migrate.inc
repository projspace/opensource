<?php
/**
 * @file
 * Migrate support for Redirect module.
 */

/**
 * Redirect as main destination for migrate.
 */
class MigrateDestinationRedirect extends MigrateDestinationEntity {
  /**
   * Constructor.
   */
  public function __construct() {
    parent::__construct('redirect', 'redirect');
  }

  /**
   * Return the schema for the key to be used in destination.
   */
  static public function getKeySchema() {
    return array(
      'rid'  => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
        'description' => 'Primary Key: Unique redirect ID.',
      ),
    );
  }

  /**
   * Return string representation for the object.
   */
  public function __toString() {
    return t('Redirects');
  }

  /**
   * Returns a list of fields available to be mapped for a flag.
   *
   * @return array
   *   Keys: machine names of the fields (to be passed to addFieldMapping)
   *   Values: Human-friendly descriptions of the fields.
   */
  public function fields() {
    return array(
      'rid' => 'Primary Key: Unique redirect ID.',
      'hash' => 'A unique hash based on source, source_options, and language.',
      'type' => "The redirect type; if value is 'redirect' it is a normal redirect handled by the module.",
      'uid' => 'The {users}.uid of the user who created the redirect.',
      'source' => 'The source path to redirect from.',
      'source_options' => 'A serialized array of source options.',
      'redirect' => 'The destination path to redirect to.',
      'redirect_options' => 'A serialized array of redirect options.',
      'language' => 'The language this redirect is for; if blank, the alias will be used for unknown languages.',
      'status_code' => 'The HTTP status code to use for the redirect.',
      'count' => 'The number of times the redirect has been used.',
      'access' => 'The timestamp of when the redirect was last accessed.'
    );
  }

  /**
   * Validate a redirect.
   *
   * We need to check if a redirect already exists otherwise if we call
   * redirect_save in complete we get an db error due to duplicate entries.
   *
   * This function is similar to the validate function in the redirect module
   * but the feedback is handled via the Migrate saveMessage functionality.
   */
  protected function redirectValidate($redirect) {
    $redirect = (object) $redirect;

    // check that there there are no redirect loops
    $migration = Migration::currentMigration();
    if (url($redirect->source) == url($redirect->redirect)) {
      $migration->saveMessage(t('Redirect to self (!redirect) ignored',
                              array('!redirect' => $redirect->redirect)),
                  MigrationBase::MESSAGE_INFORMATIONAL);
      return FALSE;
    }

    redirect_hash($redirect);
    if ($existing = redirect_load_by_hash($redirect->hash)) {
      if ($redirect->rid != $existing->rid) {
        $migration->saveMessage(t('The source path is already being redirected.'),
          MigrationBase::MESSAGE_INFORMATIONAL);
        return FALSE;
      }
    }

    return TRUE;
  }

  /**
   * Import a single row.
   *
   * @param $redirect
   *   Redirect object to build. Prefilled with any fields mapped in the Migration.
   * @param $row
   *   Raw source data object - passed through to prepare/complete handlers.
   * @return array
   *   Array of key fields of the object that was saved if successful. FALSE on
   *   failure.
   */
  public function import(stdClass $redirect, stdClass $row) {
    // Updating previously-migrated content
    if (isset($row->migrate_map_destid1)) {
      $redirect->rid = $row->migrate_map_destid1;
    }

    // Invoke migration prepare handlers
    $this->prepare($redirect, $row);

    migrate_instrument_start('redirect_save');

    // Check to see if this is a new redirect.
    $update = FALSE;
    if (isset($redirect->rid)) {
      $update = TRUE;
    }
    // Prepare the redirect.
    redirect_object_prepare($redirect);
    $parsed = redirect_parse_url($redirect->source);
    $redirect->source = isset($parsed['path']) ? $parsed['path'] : '';
    if (!empty($parsed['query'])) {
      $redirect->source_options['query'] = $parsed['query'];
    }
    if ($this->redirectValidate($redirect)) {
      redirect_save($redirect);
    }
    else {
      throw new MigrateException('The redirect was not valid.');
    }
    migrate_instrument_stop('redirect_save');

    // Return the new id or FALSE on failure.
    if (!empty($redirect->rid)) {
      // Increment the count if the save succeeded.
      if ($update) {
        $this->numUpdated++;
      }
      else {
        $this->numCreated++;
      }
      // Return the primary key to the mapping table.
      $return = array($redirect->rid);
    }
    else {
      $return = FALSE;
    }

    // Invoke migration complete handlers.
    $this->complete($redirect, $row);

    return $return;
  }

  /**
   * Delete redirects.
   *
   * @param array $id
   *   IDs to be deleted.
   */
  public function bulkRollback(array $rids) {
    migrate_instrument_start('redirect_delete_multiple');
    $this->prepareRollback($rids);
    redirect_delete_multiple($rids);
    $this->completeRollback($rids);
    migrate_instrument_stop('redirect_delete_multiple');
  }

  /**
   * Implementation of MigrateDestination::prepare().
   */
  public function prepare($redirect, stdClass $row) {
    // We do nothing here but allow child classes to act.
    $migration = Migration::currentMigration();
    $redirect->migrate = array(
      'machineName' => $migration->getMachineName(),
    );

    // Call any general handlers.
    migrate_handler_invoke_all('redirect', 'prepare', $redirect, $row);
    // Then call any prepare handler for this specific Migration.
    if (method_exists($migration, 'prepare')) {
      $migration->prepare($redirect, $row);
    }
  }

  /**
   * Implementation of MigrateDestination::complete().
   */
  public function complete($redirect, stdClass $row) {
    // We do nothing here but allow child classes to act.
    $migration = Migration::currentMigration();
    $redirect->migrate = array(
      'machineName' => $migration->getMachineName(),
    );
    // Call any general handlers.
    migrate_handler_invoke_all('redirect', 'complete', $redirect, $row);
    // Then call any complete handler for this specific Migration.
    if (method_exists($migration, 'complete')) {
      $migration->complete($redirect, $row);
    }
  }

  /**
   * Implementation of MigrateDestination::prepareRollback().
   */
  public function prepareRollback($rid) {
    // We do nothing here but allow child classes to act.
    $migration = Migration::currentMigration();
    // Call any general handlers.
    migrate_handler_invoke_all('redirect', 'prepareRollback', $rid);
    // Then call any complete handler for this specific Migration.
    if (method_exists($migration, 'prepareRollback')) {
      $migration->prepareRollback($rid);
    }
  }

  /**
   * Implementation of MigrateDestination::completeRollback().
   */
  public function completeRollback($rid) {
    // We do nothing here but allow child classes to act.
    $migration = Migration::currentMigration();
    // Call any general handlers.
    migrate_handler_invoke_all('redirect', 'completeRollback', $rid);
    // Then call any complete handler for this specific Migration.
    if (method_exists($migration, 'completeRollback')) {
      $migration->completeRollback($rid);
    }
  }
}

/**
 * Implements hook_migrate_api().
 */
function redirect_migrate_api() {
  $api = array(
    'api' => 2,
  );
  return $api;
}
