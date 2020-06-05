//
// Created by the__martian on 5/13/20.
//

#ifndef ENDECRY_VIGENERE_H
#define ENDECRY_VIGENERE_H


#include <iostream>
#include <fstream>

class Vigenere
{
private:
    std::string key_;
    const int modular_;
public:
    Vigenere(std::string);
    void Encrypt(std::ifstream&, std::ofstream&);
    void Decrypt(std::ifstream&, std::ofstream&);
};


#endif //ENDECRY_VIGENERE_H