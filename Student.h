#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>

struct Student {
    std::string name, last_name;
    std::vector<int> grades;
    int egzam_grade;
};

#endif