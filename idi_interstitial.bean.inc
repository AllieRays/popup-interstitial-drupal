<?php
/**
 * @file
 * idi_interstitial.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function idi_interstitial_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'interstitial';
  $bean_type->label = 'interstitial';
  $bean_type->options = '';
  $bean_type->description = 'popup disclaimer or interstitial usually linking to a different site.';
  $export['interstitial'] = $bean_type;

  return $export;
}

