#include "vigenere.h"

bool Vigenere::ValidateKey(std::string &key) {
  for (auto &ch : key) {
    if (isupper(ch))
      ch = (char) (ch - 'A' + 'a');
    else if (islower(ch)) {}
    else return false;
  }
  return true;
}

void Vigenere::Encrypt(std::ifstream &in, std::ofstream &out, std::string &key) {
  if (!ValidateKey(key)) {
    throw std::invalid_argument("Bad key");
  }
  char ch;
  int i = 0, key_len = key.size();
  while (in.get(ch)) {
    if (islower(ch)) {
      ch = (char) ('a' + (ch - 'a' + key[i] - 'a') % len);
    } else if ((isupper(ch))) {
      ch = (char) ('A' + (ch - 'A' + key[i] - 'a') % len);
    }
    out << ch;
    i = (i + 1) % key_len;
  }
}

void Vigenere::Decrypt(std::ifstream &in, std::ofstream &out, std::string &key) {
  if (!ValidateKey(key)) {
    throw std::invalid_argument("Bad key");
  }
  char ch;
  int i = 0, key_len = key.size();
  while (in.get(ch)) {
    if (islower(ch)) {
      ch = (char) ('a' + (ch - 'a' - key[i] + 'a' + len) % len);
    } else if ((isupper(ch))) {
      ch = (char) ('A' + (ch - 'A' - key[i] + 'a' + len) % len);
    }
    out << ch;
    i = (i + 1) % key_len;
  }
}