#ifndef __INPUT_PARSER_HPP__
#define __INPUT_PARSER_HPP__

#include "yaml-cpp/yaml.h"

class InputParser {
public:
  InputParser(const char* filepath);

  double getVariableForComponent(int comp_num, const char* var_name, const char* sys_name) const;

  const YAML::Node& get_node() const;
private:
  YAML::Node node_;
};

extern "C" {

  InputParser* input_parser_ctor(const char* filepath);

  double get_var_for_comp(const InputParser* parser,
                            int comp_num, 
                            const char* var_name, 
                            const char* sys_name);

} // end extern C

#endif