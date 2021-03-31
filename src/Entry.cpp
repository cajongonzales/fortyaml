#include "Entry.hpp"

Entry::Entry() {
    datatype_ = INVALID;
}

Entry::Entry(Dictionary* dict) {
    datatype_ = DICTIONARY;
    data_.dict = dict;
}

Entry::Entry(std::vector<int>* vect) {
    datatype_ = VECTOR;
    data_.vect = vect;
}

Entry::Entry(const double dbl) {
    datatype_ = DOUBLE;
    data_.dbl = dbl;
}

Entry::~Entry() {
    if(datatype_ == DICTIONARY)
        delete data_.dict;
    else if(datatype_ == VECTOR)
        delete data_.vect;
}

const Dictionary* Entry::getDictionary() const {
    return data_.dict;
}

const std::vector<int>* Entry::getVector() const {
    return data_.vect;
}

double Entry::getDouble() const {
    return data_.dbl;
}

Dictionary* Entry::getDictionary() {
    return data_.dict;
}
std::vector<int>* Entry::getVector() {
    return data_.vect;
}

bool Entry::isa(const DataType datatype) const {
    return datatype_ == datatype;
}