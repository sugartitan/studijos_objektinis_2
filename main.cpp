#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "Student.h"

bool CompareStudents(Student s1, Student s2) {
    if (s1.name == s2.name){
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

int GetRandomGrade() {
    return std::rand() % 10 + 1;
}

void GenerateRandomGrades(Student& s, int n) {
    for (int i = 0; i < n; i++) {
        s.grades.push_back(GetRandomGrade());
    }

    s.exam_grade = GetRandomGrade();
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

double Mean(std::vector<int> grades) {
    double sum = 0;
    for (int grade : grades) {
        sum += grade;
    }

    return sum / grades.size();
}

double Median(std::vector<int> grades) {
    std::vector<int> v_sorted(grades.size());
    std::partial_sort_copy(begin(grades), end(grades), begin(v_sorted), end(v_sorted));

    if (v_sorted.size() % 2 == 0) {
        return (v_sorted[v_sorted.size() / 2] + v_sorted[v_sorted.size() / 2 - 1]) / 2;
    }
    return v_sorted[v_sorted.size() / 2];
}

void ReadDataFromConsole(std::vector<Student>& students) {
    std::string name, last_name, str;
    int index = 1, grade, exam_grade, n_grades;
    char add_another, at_random;

    while (true) {
        Student s;
        std::cout << "Enter student's Name: ";
        std::cin >> s.name;
        std::cout << "Last name: ";
        std::cin >> s.last_name;

        std::cout << "\nDo you want to generate student's grades at random? (y/n): ";
        std::cin >> at_random;

        if (at_random == 'n') {
            std::cout << "Enter as many student's homework grades as you like. Press ENTER twice to finish." << std::endl;

            std::cin.ignore();

            while (getline(std::cin, str) and !str.empty()) {
                std::stringstream ss(str);
                while (ss >> grade)
                    s.grades.push_back(grade);
            }

            ReadInt(s.exam_grade, "Enter student's egzam grade: ");
        }
        else {
            ReadInt(n_grades, "Enter a number of homework grades to generate: ");
            GenerateRandomGrades(s, n_grades);
        }

        students.push_back(s);

        std::cout << "\nDo you wish to add another student? (y/n): ";
        std::cin >> add_another;

        if (add_another == 'n') {
            break;
        }
    }

    std::sort(students.begin(), students.end(), CompareStudents);
}

void ReadDataFromFile(std::vector<Student>& students, std::string filePath) {
    std::ifstream file(filePath);
    std::string my_string, token;
    int pos = 0, grade;

    if (!file) {
        throw("File does not exist");
    }
    
    if (file.is_open()) {
        getline(file, my_string);
        int count = CountWords(my_string);

        while (getline(file, my_string)) {
            std::stringstream ss(my_string);
            Student student;
            ss >> student.name >> student.last_name;
            for (int i = 0; i < count - 3; i++) {
                ss >> grade;
                student.grades.push_back(grade);
            }
            ss >> student.exam_grade;

            students.push_back(student);
        }
    }

    file.close();

    std::sort(students.begin(), students.end(), CompareStudents);
}

std::string ConvertDoubleToString(double d) {
    std::ostringstream oss;
    oss.precision(2);
    oss << std::fixed << d;
    return oss.str();
}

std::string PadTo(std::string str, size_t num, bool pad_right = false, char paddingChar = ' ')
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

std::string MakeSingleLine(std::vector<Student> students) {
    double mean, median;
    std::string line = PadTo("Name", 20) + PadTo("Last name", 20) + PadTo("Final grade (mean)", 20, true) + PadTo("Final grade (median)", 25, true);
    line += '\n' + std::string(85, '-') + '\n';
    for (Student s : students) {
        mean = Mean(s.grades);
        median = Median(s.grades);
        line += PadTo(s.name, 20) + PadTo(s.last_name, 20) + PadTo(ConvertDoubleToString(mean), 20, true) + PadTo(ConvertDoubleToString(median), 25, true) + '\n';
    }
    return line;
}

void WriteStudentsResultsToFile(std::vector<Student> students, std::string file_path) {
    std::ofstream file(file_path);
    file << MakeSingleLine(students);
    file.close();
}

int main() {
    std::vector<Student> students;
    std::string file_path, output_file_path, mean_or_median;
    char read_data;

    while (true) {
        std::cout << "Read data from (enter 'c' for console or 'f' for file): ";
        std::cin >> read_data;

        if (read_data != 'c' && read_data != 'f') {
            std::cout << "Invalid input" << std::endl;
        } 
        else {
            break;
        }
    }

    if (read_data == 'c') {
        ReadDataFromConsole(students);
    }
    else {
        std::cout << "Please enter file path: ";
        std::cin >> file_path;
        try {
            ReadDataFromFile(students, file_path);  
        }
        catch (std::string e){
            std::cout << e << std::endl;
        }
    }

    std::cout << "Please enter output file path: ";
    std::cin >> output_file_path;

    WriteStudentsResultsToFile(students, output_file_path);

    return 0;
}