/**
 * @file main.cpp
 * @author Aditya Kumar Singh
 * @brief   The main file
 * @details Handle command line arguments, generate input and output file
 * and also figure out which algorithm to use for decryption/encryption or which
 * algorithm to use for hashing.
 * @bug No bug
 * @warning Don't modify without prior knowledge
 */

#include <iostream>
#include "utility.h"
#include "encrypt.h"
#include "decrypt.h"
#include "information.h"
#include "hash.h"

using namespace  std;

#define MESSAGE 0
#define ENCRYPT 1
#define DECRYPT 2
#define HASH    3

int main(int argc, char const *argv[]){
    string input_file;
    string output_file;
    string algorithm;
    int what_to_do = MESSAGE;
    if(argc == 1){
        char task = TaskToPerform();
        if (task == 'h')
            PrintHelpPage();
        else if(task == 'i')
            PrintInformation();
        else {
            algorithm   = GetAlgorithm();
        }
        if (task == 'E') {
            what_to_do = ENCRYPT;
        } else if (task == 'D') {
            what_to_do = DECRYPT;
        } else if (task == 'H') {
            what_to_do = HASH;
        }
        if(task == 'E' || task == 'D'){
            input_file  = GetInputFile();
            output_file = GetOutputFile(input_file);
        }
    }
    else if(argc == 2){
        string argument_1 = CharStarToString(argv[1]);
        if (argument_1 == "-h" || argument_1 == "-help")
            PrintHelpPage();
        else if(argument_1 == "-i" || argument_1 == "-I")
            PrintInformation();
        else if(argument_1 == "-E" || argument_1 == "-e"){
            what_to_do  = ENCRYPT;
            algorithm   = GetAlgorithm();
            input_file  = GetInputFile();
            output_file = GetOutputFile(input_file);
        }
        else if(argument_1 == "-D" || argument_1 == "-d"){
            what_to_do  = DECRYPT;
            algorithm   = GetAlgorithm();
            input_file  = GetInputFile();
            output_file = GetOutputFile(input_file);
        }
        else if (argument_1 == "-H" || argument_1 == "-hash"){
            what_to_do = HASH;
            algorithm   = GetAlgorithm();
        }
        else{
            ErrorMessage();
        }
    }
    else{
        ErrorMessage();
    }

    if(what_to_do == ENCRYPT)
        Encryption(algorithm, input_file, output_file);
    else if(what_to_do == DECRYPT)
        Decryption(algorithm, input_file, output_file);
    else if(what_to_do == HASH)
        HashMe(algorithm);
    return 0;
}