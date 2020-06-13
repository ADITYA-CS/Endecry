/**
 * @file decrypt.h
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
#include "cipher/DES.h"
#include "cipher/RC4.h"

namespace fs = std::filesystem;


void Decryption(const std::string &);


#endif //ENDECRY_DECRYPT_H