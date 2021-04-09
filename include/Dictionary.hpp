#ifndef __DICTIONARY_HPP__
#define __DICTIONARY_HPP__

#include "Entry.hpp"
#include <map>
#include <string>
#include <vector>

class Entry;

class Dictionary {

public:
    Dictionary();
    void print() const;
    void set_pair(const std::string& key, const Entry value);
    Dictionary* add_child(const std::string& key);
    std::vector<int>* add_vector(const std::string& key);
    Dictionary* get_parent() const;
    double getVariableForComponent(int comp_num, 
                                   const char* var_name, 
                                   const char* sys_name) const;

private:
    Dictionary(Dictionary* dict);
    void print_spaces(int nspaces) const;

    std::map<std::string, Entry> map_;
    Dictionary* parent_;
};

#endif