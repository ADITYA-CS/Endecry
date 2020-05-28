/**
 * @file decrypt.cpp
 * @author Aditya Kumar Singh
 * @brief   call specific decryption algorithm
 * @details Take input file address, out file address, and
 * which algorithm to perform. There is no interaction with std I/O console
 * @bug No bug
 * @warning Don't modify with prior knowledge
 */


#include "decrypt.h"
using namespace std;



/**
 * @brief Calls appropriate function based on algorithm parameter for decryption
 * @param algorithm Algorithm used for decryption
 * @param input_file Address of input file
 * @param output_file Address of output file
 */

void Decryption(const string &algorithm,
                const string &input_file,
                const string &output_file)
{

    ifstream in(input_file);    // input stream
    ofstream out(output_file);  // output stream

    if(!in || !out)
    {
        PrintCannotOpenFile();
        return;;
    }

    if(algorithm == "caesar")
        CaeserCipherDecode(in, out);
    else if(algorithm == "shift")
        ShiftCipherDecode(in,out);
    else if(algorithm == "XOR")
        XorCipherDecode(in, out);
    else if(algorithm == "vigenere")
        VigenereCipherDecode(in,out);
}


/**
 * @brief Decryption based on Caesar cipher
 * @param input Input stream
 * @param output Output stream
 */

void CaeserCipherDecode(ifstream &input, ofstream &output)
{
    Caeser object(3);   // Caesar Class Object with key 3

    object.Decrypt(input, output);
}



/**
 * @brief Decryption based on Caesar cipher with key may / may not equal to 3
 * @param input Input stream
 * @param output Output stream
 */

void ShiftCipherDecode(ifstream &input, ofstream &output)
{
    int key;    // key for decryption
    cout << "Key : ";
    cin >> key;
    Caeser object(key);     // Caesar Class Object

    object.Decrypt(input, output);
}


/**
 * @brief Decryption based on XOR cipher
 * @param input Input stream
 * @param output Output stream
 */

void XorCipherDecode(ifstream &input, ofstream &output)
{
    string key;     // key for decryption
    cout << "Key : ";
    cin >> key;
    Xor object(key);    // Xor Class Object

    object.Decrypt(input, output);
}


/**
 * @brief Decryption based on Vigenere cipher
 * @param input Input stream
 * @param output Output stream
 */

void VigenereCipherDecode(ifstream &input, ofstream &output)
{
    string key;     // key for decryption
    cout << "Key : ";
    cin >> key;
    Vigenere object(key);  // Vigenere Class Object

    object.Decrypt(input, output);
}