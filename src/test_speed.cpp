#include <string>
#include <fstream>
#include <chrono>
#include <cmath>
#include <tuple>
#include <list>
#include "Student.h"
#include "Exceptions.h"
#include "helper.h"
#include "test_speed.h"
#include "data_input.h"

std::vector<std::vector<double>> TestSpeed() {
    std::vector<std::vector<double>> data;
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
        data = TestSpeed(students, choice2 == '1');
    } else {
        std::vector<Student> students;
        data = TestSpeed(students, choice2 == '1');
    }
    
    return data;
}