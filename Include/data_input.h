#ifndef DATAINPUT_H
#define DATAINPUT_H

template <typename T> void ReadDataFromConsole(T &students);

template <typename T> void ReadDataFromFile(T &students, std::string filePath);

template <typename T> void DataInput(T &students, bool split = true);

void DataInput();

#endif