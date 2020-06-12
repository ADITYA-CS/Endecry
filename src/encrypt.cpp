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

// local function
void CaeserCipherEncode(std::ifstream &, std::ofstream &);
void ShiftCipherEncode(std::ifstream &, std::ofstream &);
void XorCipherEncode(std::ifstream &, std::ofstream &);
void VigenereCipherEncode(std::ifstream &, std::ofstream &);
void DESCipherEncode(fs::path &);
void ThreeDESCipherEncode(fs::path &);
void RC4CipherEncode(fs::path &);

/**
 * @brief Calls appropriate function based on algorithm parameter for encryption
 *
 * @param algorithm Algorithm used for encryption
 * @param input_file Address of input file
 * @param output_file Address of output file
 */
void Encryption(const std::string &algorithm){
    auto input_file  = GetInputFile(); // path object
    auto output_file = GetOutputFile(input_file); // path object
    // std::cout << input_file << "\n" << output_file <<"\n";
    std::ifstream in(input_file);
    std::ofstream out(output_file);

    if(!in || !out)
    {
        PrintCannotOpenFile();
        return;
    }

    if(algorithm == "caesar" || algorithm == "CAESAR" || algorithm == "Caesar")
        CaeserCipherEncode(in, out);
    else if(algorithm == "shift" || algorithm == "SHIFT" || algorithm == "Shift")
        ShiftCipherEncode(in,out);
    else if(algorithm == "XOR" || algorithm == "Xor" || algorithm == "xor")
        XorCipherEncode(in, out);
    else if(algorithm == "vigenere" || algorithm == "VIGENERE" || algorithm == "Vigenere")
        VigenereCipherEncode(in,out);
    else if(algorithm == "DES" || algorithm == "Des" || algorithm == "des")
        DESCipherEncode(input_file);
    else if(algorithm == "RC4" || algorithm == "Rc4" || algorithm == "rc4")
        RC4CipherEncode(input_file);
    else if(algorithm == "3DES" || algorithm == "3des" || algorithm == "3Des")
        ThreeDESCipherEncode(input_file);
}

/**
 * @brief Encryption based on Caesar cipher
 * @param input Input stream
 * @param output Output stream
 */

void CaeserCipherEncode(std::ifstream &input, std::ofstream &output)
{
    Caeser object(3);   // Caesar Class Object with key 3

    object.Encrypt(input, output);
}

/**
 * @brief Encryption based on Caesar cipher with key may / may not equal to 3
 * @param input Input stream
 * @param output Output stream
 */

void ShiftCipherEncode(std::ifstream &input, std::ofstream &output)
{
    int key;    // key for Encryption
    std::cout << "Key : ";
    std::cin >> key;
    Caeser object(key);     // Caesar Class Object

    object.Encrypt(input, output);
}

/**
 * @brief Encryption based on XOR cipher
 * @param input Input stream
 * @param output Output stream
 */

void XorCipherEncode(std::ifstream &input, std::ofstream &output)
{
    std::string key;     // key for encryption
    std::cout << "Key : ";
    std::cin >> key;
    Xor object(key);    // Xor Class Object

    object.Encrypt(input, output);
}

/**
 * @brief Encryption based on Vigenere cipher
 * @param input Input stream
 * @param output Output stream
 */

void VigenereCipherEncode(std::ifstream &input, std::ofstream &output)
{
    std::string key;     // key for encryption
    std::cout << "Key : ";
    std::cin >> key;
    Vigenere object(key);  // Vigenere Class Object

    object.Encrypt(input, output);
}

void DESCipherEncode(fs::path &input){
    std::string key;
    std::cout << "Key must be 8 ascii characters or bit string of size 64\n";
    std::cout << "Enter key\n: ";
    std::cin >> key;
    fs::path output = input;
    output += ".endecry";

    DES des;
    des.Encrypt(input, output, key);
}

void ThreeDESCipherEncode(fs::path &input){
    std::string key1, key2, key3;
    std::cout << "Key must be 8 ascii characters or bit string of size 64\n";
    std::cout << "Enter 1st key\n: ";
    std::cin >> key1;
    std::cout << "Enter 2nd key\n: ";
    std::cin >> key2;
    std::cout << "Enter 3rd key\n: ";
    std::cin >> key3;


    fs::path output = input, temp = input;
    output += ".endecry";
    temp += ".temp";

    DES des1, des2, des3;

    des1.Encrypt(input, output, key1);
    des2.Decrypt(output, temp, key2);
    des3.Encrypt(temp, output, key3);

    fs::remove(temp);
}

void RC4CipherEncode(fs::path &input){
    std::string key;
    std::cout << "Enter key\n: ";
    std::cin >> key;
    RC4 rc(key);
    rc.Encrypt(input);
}