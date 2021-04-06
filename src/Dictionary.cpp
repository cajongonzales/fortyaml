#include "Dictionary.hpp"

Dictionary::Dictionary()
{
    parent_ = nullptr;
}

void Dictionary::print() const
{
    print_spaces(0);
}

void Dictionary::set_pair(const std::string& key, const Entry value) {
    map_[key] = value;
}

Dictionary* Dictionary::add_child(const std::string& key) {
    map_[key] = Entry(new Dictionary(this));
    return map_[key].getDictionary();
}

std::vector<int>* Dictionary::add_vector(const std::string& key) {
    map_[key] = Entry(new std::vector<int>());
    return map_[key].getVector();
}

Dictionary* Dictionary::get_parent() const
{
    return parent_;
}
Dictionary::Dictionary(Dictionary *dict)
{
    parent_ = dict;
}

void Dictionary::print_spaces(int nspaces) const
{
    for (auto const &pair : map_)
    {
        for (int i = 0; i < nspaces; i++)
            printf(" ");
        printf("%s", pair.first.c_str());
        if(pair.second.isa(DICTIONARY)) {
            printf("\n");
            pair.second.getDictionary()->print_spaces(nspaces + 2);
        }
        else if(pair.second.isa(DOUBLE)) {
            // lf is long float (double)
            printf(": %lf\n", pair.second.getDouble());
        }
        else if(pair.second.isa(VECTOR)) {
            printf("\n");
            const std::vector<int>& v = *pair.second.getVector();
            for(auto const &entry : v) {
                for (int i = 0; i < nspaces + 2; i++)
                    printf(" ");
                printf("- %i\n", entry);
            }
        }
    }
}
