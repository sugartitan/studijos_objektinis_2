#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>

class Student {
    private:
        std::string name_;
        std::string last_name_;
        std::vector<int> grades_;
        int exam_grade_;

    public:
        Student() : name_(""), last_name_(""), grades_(std::vector<int>{}), exam_grade_(0) { }

        Student(std::string name, std::string last_name, std::vector<int> grades, int exam_grade) : name_(name), last_name_(last_name), grades_(grades), exam_grade_(exam_grade) { };

        Student(const Student& other) : Student(other.name_, other.last_name_, other.grades_, other.exam_grade_) {}
 
        Student& operator=(const Student& other) {
            if (this == &other) {
                return *this;
            }
    
            Student temp(other);
            std::swap(name_, temp.name_);
            std::swap(last_name_, temp.last_name_);
            std::swap(grades_, temp.grades_);
            std::swap(exam_grade_, temp.exam_grade_);
    
            return *this;
        }

        std::string name() const { return name_; }
        std::string lastName() const { return last_name_; }
        std::vector<int> getGrades() const { return grades_; }
        int getExam() const { return exam_grade_; }
        ~Student() {};
};

#endif