/**
 * @file caesar.h
 * @author Aditya Kumar Singh
 * @brief   Header file, Contain class declaration for caesar cipher algorithm
 * @details Refer wikipedia/other source for more working of Caesar cipher
 * @warning Don't modify with prior knowledge
 */


#ifndef ENDECRY_CAESAR_H
#define ENDECRY_CAESAR_H


#include <iostream>
#include <fstream>

/**
 * @brief Caesar class
 *
 */

class Caeser
{
private:
    /**
     * @brief it tell how much you have to shift the letter to right in english alphabet
     */
    const int offset_;
    /**
     * @brief it is a const number 26, see caesar cipher for details
     */
    const int modular_;
public:
    explicit Caeser(int);
    void Encrypt(std::ifstream &, std::ofstream &) const;
    void Decrypt(std::ifstream &, std::ofstream &) const;
};


#endif //ENDECRY_CAESAR_H