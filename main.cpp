#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>

struct Student {
    std::string name, last_name;
    std::vector<int> grades;
    int egzam_grade;
};

int CountWords(std::string str) {
    int count = 0;
    std::stringstream ss(str);
    std::string word;
    while(ss >> word) { ++count;}
    return count;
}

void ReadData(Student &student) {
    std::string name, last_name;
    std::cout << "Enter student's" << std::endl << "Name:";
    std::cin >> name;
    std::cout << "Last name:";
    std::cin >> last_name;
}

void ReadDataFromFile(std::vector<Student>& students, std::string filePath) {
    std::ifstream file(filePath);
    std::string my_string, token;
    int pos = 0, grade;
    
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
            ss >> student.egzam_grade;

            students.push_back(student);
        }
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

void PrintStudentsResults(std::vector<Student> students, bool if_mean) {
    double sum = 0, value;
    std::string func_str = "Final grade ";

    if (if_mean) { 
        func_str += "(mean)";
    }
    else {
        func_str += "(median)";
    }

    std::cout << std::left << std::setw(20) << "Name" << std::setw(20) << "Last name" << std::right << std::setw(20) << func_str << std::endl;
    std::cout << std::string(60, '-') << std::endl;

    for (Student s : students) {
        std::cout << std::left << std::setw(20) << s.name << std::setw(20) << s.last_name;

        if (if_mean) {
            value = Mean(s.grades);
        }
        else {
            value = Median(s.grades);
        }

        std::cout << std::right << std::setw(20) << std::fixed << std::setprecision(2) << value << std::endl;
        sum = 0;
    }
}

int main() {
    std::vector<Student> students;
    std::string file_path;

    ReadDataFromFile(students, file_path);

    PrintStudentsResults(students, true);

    return 0;
}