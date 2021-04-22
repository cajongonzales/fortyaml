#include <iostream>
#include "yamlEventReader.hpp"
#include "yaml-cpp/yaml.h"

InputParser::InputParser(const char* filepath) {
  YAML::Node config = YAML::LoadFile(filepath);

  std::cout << config << std::endl;
}

extern "C" {

  InputParser* yamlEventReader(const char* filepath) {
    return new InputParser(filepath);
  }

  double get_var_for_comp(const InputParser* parser,
                          int comp_num, 
                          const char* var_name, 
                          const char* sys_name) 
  {

  }

} // end extern C
