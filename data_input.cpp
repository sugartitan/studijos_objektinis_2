#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include "Student.h"
#include "helper.h"
#include "data_input.h"

void DataInput() {
    std::vector<Student> students, poor_students, smart_students;
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

    std::sort(students.begin(), students.end(), CompareStudents);

    std::cout << "Please enter output file path for 'poor' students: ";
    std::cin >> poor_output_file_path;

    std::cout << "Please enter output file path for 'smart' students: ";
    std::cin >> smart_output_file_path;

    tie(poor_students, smart_students) = SplitStudents(students);

    WriteStudentsResultsToFile(poor_students, poor_output_file_path);
    WriteStudentsResultsToFile(smart_students, smart_output_file_path);

    return;
}