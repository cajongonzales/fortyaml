#include <stdio.h>
#include <string> //strcpy
#include <yaml.h>
#include "Dictionary.hpp"

extern "C" {

const Dictionary* yamlEventReader(const char *filePath)
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
  Dictionary* dict = new Dictionary();
  Dictionary* curr_dict = nullptr;
  std::vector<int>* curr_vect = nullptr;
  DataType datatype;

  std::string last_key;

  /* START new code */
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
      printf("YAML_STREAM_START_EVENT\n");
      break;
    case YAML_STREAM_END_EVENT: 
      printf("YAML_STREAM_END_EVENT\n");  
      break;
    /* Block delimeters */
    case YAML_DOCUMENT_START_EVENT:
      printf("YAML_DOCUMENT_START_EVENT\n"); 
      break;
    case YAML_DOCUMENT_END_EVENT:
      printf("YAML_DOCUMENT_END_EVENT\n");   
      break;
    case YAML_SEQUENCE_START_EVENT:
      printf("YAML_SEQUENCE_START_EVENT\n");
      curr_vect = curr_dict->add_vector(last_key);
      last_key.clear();
      break;
    case YAML_SEQUENCE_END_EVENT:
      printf("YAML_SEQUENCE_END_EVENT\n");
      curr_vect = nullptr;
      break;
    case YAML_MAPPING_START_EVENT:
      printf("YAML_MAPPING_START_EVENT\n");
      datatype = DICTIONARY;
      // The first mapping sets the current pointer to the dictionary root
      if(!curr_dict) {
        curr_dict = dict;
      }
      else {
        curr_dict = curr_dict->add_child(last_key);
        last_key.clear();
      } 
      break;
    case YAML_MAPPING_END_EVENT:
      printf("YAML_MAPPING_END_EVENT\n");
      datatype = INVALID;
      last_key.clear();
      curr_dict = curr_dict->get_parent();
      break;
    /* Data */
    case YAML_ALIAS_EVENT:
      printf("YAML_ALIAS_EVENT\n");
      break;
    case YAML_SCALAR_EVENT:
      printf("YAML_SCALAR_EVENT\n");

      // value is actually an unsigned char*, so we are assuming ASCII in this cast here
      std::string key(reinterpret_cast<const char*>(event.data.scalar.value));

      printf("%s (last key %s)\n", event.data.scalar.value, last_key.c_str());

      if(curr_vect) {
        curr_vect->push_back(std::stoi(key));
      } 
      else if(!last_key.empty()) {
        Entry e(key);
        curr_dict->set_pair(last_key, e);
        last_key.clear();
      } 
      else {
        last_key = key;
      }

      printf("DICT BEGIN ---\n");
      dict->print();
      printf("DICT END ---\n");

      break;
    }

    if(event.type != YAML_STREAM_END_EVENT)
      yaml_event_delete(&event);
  } while(event.type != YAML_STREAM_END_EVENT);
  yaml_event_delete(&event);
  /* END new code */

  dict->print();

  /* Cleanup */
  yaml_parser_delete(&parser);
//  delete_all();
  fclose(fh);
  return dict;
}

} // end extern C
