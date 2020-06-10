
#include "hash.h"

/**
 *  Local function definition
 */

void CallMd2(string);
void CallMd2(ifstream &, ofstream &);

void HashMe(string algorithm){
    cout << "\t-----------------------------------------------------------------\n";
    string message;
    cout << "\tMessage : ";
    cin >> message;
    CallMd2(message);
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