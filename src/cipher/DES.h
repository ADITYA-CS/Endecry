//
// Created by the__martian on 6/4/20.
//

#ifndef ENDECRY_DES_H
#define ENDECRY_DES_H

#include <iostream>
#include <stack>

using namespace std;

class DES{

private: // private data
    int *   Permutation_choice_1_; // used in key_generation
    int *   Permutation_choice_2_; // used in key_generation
    int *   Initial_permutation_; // used in encoding/decoding
    int *   Inverse_permutation_; // used in encoding/decoding
    int *   Expension_table_;    // used in f function
    int *   Permutation_table_;    // used in f function
    int *** S_box_; // used in f function
    string  subkey_[16];

private: // private function
    static int     BinaryToDecimal(const string&);
    static string  DecimalToBinary(int);
    static string  XorString(string, string);
    static string  circular_shift_one(string); // shift string circularly by one char
    static string  circular_shift_two(string); // shift string circularly by two char
    string  f(string, string); // f function

public: // public function
    DES();
    void    generate_key(string);
    string  Encrypt(string);
    string  Decrypt(string);
    void    reverse_key(); // reverse the subkey_ vector
};

#endif //ENDECRY_DES_H
