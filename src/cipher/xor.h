//
// Created by the__martian on 5/13/20.
//

#ifndef ENDECRY_XOR_H
#define ENDECRY_XOR_H


#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

/*
input: take key to encrypt the plain-text and Decrypt the cipher-text
*/
class Xor
{
private:
    string key_;
public:
    explicit Xor(string);
    void Encrypt(ifstream &, ofstream &);
    void Decrypt(ifstream &, ofstream &);
};


#endif //ENDECRY_XOR_H