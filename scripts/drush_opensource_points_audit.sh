#!/bin/bash

# bash wrapper script to run drush osp-audit-badges command
#   takes an optional argument dev|prod to specify which environment to run the command against
#   (defaults to dev unless 'prod' is specified)
audit_options='--repair --quiet'   # this is probably how we want the task to run on cron
#audit_options='50'                # (limit argument) debug by examining a small number of users (and doing no repair)

drush='/usr/bin/drush'

# todo: pick these up from the alias definitions rather than duplicating it here
config_dev='--uri=dev.opensource.com --root=/mnt/www/aradev/docroot'
config_prod='--uri=www.opensource.com --root=/mnt/www/ara/docroot'

# default to dev
drush_command="$drush $config_dev"
if [ -n "$1" ]; then
  if [ "$1" == 'prod' ]; then
    drush_command="$drush $config_prod"
  fi
fi

# option to run without --repair for debugging
if [ -n "$2" ]; then
  if [ "$2" == 'debug' ]; then
    audit_options=''
    echo "about to run: $drush_command osp-ab $audit_options"
    echo "\$1 was $1"
    echo "\$2 was $2"
  fi
fi

$drush_command osp-ab $audit_options

