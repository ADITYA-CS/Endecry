//
// Created by the__martian on 5/13/20.
//

#ifndef ENDECRY_XOR_H
#define ENDECRY_XOR_H


#include <iostream>
#include <fstream>
#include <iomanip>

/*
input: take key to encrypt the plain-text and Decrypt the cipher-text
*/
class Xor
{
private:
    std::string key_;
public:
    explicit Xor(std::string);
    void Encrypt(std::ifstream &, std::ofstream &);
    void Decrypt(std::ifstream &, std::ofstream &);
};


#endif //ENDECRY_XOR_H