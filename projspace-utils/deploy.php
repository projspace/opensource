<?php
$mirrordir='/home/<project-name>/www/dev';
$gitdir=$mirrordir."/.git";

$json= file_get_contents('php://input');
#error_log($json);
$jsarr=json_decode($json,true);
#error_log(print_r($jsarr,true));
$branch=$jsarr["ref"];
if($branch=='refs/heads/master'){
$cmd="git --work-tree=$mirrordir --git-dir=$gitdir pull";
#error_log($cmd);
exec($cmd);
} 
