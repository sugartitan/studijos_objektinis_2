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

std::vector<int> GenerateRandomGrades(int n) {
    std::vector<int> grades;
    for (int i = 0; i < n; i++) {
        grades.push_back(GetRandomGrade());
    }

    return grades;
}

Student GenerateStudent(int n, int n_grades) {
    Student s;
    s.name = "Vardas" + std::to_string(n);
    s.last_name = "Pavarde" + std::to_string(n);
    s.grades = GenerateRandomGrades(n_grades);
    s.exam_grade = GetRandomGrade();
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