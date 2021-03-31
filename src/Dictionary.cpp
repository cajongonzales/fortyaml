#include "Dictionary.hpp"

Dictionary::Dictionary()
{
    parent_ = nullptr;
    last_child_ = nullptr;
}

void Dictionary::set_key(const std::string &key)
{
    Entry* e = new Entry(new Dictionary(this));
    map_[key] = *e;
    last_child_ = map_[key].getDictionary();
}

void Dictionary::print() const
{
    print_spaces(0);
}

Dictionary* Dictionary::get_parent() const
{
    return parent_;
}

Dictionary* Dictionary::get_last_child() const
{
    return last_child_;
}

Dictionary::Dictionary(Dictionary *d)
{
    parent_ = d;
}

void Dictionary::print_spaces(int nspaces) const
{
    for (auto const &pair : map_)
    {
        for (int i = 0; i < nspaces; i++)
            printf(" ");
        printf("%s\n", pair.first.c_str());
        if(pair.second.isa(DICTIONARY))
            pair.second.getDictionary()->print_spaces(nspaces + 2);
    }
}