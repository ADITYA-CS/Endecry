/**
 * @file decrypt.cpp
 * @brief   call specific decryption algorithm
 * @details Take input file address, out file address, and
 * which algorithm to perform. There is no interaction with std I/O console
 * @bug No bug
 * @warning Don't modify with prior knowledge
 */


#include "decrypt.h"


// local function
void CaeserCipherDecode(std::ifstream &, std::ofstream &);
void ShiftCipherDecode(std::ifstream &, std::ofstream &);
void XorCipherDecode(std::ifstream &, std::ofstream &);
void VigenereCipherDecode(std::ifstream &, std::ofstream &);
void DESCipherDecode(fs::path &);
void ThreeDESCipherDecode(fs::path &);
void RC4CipherDecode(fs::path &);
/**
 * @brief Calls appropriate function based on algorithm parameter for decryption
 * @param algorithm Algorithm used for decryption
 * @param input_file Address of input file
 * @param output_file Address of output file
 */

void Decryption(const std::string &algorithm)
{

    auto input_file  = GetInputFile();
    auto output_file = GetOutputFile(input_file);
    std::ifstream in(input_file);    // input stream
    std::ofstream out(output_file);  // output stream

    if(!in || !out)
    {
        PrintCannotOpenFile();
        return;
    }

    if(algorithm == "caesar" || algorithm == "CAESAR" || algorithm == "Caesar")
        CaeserCipherDecode(in, out);
    else if(algorithm == "shift" || algorithm == "SHIFT" || algorithm == "Shift")
        ShiftCipherDecode(in,out);
    else if(algorithm == "XOR" || algorithm == "Xor" || algorithm == "xor")
        XorCipherDecode(in, out);
    else if(algorithm == "vigenere" || algorithm == "VIGENERE" || algorithm == "Vigenere")
        VigenereCipherDecode(in,out);
    else if(algorithm == "DES" || algorithm == "Des" || algorithm == "des")
        DESCipherDecode(input_file);
    else if(algorithm == "RC4" || algorithm == "Rc4" || algorithm == "rc4")
        RC4CipherDecode(input_file);
    else if(algorithm == "3DES" || algorithm == "3des" || algorithm == "3Des")
        ThreeDESCipherDecode(input_file);
}


/**
 * @brief Decryption based on Caesar cipher
 * @param input Input stream
 * @param output Output stream
 */

void CaeserCipherDecode(std::ifstream &input, std::ofstream &output)
{
    Caeser object(23);   // Caesar Class Object with key 3

    object.Decrypt(input, output);
}



/**
 * @brief Decryption based on Caesar cipher with key may / may not equal to 3
 * @param input Input stream
 * @param output Output stream
 */

void ShiftCipherDecode(std::ifstream &input, std::ofstream &output)
{
    int key;    // key for decryption
    std::cout << "Key : ";
    std::cin >> key;
    Caeser object(key);     // Caesar Class Object

    object.Decrypt(input, output);
}


/**
 * @brief Decryption based on XOR cipher
 * @param input Input stream
 * @param output Output stream
 */

void XorCipherDecode(std::ifstream &input, std::ofstream &output)
{
    std::string key;     // key for decryption
    std::cout << "Key : ";
    std::cin >> key;
    Xor object(key);    // Xor Class Object

    object.Decrypt(input, output);
}


/**
 * @brief Decryption based on Vigenere cipher
 * @param input Input stream
 * @param output Output stream
 */

void VigenereCipherDecode(std::ifstream &input, std::ofstream &output)
{
    std::string key;     // key for decryption
    std::cout << "Key : ";
    std::cin >> key;
    Vigenere object(key);  // Vigenere Class Object

    object.Decrypt(input, output);
}

void DESCipherDecode(fs::path &input){
    std::string key;
    std::cout << "Key must be 8 ascii characters or bit string of size 64\n";
    std::cout << "Enter key\n: ";
    std::cin >> key;
    fs::path output = input;
    output += ".endecry";


    DES des;
    des.Decrypt(input, output, key);
}

void ThreeDESCipherDecode(fs::path &input){
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

    des1.Decrypt(input, output, key3);
    des2.Encrypt(output, temp, key2);
    des3.Decrypt(temp, output, key1);

    fs::remove(temp);
}

void RC4CipherDecode(fs::path &input){
    std::string key;
    std::cout << "Enter key\n: ";
    std::cin >> key;
    RC4 rc(key);
    rc.Decrypt(input);
}