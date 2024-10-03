#ifndef HELPER_H
#define HELPER_H
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>

double Mean(std::vector<int> grades) {
    double sum = 0;
    for (int grade : grades) {
        sum += grade;
    }

    return sum / grades.size();
}

double Median(std::vector<int> grades) {
    std::vector<int> v_sorted(grades.size());
    std::partial_sort_copy(begin(grades), end(grades), begin(v_sorted), end(v_sorted));

    if (v_sorted.size() % 2 == 0) {
        return (v_sorted[v_sorted.size() / 2] + v_sorted[v_sorted.size() / 2 - 1]) / 2;
    }
    return v_sorted[v_sorted.size() / 2];
}

std::string ConvertDoubleToString(double d) {
    std::ostringstream oss;
    oss.precision(2);
    oss << std::fixed << d;
    return oss.str();
}

std::string PadTo(std::string str, size_t num, bool pad_right = false, char paddingChar = ' ')
{
    std::string str_copy = str;
    if(num > str.size())
        if (pad_right) {
            str_copy.insert(0, num - str.size(), paddingChar);
        }
        else {
            str_copy.insert(str.size(), num - str.size(), paddingChar);
        }

    return str_copy;
}

#endif