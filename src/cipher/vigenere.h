//
// Created by the__martian on 5/13/20.
//

#ifndef ENDECRY_VIGENERE_H
#define ENDECRY_VIGENERE_H


#include <iostream>
#include <fstream>
using namespace std;

class Vigenere
{
private:
    string key_;
    const int modular_;
public:
    [[maybe_unused]] explicit Vigenere(string);
    void Encrypt(ifstream&, ofstream&);
    void Decrypt(ifstream&, ofstream&);
};


#endif //ENDECRY_VIGENERE_H