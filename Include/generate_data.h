#ifndef GENERATEDATA_H
#define GENERATEDATA_H
#include <algorithm>
#include <vector>
#include <fstream>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <list>
#include "Student.h"

Student GenerateStudent(int n, int n_grades);

template <typename T> void CreateStudentList(T &students, int n, int n_grades) {
    Student s;
    for (int i = 1; i <= n; i++) {
        s = GenerateStudent(i, n_grades);
        students.push_back(s);
    }
}

template <typename T> std::string CreateSingleLine(T students) {
    int n;
    n = students.front().getGrades().size();

    std::string line = PadTo("Name", 25) + PadTo("Last name", 25);

    for (int i = 1; i <= n; i++) {
        line += PadTo("ND" + std::to_string(i), 10, true);
    }

    line += PadTo("Exam", 10, true);

    line += '\n' + std::string(10 * (n + 6), '-') + '\n';

    for (Student s : students) {
        line += PadTo(s.name(), 25) + PadTo(s.lastName(), 25);
        for (int g : s.getGrades()) {
            line += PadTo(std::to_string(g), 10, true);
        }
        line += PadTo(std::to_string(s.getExam()), 10, true) + '\n';
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

std::vector<std::vector<double>> GenerateData();

#endif