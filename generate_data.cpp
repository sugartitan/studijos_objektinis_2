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

template <typename T> void CreateStudentList(T &students, int n, int n_grades) {
    Student s;
    for (int i = 1; i <= n; i++) {
        s = GenerateStudent(i, n_grades);
        students.push_back(s);
    }
}

template <typename T> std::string CreateSingleLine(T students) {
    int n;
    n = students.front().grades.size();

    std::string line = PadTo("Name", 25) + PadTo("Last name", 25);

    for (int i = 1; i <= n; i++) {
        line += PadTo("ND" + std::to_string(i), 10, true);
    }

    line += PadTo("Exam", 10, true);

    line += '\n' + std::string(10 * (n + 6), '-') + '\n';

    for (Student s : students) {
        line += PadTo(s.name, 25) + PadTo(s.last_name, 25);
        for (int g : s.grades) {
            line += PadTo(std::to_string(g), 10, true);
        }
        line += PadTo(std::to_string(s.exam_grade), 10, true) + '\n';
    }
    return line;
}

template <typename T> std::vector<std::vector<double>> GenerateData(T &students) {
    std::vector<std::vector<double>> data;
    std::vector<double> line;
    std::ofstream file;
    std::string single_line, path = "generated_data";

    int n, n_grades = 15;
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff;

    for (int i = 3; i <= 7; i++) {
        line.push_back(i - 3);
        n = std::pow(10, i);
        file.open("generated_data/students" + std::to_string(n) + ".txt");

        start = std::chrono::high_resolution_clock::now();
        CreateStudentList(students, n, n_grades);
        diff = std::chrono::high_resolution_clock::now() - start;
        std::cout << std::fixed << n << " studentu duomenu sugeneravimas uztruko: " << diff.count() << " s\n";
        line.push_back(diff.count());

        start = std::chrono::high_resolution_clock::now();
        single_line = CreateSingleLine(students);
        diff = std::chrono::high_resolution_clock::now() - start;
        std::cout << std::fixed << n << " studentu duomenu sudejimas i viena eilute uztruko: " << diff.count() << " s\n";
        line.push_back(diff.count());

        start = std::chrono::high_resolution_clock::now();
        file << single_line;
        diff = std::chrono::high_resolution_clock::now() - start;
        std::cout << std::fixed << n << " studentu duomenu irasymas i faila uztruko: " << diff.count() << " s\n\n\n";
        line.push_back(diff.count());

        data.push_back(line);

        file.close();

        students = T{};
        line = std::vector<double>{};
    }

    return data;
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