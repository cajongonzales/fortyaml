#include <stdio.h>
#include <stdlib.h> // atoi, malloc
#include <string.h> //strcpy
#include <yaml.h>
#include "Dictionary.hpp"

extern "C" {

int yamlEventReader(char *filePath)
{
  printf("yamlEventReader %s\n", filePath);

// LibYAML 

  FILE *fh = fopen(filePath, "r");
  yaml_parser_t parser;
  yaml_event_t  event;   /* New variable */
  
    /* Initialize parser */
  if(!yaml_parser_initialize(&parser))
    fputs("Failed to initialize parser!\n", stderr);
  if(fh == NULL)
    printf("Failed to open file %s!\n", filePath);

  /* Set input file */
  yaml_parser_set_input_file(&parser, fh);

  /* Create dictionary */
  Dictionary d;
  Dictionary* curr_ptr = nullptr;
  
  bool reading_key = false;
  bool reading_sequence = false;

  /* START new code */
  int level=0;
  do {
    if (!yaml_parser_parse(&parser, &event)) {
       printf("Parser error %d\n", parser.error);
       exit(EXIT_FAILURE);
    }

    switch(event.type)
    { 
    case YAML_NO_EVENT: puts("No event!"); break;
    /* Stream start/end */
    case YAML_STREAM_START_EVENT: 
      puts("STREAM START");
      ++level;
      break;
    case YAML_STREAM_END_EVENT:   
      puts("STREAM END");
      --level; 
      break;
    /* Block delimeters */
    case YAML_DOCUMENT_START_EVENT: 
      puts("<b>Start Document</b>"); 
      ++level; 
      break;
    case YAML_DOCUMENT_END_EVENT:   
      puts("<b>End Document</b>");   
      --level; 
      break;
    case YAML_SEQUENCE_START_EVENT: 
      puts("<b>Start Sequence</b>"); 
      ++level;
      curr_ptr = curr_ptr->get_last_child();
      reading_sequence = true;
      break;
    case YAML_SEQUENCE_END_EVENT:   
      puts("<b>End Sequence</b>");   
      --level;
      curr_ptr = curr_ptr->get_parent();
      reading_sequence = false;
      reading_key = true;
      break;
    case YAML_MAPPING_START_EVENT:  
      puts("<b>Start Mapping</b>");  
      ++level;
      // The first mapping sets the current pointer to the dictionary root
      if(!curr_ptr) curr_ptr = &d;
      else curr_ptr = curr_ptr->get_last_child();
      reading_key = true;
      break;
    case YAML_MAPPING_END_EVENT:    
      puts("<b>End Mapping</b>");    
      --level;
      curr_ptr = curr_ptr->get_parent();
      break;
    /* Data */
    case YAML_ALIAS_EVENT:
      printf("Got alias (anchor %s)\n", event.data.alias.anchor); 
      break;
      
    case YAML_SCALAR_EVENT:
      printf("Got a value at level %d (value %s)\n", level, event.data.scalar.value);

      // value is actually an unsigned char*, so we are assuming ASCII in this cast here
      std::string key(reinterpret_cast<const char*>(event.data.scalar.value));
      if(reading_sequence || reading_key) {
        curr_ptr->set_key(key);
        reading_key = false;
      } else {
        Dictionary* down_ptr = curr_ptr->get_last_child();
        down_ptr->set_key(key);
        reading_key = true;
      }
      break;
    }

    if(event.type != YAML_STREAM_END_EVENT)
      yaml_event_delete(&event);
  } while(event.type != YAML_STREAM_END_EVENT);
  yaml_event_delete(&event);
  /* END new code */

  d.print();

  /* Cleanup */
  yaml_parser_delete(&parser);
//  delete_all();
  fclose(fh);
  return 0;
}

} // end extern C