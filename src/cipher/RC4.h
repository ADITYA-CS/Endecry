#ifndef ENDECRY_RC4_H
#define ENDECRY_RC4_H
#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

class RC4{
private:
    int s_[256];
public:
    RC4(string);
    void Encrypt(fs::path &);
    void Decrypt(fs::path &);
};
#endif //ENDECRY_RC4_H
