#ifndef TESTSPEED_H
#define TESTSPEED_H
#include <string>
#include <fstream>
#include <chrono>
#include <cmath>
#include <tuple>
#include <list>

template <typename T> std::vector<std::vector<double>> TestSpeed(T &students, bool split) {
    std::vector<std::vector<double>> data;
    std::vector<double> line;
    T poor, smart;
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
        line.push_back(diff.count());

        start = std::chrono::high_resolution_clock::now();
        Sort(students);
        diff = std::chrono::high_resolution_clock::now() - start;
        std::cout << std::fixed << n << " studentu duomenu surusiavimas didejant naudojant sort: " << diff.count() << " s\n";
        line.push_back(diff.count());

        start = std::chrono::high_resolution_clock::now();
        if (split) {
            tie(poor, smart) = SplitStudents(students);
        } else {
            poor = SplitStudentsKeep(students);
        }
        diff = std::chrono::high_resolution_clock::now() - start;
        std::cout << std::fixed << n << " studentu duomenu dalijimas i dvi grupes uztruko: " << diff.count() << " s\n";
        line.push_back(diff.count());

        start = std::chrono::high_resolution_clock::now();
        WriteStudentsResultsToFile(poor, "output/" + std::to_string(n) + "_vargsiuku_rezultatai.txt");
        diff = std::chrono::high_resolution_clock::now() - start;
        std::cout << std::fixed << n << " vargsiuku studentu surasymas i faila uztruko: " << diff.count() << " s\n";
        line.push_back(diff.count());

        start = std::chrono::high_resolution_clock::now();
        if (split) {
            WriteStudentsResultsToFile(smart, "output/" + std::to_string(n) + "_kietuoliu_rezultatai.txt");
        } else {
            WriteStudentsResultsToFile(students, "output/" + std::to_string(n) + "_kietuoliu_rezultatai.txt");;
        }
        diff = std::chrono::high_resolution_clock::now() - start;
        std::cout << std::fixed << n << " kietuoliu studentu surasymas i faila uztruko: " << diff.count() << " s\n";
        line.push_back(diff.count());

        diff = std::chrono::high_resolution_clock::now() - st;
        std::cout << std::fixed << n << " studentu testas truko: " << diff.count() << " s\n\n\n";
        line.push_back(diff.count());

        data.push_back(line);

        students = T{};
        smart = T{};
        poor = T{};
        line = std::vector<double>{};
    }
    
    return data;
}

std::vector<std::vector<double>> TestSpeed();

#endif