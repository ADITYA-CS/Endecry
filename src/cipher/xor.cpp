//
// Created by the__martian on 5/13/20.
//
#include "xor.h"

Xor :: Xor(std::string s) : key_(s){}

void Xor :: Encrypt(std::ifstream &in, std::ofstream &out)
{
    size_t key_len = key_.size(), i = 0;
    char ch;
    while(in.get(ch))
    {
        if(!ch)
            break;
        int temp = ch ^ key_[i];
        i = (i + 1) % key_len;
        out << std::setw(2) << std::setfill('0') << std::hex << temp << ' ';
    }
    in.close();
    out.close();
}

void Xor :: Decrypt(std::ifstream &in, std::ofstream &out)
{
    char ch;
    int hexa;
    size_t key_len = key_.size(), i = 0;
    while(in)
    {
        in >> std::hex >> hexa; //reads a hexadecimal number
        ch = (char) ((int)key_[i] ^ hexa);
        i = (i + 1) % key_len;
        out << ch;
        in.get(ch);
        if(!ch)
            break;
    }
    in.close();
    out.close();
}
