/**
 * @file decrypt.h
 * @author Aditya Kumar Singh
 * @brief   Header file, function defined in decrypt.cpp
 * @details Take input file address, out file address, and
 * which algorithm to perform. There is no interaction with std I/O console
 * It is dependency file for main.cpp
 * @bug No bug
 * @warning Don't modify with prior knowledge
 */

#ifndef ENDECRY_DECRYPT_H
#define ENDECRY_DECRYPT_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include "utility.h"
#include "cipher/caesar.h"
#include "cipher/xor.h"
#include "cipher/vigenere.h"

namespace fs = std::filesystem;

using namespace  std;

void Decryption(const string &);
void CaeserCipherDecode(ifstream &, ofstream &);
void ShiftCipherDecode(ifstream &, ofstream &);
void XorCipherDecode(ifstream &, ofstream &);
void VigenereCipherDecode(ifstream &, ofstream &);

#endif //ENDECRY_DECRYPT_H