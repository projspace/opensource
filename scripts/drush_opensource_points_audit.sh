#!/bin/bash

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

#  $items['osp-audit-badges'] = array(
#    'description' => 'Audit user badges and roles.',
#    'options' => array(
#        'show-failures'   => 'Show info about each failure',
#        'show-debug'      => 'Lots of debug output',
#        'quiet'           => 'Suppress all output',
#        'repair'          => 'Repair any problems which are found',
#        'no-logging'      => 'Do not log to watchdog',
#      ),  
#    'arguments' => array(
#        'limit'   => 'Only process the first X items',
#      ),  
#    'aliases' => array('osp-ab'),
#  ); 

audit_options='--repair --quiet'   # this is probably how we want the task to run on cron
#audit_options='50'                  # (limit argument) debug just by examining a small number of users

$drush_command osp-ab $audit_options

