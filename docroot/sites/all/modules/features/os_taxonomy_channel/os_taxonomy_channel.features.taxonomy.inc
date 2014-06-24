<?php
/**
 * @file
 * os_taxonomy_channel.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function os_taxonomy_channel_taxonomy_default_vocabularies() {
  return array(
    'channel' => array(
      'name' => 'Channel',
      'machine_name' => 'channel',
      'description' => 'A Channel is a section of the site such as Business, Education, etc.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
