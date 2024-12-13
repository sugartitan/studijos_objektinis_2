#include <iostream>
#include "helper.h"
#include "data_input.h"
#include "generate_data.h"
#include "test_speed.h"
#include "unit_tests.h"

int main() {
    char choice;
    bool cont = true;
    std::string file_path;
    std::vector<std::vector<double>> data;

    while (cont) {
        std::cout << "Please choose: \n(g) - data generation\n(d) - data input\n(t) - test speed\n(e) - end program" << std::endl; 
        std::cout << "Enter: ";
        std::cin >> choice;

        switch (choice) {
            case 'd':
                DataInput();
                break;
            case 'g':
                data = GenerateData();
                std::cout << "Save timing data to: ";
                std::cin >> file_path;
                SaveCsv(data, file_path);
                break;
            case 't':
                data = TestSpeed();
                std::cout << "Save data to: ";
                std::cin >> file_path;
                SaveCsv(data, file_path);
                break;
            case 'e':
                cont = false;
                break;
            case 'u':
                UnitTests();
                std::cout << "Tests are successful" << std::endl;
                break;
            default:
                std::cout << "Choice does not exist.";
        }

        std::cout << "\n\n";
    }
}