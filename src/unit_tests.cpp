#include "unit_tests.h"
#include "data_input.h"
#include <vector>
#include "Student.h"
#include <cassert>
#include <list>
#include <string>

void ReadDataFromFile_FileNotFound_test() {
    std::vector<Student> students = {};
    std::string file_path = "";

    try {
        ReadDataFromFile(students, "");
    }
    catch (std::exception& e){
        std::string a = e.what(), b = FileNotFound().what();
        assert(a == b);
    }
}

void ReadDataFromFile_Vector_FileEmpty_test() {
    std::vector<Student> students = {};
    std::string file_path = "../tests/test_data/test_students0.txt";

    ReadDataFromFile(students, file_path);

    assert(students.size() == 0);
}

void ReadDataFromFile_Vector_FileNotEmpty_test() {
    std::vector<Student> students = {};
    std::string file_path = "../tests/test_data/test_students10.txt";

    ReadDataFromFile(students, file_path);

    assert(students.size() == 10);
}

void ReadDataFromFile_List_FileEmpty_test() {
    std::list<Student> students = {};
    std::string file_path = "../tests/test_data/test_students0.txt";

    ReadDataFromFile(students, file_path);

    assert(students.size() == 0);
}

void ReadDataFromFile_List_FileNotEmpty_test() {
    std::list<Student> students = {};
    std::string file_path = "../tests/test_data/test_students10.txt";

    ReadDataFromFile(students, file_path);

    assert(students.size() == 10);
}

void UnitTests() {
    std::cout << "FileNotFound test: ";
    ReadDataFromFile_FileNotFound_test();
    std::cout << "Success" << std::endl;

    std::cout << "Vector FileEmpty test: ";
    ReadDataFromFile_Vector_FileEmpty_test();
    std::cout << "Success" << std::endl;

    std::cout << "Vector FileNotEmpty test: ";
    ReadDataFromFile_Vector_FileNotEmpty_test();
    std::cout << "Success" << std::endl;

    std::cout << "List FileEmpty test: ";
    ReadDataFromFile_List_FileEmpty_test();
    std::cout << "Success" << std::endl;

    std::cout << "List FileNotEmpty test: ";
    ReadDataFromFile_List_FileNotEmpty_test();
    std::cout << "Success" << std::endl;
}