//
// Created by the__martian on 6/4/20.
//

#ifndef ENDECRY_DES_H
#define ENDECRY_DES_H

#include <iostream>
#include <filesystem>
#include <stack>
#include <fstream>
#include <algorithm>

namespace fs = std::filesystem;

class DES{

private: // private data
    int *   Permutation_choice_1_; // used in key_generation
    int *   Permutation_choice_2_; // used in key_generation
    int *   Initial_permutation_; // used in encoding/decoding
    int *   Inverse_permutation_; // used in encoding/decoding
    int *   Expension_table_;    // used in f function
    int *   Permutation_table_;    // used in f function
    int *** S_box_; // used in f function
    std::string  subkey_[16];

private: // private function
    std::string ValidKey(std::string key);
    static int     BinaryToDecimal(const std::string&);
    static std::string  DecimalToBinary(int);
    static std::string  XorString(std::string, std::string);
    static std::string  circular_shift_one(std::string); // shift string circularly by one char
    static std::string  circular_shift_two(std::string); // shift string circularly by two char
    std::string  f(std::string, std::string &); // f function
    void    Generate_key(std::string);
    void    Reverse_key(); // reverse the subkey_ vector
    std::string  Encrypt(std::string);
    static std::string     StringToBitString(const std::string &);
    static std::string     Padding(std::string &);
    static std::string     BinaryToAscii(const std::string &input);
public: // public function
    DES();

    void    Encrypt(fs::path&, fs::path&, const std::string &);
    void    Decrypt(fs::path&, fs::path&, const std::string &);
};

#endif //ENDECRY_DES_H
