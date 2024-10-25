#include <iostream>
#include "helper.h"
#include "data_input.h"
#include "generate_data.h"
#include "test_speed.h"

int main() {
    char choice;
    bool cont = true;

    while (cont) {
        std::cout << "Please choose: \n(g) - data generation\n(d) - data input\n(t) - test speed\n(e) - end program" << std::endl; 
        std::cout << "Enter: ";
        std::cin >> choice;

        switch (choice) {
            case 'd':
                DataInput();
                break;
            case 'g':
                GenerateData();
                break;
            case 't':
                TestSpeed();
                break;
            case 'e':
                cont = false;
                break;
            default:
                std::cout << "Choice does not exist.";
        }

        std::cout << "\n\n";
    }
}