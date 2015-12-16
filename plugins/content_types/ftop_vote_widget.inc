<?php

$plugin = array(
    'single' => TRUE,
    'title' => t('FootballTop Vote Widget'),
    'description' => t('Voting widget for footballtop.ru.'),
    'category' => t('Node'),
    'render callback' => 'ftop_vote_widget_content_type_render',
    'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Render the custom content type.
 */
function ftop_vote_widget_content_type_render($subtype, $conf, $panel_args, $context) {
 
  // На всякий случай, если вдруг контекст был, плагин включили, а потом контекст убрали.
  if (empty($context) || empty($context->data)) {
    return;
  }
 
  // Забираем нашу ноду из контекста.
  $node= $context->data;
 
  // Создаём блок с формой и передаём ей ноду.
  $block = new stdClass();
  $block->module  = 'ftop_vote';
  $block->content = drupal_get_form('ftop_vote_form', $context->data);
  return $block;
}