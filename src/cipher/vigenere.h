#ifndef ENDECRY_SRC_CIPHER_VIGENERE_H_
#define ENDECRY_SRC_CIPHER_VIGENERE_H_
#include <fstream>

class Vigenere {
  static const int len = 26;
 public:
  Vigenere() = delete;
  ~Vigenere() = default;
  Vigenere(const Vigenere &) = delete;
  Vigenere(Vigenere &&) = delete;
  Vigenere &operator=(const Vigenere &) = delete;
  Vigenere &operator=(Vigenere &&) = delete;
  static bool ValidateKey(std::string &key);
  static void Encrypt(std::ifstream &in, std::ofstream &out, std::string &key);
  static void Decrypt(std::ifstream &in, std::ofstream &out, std::string &key);
};

#endif //ENDECRY_SRC_CIPHER_VIGENERE_H_
