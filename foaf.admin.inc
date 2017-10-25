<?php
/**
 * @file
 * Administrative page callbacks for the FOAF module.
 */
function foaf_settings_form() {
  $form['foaf_data_policies'] = array(
    '#type' => 'textarea',
    '#title' => t('Data policies text'),
    '#default_value' => variable_get('foaf_data_policies', ''),
    //'#required' => TRUE,
  );
  return system_settings_form($form);
}