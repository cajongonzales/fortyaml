#include <map>
#include <string>

class Dictionary {

public:
    Dictionary() {}
    
    void set_key(const std::string& key) {
        map_[key] = new Dictionary(this);
        last_child_ = map_[key];
    }

    void print() const {
        print_spaces(0);
    }

    Dictionary* get_parent() const {
        return parent_;
    }

    Dictionary* get_last_child() const {
        return last_child_;
    }

private:
    Dictionary(Dictionary* d) {
        parent_ = d;
    }

    void print_spaces(int nspaces) const {
        for (auto const& pair : map_) {
            for(int i=0; i<nspaces; i++) printf(" ");
            printf("%s\n", pair.first.c_str());
            pair.second->print_spaces(nspaces+2);
        }
    }

    std::map<std::string, Dictionary*> map_;
    Dictionary* parent_;
    Dictionary* last_child_;
};
