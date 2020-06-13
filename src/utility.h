/**
 * @file utility.h
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

void    welcome();
void    ErrorMessage();
void    PrintAlgorithmOption();
void    PrintHashOption();
void    PrintError();
void    PrintCannotOpenFile();
int     StringToInt(const std::string&);
char    TaskToPerform();
fs::path GetInputFile();
fs::path  GetOutputFile(const fs::path &);
std::string  GetAlgorithm(int);
std::string  CharStarToString(const char *);


#endif //ENDECRY_UTILITY_H