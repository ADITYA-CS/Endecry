/**
 * @file caesar.cpp
 * @author Aditya Kumar Singh
 * @brief   Contain class definition for caesar cipher algorithm
 * @details Refer wikipedia/other source for more working of Caesar cipher
 * @warning Don't modify with prior knowledge
 */


#include "caesar.h"


/**
 * @brief A constructor
 * @details
 * Assign n to offset_
 * set modular_ to 26
 * @param n integer key for shift cipher, n = 3 in case of caesar cipher
 */
Caeser :: Caeser(int n) : offset_(n), modular_(26){}

/**
 * @brief Encryption function
 * @details read a file char by char from input stream and perform caesar cipher encoding on each char
 * and store that in output file specified by output stream
 * @param in Input stream that open file as text
 * @param out Output stream that contain encrypted text
 */
void Caeser :: Encrypt(ifstream &in, ofstream &out) const
{
    char ch;
    while(in)
    {
        in.get(ch);
        if(!in)
            break;
        if(ch >= 'a' && ch <= 'z')
            ch = (ch - 'a' + offset_) % modular_ + 'a';
        else if(ch >= 'A' && ch <= 'Z')
            ch = (ch - 'A' + offset_) % modular_ + 'A';
        out << ch;
    }
    in.close();
    out.close();
}

/**
 * @brief Decryption function
 * @details read a file char by char from input stream and perform caesar cipher decoding on each char
 * and store that in output file specified by output stream
 * @param in Input stream that open file as text
 * @param out Output stream that contain decrypted text
 */
void Caeser :: Decrypt(ifstream &in, ofstream &out) const
{
    char ch;
    while(in)
    {
        in.get(ch);
        if(!in)
            break;
        if(ch >= 'a' && ch <= 'z')
            ch = (ch - 'a' + modular_ - offset_) % modular_ + 'a';
        else if(ch >= 'A' && ch <= 'Z')
            ch = (ch - 'A' + modular_ - offset_) % modular_ + 'A';
        out << ch;
    }
    in.close();
    out.close();
}