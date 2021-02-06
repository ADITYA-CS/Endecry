#include "des.h"
#include <iostream>

void DES::GenerateKey(std::array<std::bitset<48>, 16> &K,
                      const std::string &key) {

  std::array<std::bitset<28>, 2> CD;
  CD[0].reset();
  CD[1].reset();
  for (uint8_t i = 0; i < 28; i++) {
    uint8_t id = PC1[i] - 1;
    if (key[id >> 3] & (1 << (7 - (id & 0x7))))
      CD[0].flip(27 - i);
  }
  for (uint8_t i = 28; i < 56; i++) {
    uint8_t id = PC1[i] - 1;
    if (key[id >> 3] & (1 << (7 - (id & 0x7))))
      CD[1].flip(55 - i);
  }

  for (uint8_t round = 0; round < 16; round++) {

    bool t = CD[0][27];
    CD[0] <<= 1;
    if (t)
      CD[0].flip(0);
    t = CD[1][27];
    CD[1] <<= 1;
    if (t)
      CD[1].flip(0);

    if (!(round == 0 || round == 1 || round == 8 || round == 15)) {
      t = CD[0][27];
      CD[0] <<= 1;
      if (t)
        CD[0].flip(0);
      t = CD[1][27];
      CD[1] <<= 1;
      if (t)
        CD[1].flip(0);
    }

    for (int i = 0; i < 48; i++) {
      int id = PC2[i] - 1;
      if (CD[id / 28][27 - id % 28])
        K[round][47 - i].flip();
    }
    std::cout << "\"" << K[round] << "\"," << std::endl;
  }
}

void DES::Encrypt(std::istream &, std::ostream &, const std::string &s) {
  std::array<std::bitset<48>, 16> key;
  GenerateKey(key, s);
}