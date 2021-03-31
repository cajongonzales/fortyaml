#ifndef __ENTRY_HPP__
#define __ENTRY_HPP__

#include "Dictionary.hpp"
#include<vector>

class Dictionary;

enum DataType {
    INVALID = 0,
    DICTIONARY,
    VECTOR,
    DOUBLE
};

union Data {
    Dictionary* dict;
    std::vector<int>* vect;
    double dbl;
};

class Entry {
public:
    Entry();
    Entry(Dictionary* dict);
    Entry(std::vector<int>* vect);
    Entry(const double dbl);
    
    ~Entry();

    const Dictionary* getDictionary() const;
    const std::vector<int>* getVector() const;
    double getDouble() const;

    Dictionary* getDictionary();
    std::vector<int>* getVector();

    bool isa(const DataType datatype) const;
private:
    DataType datatype_;
    Data data_;
};

#endif