#include <stdio.h>
#include <stdlib.h> // atoi, malloc
#include <string.h> //strcpy
#include <yaml.h>
//#include "uthash.h"
int yamlEventReader(char *filePath)
{
  struct my_struct{
    int component_number; // only if Local factors are to be applied
    char component_type[20]; //required
    char category[100]; //Global or Local
    int level; // how deep in the tree are you
    double value;
    char key[50];
    char system[50]; //Named system to apply factors on - if local then null
    char tree[100]; // try and capture the levels of the tree
  };

// LibYAML 

  FILE *fh = fopen(filePath, "r");
  yaml_parser_t parser;
  yaml_event_t  event;   /* New variable */
  struct my_struct yamlData;
    /* Initialize parser */
  if(!yaml_parser_initialize(&parser))
    fputs("Failed to initialize parser!\n", stderr);
  if(fh == NULL)
    fputs("Failed to open file!\n", stderr);

  /* Set input file */
  yaml_parser_set_input_file(&parser, fh);

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
      break;
    case YAML_SEQUENCE_END_EVENT:   
      puts("<b>End Sequence</b>");   
      --level;
      break;
    case YAML_MAPPING_START_EVENT:  
      puts("<b>Start Mapping</b>");  
      ++level;
      break;
    case YAML_MAPPING_END_EVENT:    
      puts("<b>End Mapping</b>");    
      --level;
      break;
    /* Data */
    case YAML_ALIAS_EVENT:
      printf("Got alias (anchor %s)\n", event.data.alias.anchor); 
      break;
      
    case YAML_SCALAR_EVENT:
      printf("Got a value at level %d (value %s)\n", level, event.data.scalar.value);
      yamlData.level=level;
       
      break;
    }
    if(event.type != YAML_STREAM_END_EVENT)
      yaml_event_delete(&event);
  } while(event.type != YAML_STREAM_END_EVENT);
  yaml_event_delete(&event);
  /* END new code */

  /* Cleanup */
  yaml_parser_delete(&parser);
//  delete_all();
  fclose(fh);
  return 0;
}
