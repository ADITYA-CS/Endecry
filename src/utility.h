/**
 * @file utility.h
 * @author Aditya Kumar Singh
 * @brief   Header file, function defined in utility.cpp
 * @details For details information see utility.cpp
 * @bug No bug
 * @warning Don't modify with prior knowledge
 */

#ifndef ENDECRY_UTILITY_H
#define ENDECRY_UTILITY_H

#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;

void    ErrorMessage();
void    PrintAlgorithmOption();
void    PrintError();
void    PrintCannotOpenFile();
void    PrintHelpPage();
int     StringToInt(const string&);
char    TaskToPerform();
fs::path GetInputFile();
fs::path  GetOutputFile(const fs::path &);
string  GetAlgorithm();
string  CharStarToString(const char *);

#endif //ENDECRY_UTILITY_H