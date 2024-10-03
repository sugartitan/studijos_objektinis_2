#ifndef GENERATEDATA_H
#define GENERATEDATA_H
#include <vector>
#include "Student.h"

std::vector<int> GenerateRandomGrades(int n);

Student GenerateStudent(int n, int n_grades);

std::vector<Student> CreateStudentList(int n, int n_grades);

std::string CreateSingleLine(std::vector<Student> students);

void GenerateData();

#endif