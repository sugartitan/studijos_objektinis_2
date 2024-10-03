#include <string>
#include <fstream>
#include <chrono>
#include <cmath>
#include <tuple>
#include "Student.h"
#include "Exceptions.h"
#include "helper.h"
#include "test_speed.h"

void TestSpeed() {
    std::vector<Student> students, poor, smart;
    std::string single_line, file_path;
    int n, n_grades = 15;
    auto start = std::chrono::high_resolution_clock::now();
    auto st = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff;

    for (int i = 3; i <= 7; i++) {
        n = std::pow(10, i);
        file_path = "generated_data/studentai" + std::to_string(n) + ".txt";

        st = std::chrono::high_resolution_clock::now();

        start = std::chrono::high_resolution_clock::now();
        ReadDataFromFile(students, file_path);
        diff = std::chrono::high_resolution_clock::now() - start;
        std::cout << std::fixed << n << " studentu duomenu nuskaitymas is failo uztruko: " << diff.count() << " s\n";

        start = std::chrono::high_resolution_clock::now();
        std::sort(students.begin(), students.end(), CompareStudents);
        diff = std::chrono::high_resolution_clock::now() - start;
        std::cout << std::fixed << n << " studentu duomenu surusiavimas didejant naudojant sort: " << diff.count() << " s\n";

        start = std::chrono::high_resolution_clock::now();
        tie(poor, smart) = SplitStudents(students);
        diff = std::chrono::high_resolution_clock::now() - start;
        std::cout << std::fixed << n << " studentu duomenu dalijimas i dvi grupes uztruko: " << diff.count() << " s\n";

        start = std::chrono::high_resolution_clock::now();
        WriteStudentsResultsToFile(poor, "output/" + std::to_string(n) + "_vargsiuku_rezultatai.txt");
        diff = std::chrono::high_resolution_clock::now() - start;
        std::cout << std::fixed << n << " vargsiuku studentu surasymas i faila uztruko: " << diff.count() << " s\n";

        start = std::chrono::high_resolution_clock::now();
        WriteStudentsResultsToFile(smart, "output/" + std::to_string(n) + "_kietuoliu_rezultatai.txt");
        diff = std::chrono::high_resolution_clock::now() - start;
        std::cout << std::fixed << n << " kietuoliu studentu surasymas i faila uztruko: " << diff.count() << " s\n";

        diff = std::chrono::high_resolution_clock::now() - st;
        std::cout << std::fixed << n << " studentu testas truko: " << diff.count() << " s\n\n\n";
    }
}