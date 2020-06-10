
#include "RC4.h"

/*
int main(){
    fs::path p;
    cout << ": ";
    cin >> p;
    string key;
    cout << ": ";
    cin >> key;
    RC4 rc(key);
    rc.Encrypt(p);
    p += ".endecry";
    rc.Decrypt(p);
}*/

RC4 :: RC4(string key){
    for(int i = 0; i  < 256; i++){
        s_[i] = i;
    }
    int len = key.size(), j;
    for(int i = 0; i < 256; i++){
        j = (j + s_[i] + (int)key[i % len]) % 256;
        std::swap(s_[i], s_[j]);
    }
}

void RC4 :: Encrypt(fs::path &input){
    fs::path output = input;
    output += ".endecry";
    std::ifstream in;
    std::ofstream out;

    try{
        in.open(input);
        if(!in.is_open()){
            throw string("Error opening input file");
        }
        out.open(output, ios::out);
        if(!out.is_open()){
            throw string("Error opening output file");
        }
    } catch (const string & e){
        cout << e  <<  "\n";
        exit(601);
    }

    char ch;
    unsigned int temp, i = 0, j = 0, k;
    while(in.get(ch)){
        temp = (unsigned int)ch;
        i = (i + 1) % 256;
        j = (j + s_[i]) % 256;
        std::swap(s_[i], s_[j]);
        k = s_[s_[i] + s_[j]] % 256;
        out << (char) (k ^ temp);
    }

    in.close();
    out.close();
}

void RC4 :: Decrypt(fs::path &input){
    Encrypt(input);
}
