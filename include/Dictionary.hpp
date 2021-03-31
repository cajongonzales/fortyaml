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
    void set_key(const std::string& key);
    void print() const;
    Dictionary* get_parent() const;
    Dictionary* get_last_child() const;

private:
    Dictionary(Dictionary* d);
    void print_spaces(int nspaces) const;

    std::map<std::string, Entry> map_;
    Dictionary* parent_;
    Dictionary* last_child_;
};

#endif