#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <tuple>
#include "Student.h"
#include "helper.h"
#include "data_input.h"
#include "Exceptions.h"

void DataInput() {
    char choice1, choice2;
    bool cont = true;
    while (cont) {
        std::cout << "Please choose: \n(l) - list\n(v) - vector" << std::endl; 
        std::cout << "Enter: ";
        std::cin >> choice1;

        if (choice1 == 'l') {
            break;
        }
        else if (choice1 == 'v'){
            break;
        }
        else {
            std::cout << "Choice does not exist.";
        }

        std::cout << "\n\n";   
    }

    while (cont) {
        std::cout << "Please choose: \n(1) - split container\n(2) - use same container" << std::endl; 
        std::cout << "Enter: ";
        std::cin >> choice2;

        if (choice2 == '1') {
            break;
        }
        else if (choice2 == '2'){
            break;
        }
        else {
            std::cout << "Choice does not exist.";
        }

        std::cout << "\n\n";   
    }

    if (choice1 == 'l') {
        std::list<Student> students;
        DataInput(students, choice2 == '1');
    } else {
        std::vector<Student> students;
        DataInput(students, choice2 == '1');
    }
}