<?php

/**
 * @file
 * Definition of views_handler_argument_aggregator_iid.
 */

/**
 * Argument handler to accept an aggregator item id.
 *
 * @ingroup views_argument_handlers
 */
class views_handler_argument_aggregator_iid extends views_handler_argument_numeric {

  /**
   * Override the behavior of title(). Get the title of the category.
   */
  public function title_query() {
    $titles = array();

    $result = db_select('aggregator_item', 'ai')
      ->condition('iid', $this->value, 'IN')
      ->fields('ai', array('title'))
      ->execute();
    foreach ($result as $term) {
      $titles[] = check_plain($term->title);
    }
    return $titles;
  }

}
