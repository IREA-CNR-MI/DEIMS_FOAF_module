<?php
/**
 * @file
 * Page callbacks for the FOAF module.
 */
/**
 * Output a node as FOAF.
 *
 * Sets the content header for xml, renders the FOAF, and returns nothing in
 * order to not have render actions take place on the iso.
 * When nothing is returned from a page callback Drupal will not render anything
 * and still call the rest of the proper hooks including necessary exit hooks.
 * For a similar usage example see:
 * @see http://api.drupal.org/api/drupal/modules%21node%21node.module/function/node_feed/7
 */
function foaf_output_node($node) {
  if ($node->type != 'data_set') {
    return MENU_NOT_FOUND;
  }
  try {
    // Get the FOAF as a string and output it.
    $dataset = new FoafDataSet($node);
    $foaf = $dataset->getFOAF();
	drupal_add_http_header('Content-Type', 'application/xml');
    print $foaf;
  }
  catch (Exception $exception) {
    watchdog_exception('foaf', $exception);
    return MENU_NOT_FOUND;
  }
}