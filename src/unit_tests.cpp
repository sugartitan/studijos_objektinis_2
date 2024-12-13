#include "unit_tests.h"
#include <data_input.h>
#include <vector>
#include <Student.h>
#include <cassert>
#include <list>

void ReadDataFromFile_FileNotFound_test() {
    std::vector<Student> students = {};

    try {
        ReadDataFromFile(students, "");
    }
    catch (std::exception& e){
        assert(e.what() == FileNotFound().what());
    }
}

void ReadDataFromFile_Vector_FileEmpty_test() {
    std::vector<Student> students = {};

    ReadDataFromFile(students, "tests/test_data/test_students0.txt");

    assert(students.size() == 0);
}

void ReadDataFromFile_Vector_FileNotEmpty_test() {
    std::vector<Student> students = {};

    ReadDataFromFile(students, "tests/test_data/test_students10.txt");

    assert(students.size() == 10);
}

void ReadDataFromFile_List_FileEmpty_test() {
    std::list<Student> students = {};

    ReadDataFromFile(students, "tests/test_data/test_students0.txt");

    assert(students.size() == 0);
}

void ReadDataFromFile_List_FileNotEmpty_test() {
    std::list<Student> students = {};

    ReadDataFromFile(students, "tests/test_data/test_students10.txt");

    assert(students.size() == 10);
}

void UnitTests() {
    ReadDataFromFile_FileNotFound_test();
    ReadDataFromFile_Vector_FileEmpty_test();
    ReadDataFromFile_Vector_FileNotEmpty_test();
    ReadDataFromFile_List_FileEmpty_test();
    ReadDataFromFile_List_FileNotEmpty_test();
}