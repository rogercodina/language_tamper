<?php

$plugin = array(
  'form'     => 'language_tamper_form',
  'callback' => 'language_tamper_callback',
  'name'     => 'Language replace tamper',
  'multi'    => 'direct',
  'category' => 'Other',
);

function language_tamper_form($importer, $element_key, $settings) {
  $form = array();

  $form['instructions'] = array(
    '#markup' => t('Expected input: a string with a language name: Español, English, Català')
  );

  return $form;
}

function language_tamper_callback($source, $item_key, $element_key, &$field, $settings) {
  if (!is_array($field)) {
    $field = array($field);
  }

  $trad = array(
    "Español" => "es",
    "English" => "en",
    "Català" => "ca",
    "Deutsch" => "de",
    "Français" => "fr"
  );

  $out = array();

  foreach ($field as $f) {
    if(is_array($f)) {
      foreach ($f as $f_values) {
        foreach ($trad as $search => $replace) {
          $f_values = str_replace($search, $replace, $f_values);
        }
        $out[] = $f_values;
      }
    } else {
      foreach ($trad as $search => $replace) {
        $f = str_replace($search, $replace, $f);
      }
      $out[] = $f;
    }
  }
  $field = $out;
}
