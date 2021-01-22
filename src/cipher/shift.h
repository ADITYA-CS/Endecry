#ifndef ENDECRY_CIPHER_SHIFT_H_
#define ENDECRY_CIPHER_SHIFT_H_
#include <fstream>

class shift {
  static const int len = 26;
 public:
  shift() = delete;
  ~shift() = default;
  shift (const shift &) = delete;
  shift (shift &&) = delete;
  shift& operator=(const shift &) = delete;
  shift& operator=(shift &&) = delete;
  static void Encrypt(std::ifstream &in, std::ofstream &out, int key = -3) ;
  static void Decrypt(std::ifstream &in, std::ofstream &out, int key = -3) ;
};

#endif //ENDECRY_CIPHER_SHIFT_H_
