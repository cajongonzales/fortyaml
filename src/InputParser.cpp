#include <iostream>
#include <vector>
#include "InputParser.hpp"

InputParser::InputParser(const char* filepath) {
  node_ = YAML::LoadFile(filepath);
}

double InputParser::getVariableForComponent(int comp_num, const char* var_name, const char* sys_name) const {
  // For all local components...
  const YAML::Node& local = node_["Local"];

  // comp is a pointer to a pair; the first item is the key and the second is the value
  // which in our case will usually be a map/tree
  for(YAML::const_iterator comp = local.begin(); comp != local.end(); ++comp) {
    // Get the list of numbers corresponding to this component
    const YAML::Node& number = comp->second["number"];
    bool found_it = false;

    // If number is a single value, compare it to comp_num
    if(number.IsScalar() && number.as<int>() == comp_num) {
      found_it = true;
    }
    // Otherwise, compare its entries to comp_num
    else if(number.IsSequence()) {
      const std::vector<int>& numbers = number.as<std::vector<int>>();
      found_it = std::find(numbers.begin(), numbers.end(), comp_num) != numbers.end();
    }

    // If the variable is defined for this component...
    if(found_it && comp->second[var_name].IsDefined()) {
      // ...return its value
      return comp->second[var_name].as<double>();
    }
  }

  // Search the specified system for this variable
  // Note: we assume the specified system name is in fact valid
  if(node_[sys_name].IsDefined()) {
    const YAML::Node& system = node_[sys_name];
    if(system[var_name].IsDefined() && system[var_name].IsScalar()) {
      return system[var_name].as<double>();
    } 
  }

  // Search the globals for this variable
  const YAML::Node& global = node_["Global"];
  if(global[var_name].IsDefined() && global[var_name].IsScalar()) {
    return global[var_name].as<double>();
  } 

  // By default, return 1.0
  return 1.0;
}

const YAML::Node& InputParser::get_node() const {
  return node_;
}

extern "C" {

  InputParser* input_parser_ctor(const char* filepath) {
    return new InputParser(filepath);
  }

  double get_var_for_comp(const InputParser* parser,
                          int comp_num, 
                          const char* var_name, 
                          const char* sys_name) 
  {
    return parser->getVariableForComponent(comp_num, var_name, sys_name);
  }

} // end extern C
