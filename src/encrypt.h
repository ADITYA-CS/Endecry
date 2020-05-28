/**
 * @file encrypt.h
 * @author Aditya Kumar Singh
 * @brief   Header file, function defined in encrypt.cpp
 * @details Take input file address, out file address, and
 * which algorithm to perform. There is no interaction with std I/O console
 * It is dependency file for main.cpp
 * @bug No bug
 * @warning Don't modify with prior knowledge
 */

#ifndef ENDECRY_ENCRYPT_H
#define ENDECRY_ENCRYPT_H

#include <iostream>
#include <fstream>
#include "utility.h"
#include "cipher/caesar.h"
#include "cipher/xor.h"
#include "cipher/vigenere.h"

using namespace  std;

void Encryption(const string &,const string &, const string &);
void CaeserCipherEncode(ifstream &, ofstream &);
void ShiftCipherEncode(ifstream &, ofstream &);
void XorCipherEncode(ifstream &, ofstream &);
void VigenereCipherEncode(ifstream &, ofstream &);

#endif //ENDECRY_ENCRYPT_H