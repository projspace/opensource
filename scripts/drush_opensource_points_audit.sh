#!/bin/bash

# bash wrapper script to run drush osp-audit-badges command
#   takes an optional argument dev|prod to specify which environment to run the command against
#   (defaults to dev unless 'prod' is specified
audit_options='--repair --quiet'   # this is probably how we want the task to run on cron
#audit_options='50'                # (limit argument) debug by examining a small number of users (and doing no repair)

drush='/usr/bin/drush'

# todo: pick these up from the alias definitions rather than duplicating it here
config_prod='--uri=dev.opensource.com --root=/mnt/www/aradev/docroot'
config_dev='--uri=www.opensource.com --root=/mnt/www/ara/docroot'

# default to dev
drush_command="$drush $config_dev"
if [ -z "$1" ]; then
  if [ "$1" == 'prod' ]; then
    drush_command="$drush $config_prod"
  fi
fi

$drush_command osp-ab $audit_options

