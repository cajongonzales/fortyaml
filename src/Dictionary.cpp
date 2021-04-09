#include "Dictionary.hpp"
#include <algorithm>
#include <exception>

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

double Dictionary::getVariableForComponent(int comp_num, 
                                           const char* var_name, 
                                           const char* sys_name) const {
    // Search the local components for this number
    auto local = map_.find("Local");
    if (local != map_.end()) {
        auto lmap = local->second.getDictionary()->map_;
        auto component = lmap.find("component");
        if (component != lmap.end()) {
            auto cmap = component->second.getDictionary()->map_;
            auto numbers = cmap.find("number");
            if (numbers != cmap.end()) {
                auto nlist = numbers->second.getVector();

                // If the number has been found, look for the variable
                if (std::find(nlist->begin(), nlist->end(), comp_num) != nlist->end())
                {
                    auto vptr = cmap.find(var_name);
                    if (vptr != cmap.end()) {
                        return vptr->second.getDouble();
                    }
                }
            }
        }
    }

    // Search the given system for this variable
    if (sys_name) {
        auto sptr = map_.find(sys_name);
        if (sptr != map_.end()) {
            auto smap = sptr->second.getDictionary()->map_;
            auto vptr = smap.find(var_name);
            if (vptr != smap.end()) {
                return vptr->second.getDouble();
            }
        }
    }

    // Search the globals for this variable
    auto global = map_.find("Global");
    if (global != map_.end()) {
        auto gmap = global->second.getDictionary()->map_;
        auto vptr = gmap.find(var_name);
        if (vptr != gmap.end()) {
            return vptr->second.getDouble();
        }
    }

    throw std::logic_error("Variable is not defined for this component");
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
