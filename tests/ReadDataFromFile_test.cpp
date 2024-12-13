#include <data_input.h>
#include <vector>
#include <Student.h>
#include <cassert>

void ReadDataFromFile_FileNotFound_test() {
    std::vector<Student> students = {};

    try {
        ReadDataFromFile(students, "");
    }
    catch (std::exception& e){
        assert(e.what() == FileNotFound().what());
    }
}

void 