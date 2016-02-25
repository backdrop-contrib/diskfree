<?php

/**
 * @file
 * Disfree admin settings.
 */

/**
 * Settings form to configure utility paths and alerts.
 */
function diskfree_admin_settings() {
  $config = config('diskfree.settings');
  $form = array();
  $form['diskfree_alert_threshold'] = array(
    '#type' => 'textfield',
    '#title' => t('Alert threshold percent'),
    '#description' => t('An integer between 0 and 100 which is the minimum disk space to trigger an alert of low disk space. A value of 100 effectively disables alerts.'),
    '#default_value' => $config->get('alert_threshold'),
  );
  $form['diskfree_alert_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Alert email address'),
    '#default_value' => $config->get('alert_email', config_get('system.core', 'site_mail')),
  );
  $form['diskfree_alert_email_freq'] = array(
    '#type' => 'select',
    '#title' => t('Alert email sending frequency'),
    '#description' => t('How often to send email alerts per partition.'),
    '#options' => array(
      '300' => '5 minutes',
      '600' => '10 minutes',
      '900' => '15 minutes',
      '1800' => '30 minutes',
      '3600' => '1 hour',
      '7200' => '2 hours',
      '14400' => '4 hours',
      '28800' => '8 hours',
      '86400' => '1 day',
    ),
    '#default_value' => $config->get('alert_email_freq'),
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Implements hook_validate().
 */
function diskfree_admin_settings_validate($form, &$form_state) {
  $threshold = $form_state['values']['diskfree_alert_threshold'];
  if (!is_numeric($threshold) || $threshold < 0 || $threshold > 100) {
    form_set_error('diskfree_alert_threshold', t('Alert threshold must be an integer between 0 and 100, inclusive.'));
  }

  $mail = $form_state['values']['diskfree_alert_email'];
  if ($mail != '' && !valid_email_address($mail)) {
    form_set_error('diskfree_alert_email', t('The e-mail address %mail is not valid.', array('%mail' => $mail)));
  }
}

/**
 * Implements hook_submit().
 */
function diskfree_admin_settings_submit($form, &$form_state) {
  $config = config('diskfree.settings');
  $config->set('alert_threshold', $form_state['values']['diskfree_alert_threshold']);
  $config->set('alert_email', $form_state['values']['diskfree_alert_email']);
  $config->set('alert_email_freq', $form_state['values']['diskfree_alert_email_freq']);
  $config->save();
}
