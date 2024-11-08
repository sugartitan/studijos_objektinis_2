#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <tuple>
#include <limits>
#include <list>
#include "Student.h"
#include "Exceptions.h"
#include "helper.h"

bool CompareStudents(Student s1, Student s2) {
    if (s1.name == s2.name){
        if (s1.last_name == s2.last_name) {
            return Mean(s1) < Mean(s2);
        }
        return s1.last_name < s2.last_name;
    }
    return s1.name < s2.name;
}

int CountWords(std::string str) {
    int count = 0;
    std::stringstream ss(str);
    std::string word;
    while(ss >> word) { ++count;}
    return count;
}

double Mean(Student s) {
    double sum = s.exam_grade;
    for (int grade : s.grades) {
        sum += grade;
    }

    return sum / (s.grades.size() + 1);
}

double Median(Student s) {
    std::vector<int> v_sorted(s.grades);
    v_sorted.push_back(s.exam_grade);
    std::sort(v_sorted.begin(), v_sorted.end());;

    if (v_sorted.size() % 2 == 0) {
        return (v_sorted[v_sorted.size() / 2] + v_sorted[v_sorted.size() / 2 - 1]) / 2;
    }
    return v_sorted[v_sorted.size() / 2];
}

std::string ConvertDoubleToString(double d) {
    std::ostringstream oss;
    oss.precision(2);
    oss << std::fixed << d;
    return oss.str();
}

std::string PadTo(std::string str, size_t num, bool pad_right, char paddingChar)
{
    std::string str_copy = str;
    if(num > str.size())
        if (pad_right) {
            str_copy.insert(0, num - str.size(), paddingChar);
        }
        else {
            str_copy.insert(str.size(), num - str.size(), paddingChar);
        }

    return str_copy;
}

int GetRandomGrade() {
    return std::rand() % 10 + 1;
}

void GenerateRandomGrades(Student& s, int n) {
    for (int i = 0; i < n; i++) {
        s.grades.push_back(GetRandomGrade());
    }
}

void ReadInt(int& n, std::string header) {
    std::cout << header;
    std::cin >> n;

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                '\n');
        std::cout << "Input is not an integer" << std::endl;
        std::cout << header;
        std::cin >> n;
    }
}

void Sort(std::vector<Student> &students) {
    std::sort(students.begin(), students.end(), CompareStudents);
}

void Sort(std::list<Student> &students) {
    students.sort(CompareStudents);
}

void SaveCsv(std::vector<std::vector<double>> data, std::string file_path) {
    std::ofstream file;
    file.open(file_path);
    std::string text = "";

    for (int i = 0; i < data.size(); i++) {
        text += std::to_string(i);
        for (int j = 0; j < data[i].size(); j++) {
            text += ',' + std::to_string(data[i][j]);
        }
        text += '\n';
    }

    file << text;
    file.close();
}