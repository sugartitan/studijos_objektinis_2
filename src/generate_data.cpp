#include <algorithm>
#include <vector>
#include <fstream>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <list>
#include "Student.h"
#include "helper.h"
#include "generate_data.h"

Student GenerateStudent(int n, int n_grades) {
    std::string name = "Vardas" + std::to_string(n);
    std::string last_name = "Pavarde" + std::to_string(n);
    std::vector<int> grades = GenerateRandomGrades(n_grades);
    int exam_grade = GetRandomGrade();
    Student s = Student(name, last_name, grades, exam_grade);
    return s;
}

std::vector<std::vector<double>> GenerateData() {
    std::vector<std::vector<double>> data;
    char choice;
    bool cont = true;
    while (cont) {
        std::cout << "Please choose: \n(l) - list\n(v) - vector" << std::endl; 
        std::cout << "Enter: ";
        std::cin >> choice;

        if (choice == 'l') {
            std::list<Student> students;
            data = GenerateData(students);
            break;
        }
        else if (choice == 'v'){
            std::vector<Student> students;
            data = GenerateData(students);
            break;
        }
        else {
            std::cout << "Choice does not exist.";
        }

        std::cout << "\n\n";   
    }

    return data;
}