#ifndef HELPER_H
#define HELPER_H
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include "Student.h"

bool CompareStudents(Student s1, Student s2);

int CountWords(std::string str);

double Mean(std::vector<int> grades);

double Median(std::vector<int> grades);

std::string ConvertDoubleToString(double d);

std::string PadTo(std::string str, size_t num, bool pad_right = false, char paddingChar = ' ');

int GetRandomGrade();

void GenerateRandomGrades(Student& s, int n);

void ReadInt(int& n, std::string header);

void ReadDataFromConsole(std::vector<Student>& students);

void ReadDataFromFile(std::vector<Student>& students, std::string filePath);

std::tuple<std::vector<Student>, std::vector<Student>> SplitStudents(std::vector<Student> students);

std::string MakeSingleLine(std::vector<Student> students);

void WriteStudentsResultsToFile(std::vector<Student> students, std::string file_path);

#endif