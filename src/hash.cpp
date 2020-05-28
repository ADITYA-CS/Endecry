
#include "hash.h"

/**
 *  Local function definition
 */

void CallMd2(string);
void CallMd2(ifstream &, ofstream &);

void HashMe(string algorithm){
    string option;
    cout << "\t-----------------------------------------------------------------\n";
    cout << "\tWhat do you want to hash?\n";
    cout << "\t1. String\n";
    cout << "\t2. File\n";
    cout << "\tOption: ";
    cin >> option;
    int op = StringToInt(option);
    while(op < 1 || op > 2){
        cout << "\tWrong option\n";
        cout << "\tOption: ";
        cin >> option;
        op = StringToInt(option);
    }
    cout << "\t-----------------------------------------------------------------\n\v";
    cout << "\t-----------------------------------------------------------------\n";
    if(op == 1){
        string message;
        cout << "\tMessage : ";
        cin >> message;
        algorithm = "MD2";
        if(algorithm == "MD2"){
            CallMd2(message);
        }
    }
    else{
        //TODO file implementation
    }


    cout << "\t-----------------------------------------------------------------\n";
}

void CallMd2(string input){
    MD2 md;
    unsigned char digest[16];
    unsigned int len = input.size();
    unsigned  char message[len];
    for(int i = 0; i < len; i++){
        message[i] = input[i];
    }
    Init(&md);
    Update(&md, message, len);
    Final(digest, &md);
    cout << "\tMD2 hash : ";
    for(int i = 0; i < 16; i++){
        printf("%02x", digest[i]);
    }
    cout << "\n";
}
void CallMd2(ifstream &, ofstream &);