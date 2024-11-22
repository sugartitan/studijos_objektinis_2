#ifndef DATAINPUT_H
#define DATAINPUT_H
#include "Exceptions.h"

template <typename T> void ReadDataFromConsole(T &students) {
    std::vector<int> grades;
    std::string name, last_name, str;
    int index = 1, grade, exam_grade, n_grades;
    char add_another, at_random;

    while (true) {
        Student s;
        std::cout << "Enter student's Name: ";
        std::cin >> name;
        std::cout << "Last name: ";
        std::cin >> last_name;

        std::cout << "\nDo you want to generate student's grades at random? (y/n): ";
        std::cin >> at_random;

        if (at_random == 'n') {
            std::cout << "Enter as many student's homework grades as you like. Press ENTER twice to finish." << std::endl;

            std::cin.ignore();

            while (getline(std::cin, str) and !str.empty()) {
                std::stringstream ss(str);
                while (ss >> grade)
                    grades.push_back(grade);
            }

            ReadInt(exam_grade, "Enter student's egzam grade: ");
        }
        else {
            ReadInt(n_grades, "Enter a number of homework grades to generate: ");
            grades = GenerateRandomGrades(n_grades);
        }

        s = Student(name, last_name, grades, exam_grade);
        students.push_back(s);

        grades = std::vector<int>{};

        std::cout << "\nDo you wish to add another student? (y/n): ";
        std::cin >> add_another;

        if (add_another == 'n') {
            break;
        }
    }

    Sort(students);
}

template <typename T> void ReadDataFromFile(T &students, std::string filePath) {
    std::ifstream file(filePath);
    std::string my_string, token, name, last_name;
    std::vector<int> grades;
    int pos = 0, grade, exam_grade;

    if (!file) {
        throw FileNotFound();
    }
    
    if (file.is_open()) {
        getline(file, my_string);
        int count = CountWords(my_string);
        getline(file, my_string);

        while (getline(file, my_string)) {
            std::stringstream ss(my_string);
            Student student;
            ss >> name >> last_name;
            for (int i = 0; i < count - 4; ++i) {
                ss >> grade;
                grades.push_back(grade);
            }
            ss >> exam_grade;

            student = Student(name, last_name, grades, exam_grade);

            students.push_back(student);

            grades = std::vector<int>();
        }
    }

    file.close();
}

template <typename T> void DataInput(T &students, bool split) {
    T poor_students, smart_students;
    std::string file_path, poor_output_file_path, smart_output_file_path;
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
        catch (std::exception& e){
            std::cout << "Error: " << e.what() << std::endl;
            return;
        }
    }

    Sort(students);

    std::cout << "Please enter output file path for 'poor' students: ";
    std::cin >> poor_output_file_path;

    std::cout << "Please enter output file path for 'smart' students: ";
    std::cin >> smart_output_file_path;

    if (split) {
        tie(poor_students, smart_students) = SplitStudents(students);
        WriteStudentsResultsToFile(smart_students, smart_output_file_path);
    } else {
        tie(poor_students, students) = SplitStudents(students);
        WriteStudentsResultsToFile(students, smart_output_file_path);
    }
    
    WriteStudentsResultsToFile(poor_students, poor_output_file_path);

    std::cout << "Poor students results save in '" << poor_output_file_path << "'\n";
    std::cout << "Smart students results save in '" << smart_output_file_path << "'\n";

    return;
}

void DataInput();

#endif