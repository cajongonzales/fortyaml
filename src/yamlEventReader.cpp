#include <iostream>
#include "yamlEventReader.hpp"

InputParser::InputParser(const char* filepath) {
  node_ = YAML::LoadFile(filepath);
}

const YAML::Node& InputParser::get_node() const {
  return node_;
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
