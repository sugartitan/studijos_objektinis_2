#ifndef HUMAN_H
#define HUMAN_H
#include <string>

class Human {
    protected:
        std::string name_;
        std::string last_name_;

    public:
        Human() : name_(""), last_name_("") { }
        Human(std::string name, std::string last_name) : name_(name), last_name_(last_name) { }
};

#endif