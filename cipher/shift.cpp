#include "shift.h"

void shift::Encrypt(std::ifstream &in, std::ofstream &out, int key) {
  char ch;
  while (in.get(ch)) {
    if (ch >= 'A' && ch <= 'Z')
      ch = (char) ((int)'A' + (ch - (int)'A' + key + len) % len);
    else if (ch >= 'a' && ch <= 'z')
      ch = (char) ((int)'a' + (ch - (int)'a'  + key + len) % len);
    out << ch;
  }
}

void shift::Decrypt(std::ifstream &in, std::ofstream &out, int key) {
  Encrypt(in, out, -key);
}