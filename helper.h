#ifndef HELPER_H
#define HELPER_H
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <tuple>
#include "Student.h"

bool CompareStudents(Student s1, Student s2);

int CountWords(std::string str);

double Mean(Student s);

double Median(Student s);

std::string ConvertDoubleToString(double d);

std::string PadTo(std::string str, size_t num, bool pad_right = false, char paddingChar = ' ');

int GetRandomGrade();

void GenerateRandomGrades(Student& s, int n);

void ReadInt(int& n, std::string header);

template <typename T> std::tuple<T, T> SplitStudents(T students) {
    T poor, smart;

    for (Student s : students) {
        if (Mean(s) < 5) poor.push_back(s);
        else smart.push_back(s);
    }

    return std::make_tuple(poor, smart);
}

template <typename T> T SplitStudentsKeep(T &students) {
    T poor;
    
    for (Student s : students) {
        if (Mean(s) < 5) {
            poor.push_back(s);
        }
    }

    students.erase(
        std::remove_if(students.begin(), students.end(), [](Student s) { return Mean(s) < 5; }),
        students.end());

    return poor;
}

template <typename T> std::string MakeSingleLine(T students) {
    double mean, median;
    std::string line = PadTo("Name", 20) + PadTo("Last name", 20) + PadTo("Final grade (mean)", 20, true) + PadTo("Final grade (median)", 25, true);
    line += '\n' + std::string(85, '-') + '\n';
    for (Student s : students) {
        mean = Mean(s);
        median = Median(s);
        line += PadTo(s.name, 20) + PadTo(s.last_name, 20) + PadTo(ConvertDoubleToString(mean), 20, true) + PadTo(ConvertDoubleToString(median), 25, true) + '\n';
    }
    return line;
}

template <typename T> void WriteStudentsResultsToFile(T students, std::string file_path) {
    std::ofstream file(file_path);
    file << MakeSingleLine(students);
    file.close();
}

void Sort(std::vector<Student> &students);

void Sort(std::list<Student> &students);

#endif