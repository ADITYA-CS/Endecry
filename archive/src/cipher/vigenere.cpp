

#include "vigenere.h"

Vigenere :: Vigenere(std::string s) : modular_(26)
{
    key_ = "";
    for(size_t i = 0; s[i]; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
            key_ += s[i] - 'a' + 'A';
        else
            key_ += s[i];
    }
}

void Vigenere :: Encrypt(std::ifstream &in, std::ofstream &out)
{
    size_t key_len = key_.size(), i = 0;
    char ch;
    while(in.get(ch))
    {
        if(ch >= 'a' && ch <= 'z')
            ch = (ch - 'a' + key_[i]  - 'A') % modular_ + 'a';
        else if(ch >= 'A' && ch <= 'Z')
            ch = (ch - 'A' + key_[i]  - 'A') % modular_ + 'A';
        i = (i + 1) % key_len;
        out << ch;
    }
    in.close();
    out.close();
}

void Vigenere :: Decrypt(std::ifstream &in, std::ofstream &out)
{
    size_t key_len = key_.size(), i = 0;
    char ch;
    while(in.get(ch))
    {
        if(ch >= 'a' && ch <= 'z')
            ch = (ch - 'a' - key_[i]  + 'A' + modular_) % modular_ + 'a';
        else if(ch >= 'A' && ch <= 'Z')
            ch = (ch - 'A' - key_[i]  + 'A' + modular_) % modular_ + 'A';
        i = (i + 1) % key_len;
        out << ch;
    }
    in.close();
    out.close();
}