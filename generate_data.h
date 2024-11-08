#ifndef GENERATEDATA_H
#define GENERATEDATA_H
#include <vector>
#include <list>
#include "Student.h"

std::vector<int> GenerateRandomGrades(int n);

Student GenerateStudent(int n, int n_grades);

template <typename T> void CreateStudentList(T &students, int n, int n_grades);

template <typename T> std::string CreateSingleLine(T students);

template <typename T> void GenerateData(T &students);

void GenerateData();

#endif