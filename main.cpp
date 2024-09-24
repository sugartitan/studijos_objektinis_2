#include <string>
#include <vector>
#include <fstream>
#include <iostream>

struct Student {
    std::string name, last_name;
    std::vector<int> grades = { 0 };
    int egzam_grade;
};

void ReadData(Student &student) {

}

void ReadDataFromFile(std::vector<Student> &students, std::string filePath) {
    std::ifstream file;
    std::string my_string;
    file.open(filePath);
    file >> my_string;
    std::cout << my_string;
}

int main() {
    std::vector<Student> students;
    std::string file_path = "studentai.txt";

    ReadDataFromFile(students, file_path);

    return 0;
}