<?php
/**
 * @file
 * idi_interstitial.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function idi_interstitial_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-interstitial-field_external'
  $field_instances['bean-interstitial-field_external'] = array(
    'bundle' => 'interstitial',
    'default_value' => array(
      0 => array(
        'title' => 'Ok',
        'url' => '#',
      ),
    ),
    'deleted' => 0,
    'description' => 'External link usually leaving [site:name].',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_external',
    'label' => 'External',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 0,
      'attributes' => array(
        'class' => 'external',
        'configurable_class' => 1,
        'configurable_title' => 1,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 255,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'bean-interstitial-field_internal'
  $field_instances['bean-interstitial-field_internal'] = array(
    'bundle' => 'interstitial',
    'default_value' => array(
      0 => array(
        'title' => 'Cancel',
        'url' => '#',
      ),
    ),
    'deleted' => 0,
    'description' => 'A link usually staying on the internal page of [site:name]. ',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_internal',
    'label' => 'Internal',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 0,
      'attributes' => array(
        'class' => 'internal',
        'configurable_class' => 1,
        'configurable_title' => 1,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 255,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'bean-interstitial-field_interstitial_copy'
  $field_instances['bean-interstitial-field_interstitial_copy'] = array(
    'bundle' => 'interstitial',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Copy explaining the interstitial. ',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_interstitial_copy',
    'label' => 'Interstitial Copy',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 10,
      ),
      'type' => 'text_textarea',
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('A link usually staying on the internal page of [site:name]. ');
  t('Copy explaining the interstitial. ');
  t('External');
  t('External link usually leaving [site:name].');
  t('Internal');
  t('Interstitial Copy');

  return $field_instances;
}
