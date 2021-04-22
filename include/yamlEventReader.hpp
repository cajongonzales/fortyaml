#ifndef __INPUT_PARSER_HPP__
#define __INPUT_PARSER_HPP__

class InputParser {
public:
  InputParser(const char* filepath);
};

extern "C" {

  InputParser* yamlEventReader(const char* filepath);

  double get_var_for_comp_c(const InputParser* parser,
                            int comp_num, 
                            const char* var_name, 
                            const char* sys_name);

} // end extern C

#endif