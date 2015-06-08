<?php
/**
 * @file
 * idi_interstitial.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function idi_interstitial_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create any interstitial bean'.
  $permissions['create any interstitial bean'] = array(
    'name' => 'create any interstitial bean',
    'roles' => array(
      'ADMINISTRATOR' => 'ADMINISTRATOR',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any interstitial bean'.
  $permissions['delete any interstitial bean'] = array(
    'name' => 'delete any interstitial bean',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any interstitial bean'.
  $permissions['edit any interstitial bean'] = array(
    'name' => 'edit any interstitial bean',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any interstitial bean'.
  $permissions['view any interstitial bean'] = array(
    'name' => 'view any interstitial bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
