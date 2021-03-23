#include <stdio.h>
#include <stdlib.h> // atoi, malloc
#include <string.h> //strcpy
#include <yaml.h>
#include "uthash.h"
int yamlEventReader(char *filePath)
{
// Hash Table Methods
  struct my_struct {
    int id;
    char name[20];
    char event_type[20];
    UT_hash_handle hh;
  };
  struct my_struct *yaml_doc = NULL;
  void add_event(int event_id, char *event_type)
  {
    struct my_struct *s;
    HASH_FIND_INT(yaml_doc, &event_id, s);
    if (s==NULL) 
    {
      s = (struct my_struct*)malloc(sizeof(struct my_struct));
      s->id = event_id;
      HASH_ADD_INT(yaml_doc, id, s);
    }
    strcpy(s->event_type, event_type);
  }
  void delete_all() {
    struct my_struct *current_doc, *tmp;
    HASH_ITER(hh, yaml_doc, current_doc, tmp) {
      HASH_DEL(yaml_doc, current_doc);  /* delete it (users advances to next) */
      free(current_doc);             /* free it */
    }
  }

// LibYAML 

  FILE *fh = fopen(filePath, "r");
  yaml_parser_t parser;
  yaml_event_t  event;   /* New variable */
    /* Initialize parser */
  if(!yaml_parser_initialize(&parser))
    fputs("Failed to initialize parser!\n", stderr);
  if(fh == NULL)
    fputs("Failed to open file!\n", stderr);

  /* Set input file */
  yaml_parser_set_input_file(&parser, fh);

  /* START new code */
  int id=1;
  char event_type[20];
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
      //what event takes place here? log it in the hash?
      break;
    case YAML_STREAM_END_EVENT:   puts("STREAM END");   break;
    /* Block delimeters */
    case YAML_DOCUMENT_START_EVENT: puts("<b>Start Document</b>"); break;
    case YAML_DOCUMENT_END_EVENT:   puts("<b>End Document</b>");   break;
    case YAML_SEQUENCE_START_EVENT: puts("<b>Start Sequence</b>"); break;
    case YAML_SEQUENCE_END_EVENT:   puts("<b>End Sequence</b>");   break;
    case YAML_MAPPING_START_EVENT:  puts("<b>Start Mapping</b>");  break;
    case YAML_MAPPING_END_EVENT:    puts("<b>End Mapping</b>");    break;
    /* Data */
    case YAML_ALIAS_EVENT:
      printf("Got alias (anchor %s)\n", event.data.alias.anchor); 
      break;
      
    case YAML_SCALAR_EVENT:
      event_type[0] = YAML_SCALAR_EVENT;
      printf("Got scalar (value %s)\n", event.data.scalar.value); 
      add_event(id++, event_type);
      printf("YAML_SCALAR_EVENT: %d\n", event_type[0]);
      break;
    }
    if(event.type != YAML_STREAM_END_EVENT)
      yaml_event_delete(&event);
  } while(event.type != YAML_STREAM_END_EVENT);
  yaml_event_delete(&event);
  /* END new code */

  /* Cleanup */
  yaml_parser_delete(&parser);
  delete_all();
  fclose(fh);
  return 0;
}
