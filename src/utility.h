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
using namespace std;

void    ErrorMessage();
void    PrintAlgorithmOption();
void    PrintCannotOpenFile();
void    PrintHelpPage();
int     StringToInt(string);
char    TaskToPerform();
string  GetInputFile();
string  GetOutputFile(const string &);
string  GetAlgorithm();
string  CharStarToString(const char *);

#endif //ENDECRY_UTILITY_H