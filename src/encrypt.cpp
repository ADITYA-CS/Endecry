/**
 * @file encrypt.cpp
 * @author Aditya Kumar Singh
 * @brief   call specific encryption algorithm
 * @details Take input file address, out file address, and
 * which algorithm to perform. There is no interaction with std I/O console
 * @bug No bug
 * @warning Don't modify with prior knowledge
 */

#include "encrypt.h"
using namespace std;

/**
 * @brief Calls appropriate function based on algorithm parameter for encryption
 *
 * @param algorithm Algorithm used for encryption
 * @param input_file Address of input file
 * @param output_file Address of output file
 */

void Encryption(const string &algorithm){
    auto input_file  = GetInputFile(); // path object
    auto output_file = GetOutputFile(input_file); // path object
    cout << input_file << "\n" << output_file <<"\n";
    ifstream in(input_file);
    ofstream out(output_file);

    if(!in || !out)
    {
        PrintCannotOpenFile();
        return;;
    }

    if(algorithm == "caesar" || algorithm == "CAESAR" || algorithm == "Caesar")
        CaeserCipherEncode(in, out);
    else if(algorithm == "shift" || algorithm == "SHIFT" || algorithm == "Shift")
        ShiftCipherEncode(in,out);
    else if(algorithm == "XOR" || algorithm == "Xor" || algorithm == "xor")
        XorCipherEncode(in, out);
    else if(algorithm == "vigenere" || algorithm == "VIGENERE" || algorithm == "Vigenere")
        VigenereCipherEncode(in,out);
}

/**
 * @brief Encryption based on Caesar cipher
 * @param input Input stream
 * @param output Output stream
 */

void CaeserCipherEncode(ifstream &input, ofstream &output)
{
    Caeser object(3);   // Caesar Class Object with key 3

    object.Encrypt(input, output);
}

/**
 * @brief Encryption based on Caesar cipher with key may / may not equal to 3
 * @param input Input stream
 * @param output Output stream
 */

void ShiftCipherEncode(ifstream &input, ofstream &output)
{
    int key;    // key for Encryption
    cout << "Key : ";
    cin >> key;
    Caeser object(key);     // Caesar Class Object

    object.Encrypt(input, output);
}

/**
 * @brief Encryption based on XOR cipher
 * @param input Input stream
 * @param output Output stream
 */

void XorCipherEncode(ifstream &input, ofstream &output)
{
    string key;     // key for encryption
    cout << "Key : ";
    cin >> key;
    Xor object(key);    // Xor Class Object

    object.Encrypt(input, output);
}

/**
 * @brief Encryption based on Vigenere cipher
 * @param input Input stream
 * @param output Output stream
 */

void VigenereCipherEncode(ifstream &input, ofstream &output)
{
    string key;     // key for encryption
    cout << "Key : ";
    cin >> key;
    Vigenere object(key);  // Vigenere Class Object

    object.Encrypt(input, output);
}