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
        std::string name() const { return name_; }
        std::string lastName() const { return last_name_; }
        virtual ~Human() = 0;
};

#endif