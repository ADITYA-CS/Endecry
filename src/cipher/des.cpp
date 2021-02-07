#include "des.h"
#include <algorithm>
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
//    std::cout << "\"" << K[round] << "\"," << std::endl;
  }
}

void DES::Encrypt(std::istream &, std::ostream &, const std::string &s, bool decip) {
  std::array<std::bitset<48>, 16> key;
  GenerateKey(key, s);
  if (decip) {
    std::reverse(key.begin(), key.end());
  }

  std::vector<uint32_t> plaintext(2), ciphertext(2);
  plaintext[0] = 19088743;
  plaintext[1] = 2309737967;
  ProcessBlock(plaintext, key, ciphertext);
  std::string h{"0123456789ABCDEF"};
  for (int i = 28; i >= 0; i-=4){
    uint8_t t = (ciphertext[0] >> i) & 0xf;
    std::cout << h[t];
  }
  for (int i = 28; i >= 0; i-=4){
    uint8_t t = (ciphertext[1] >> i) & 0xf;
    std::cout << h[t];
  }
}

void DES::ProcessBlock(const std::vector<uint32_t> & plaintext, const std::array<std::bitset<48>, 16> & key, std::vector<uint32_t> & result) {
  std::vector<uint32_t> LR(2);
  for (int i = 0; i < 32; i++) {
    uint8_t id = IP[i] - 1;
    LR[0] |= ((plaintext[id >> 5] >> (31 - (id & 0x1f))) & 1) << (31 - i);
  }
  for (int i = 0; i < 32; i++) {
    uint8_t id = IP[32 + i] - 1;
    LR[1] |= ((plaintext[id >> 5] >> (31 - (id & 0x1f))) & 1) << (31 - i);
  }
  uint32_t  tmp;
  for (uint8_t round = 0; round < 16; round++) {
    tmp = FeistelNetwork::f(LR[1], key[round]);
    tmp ^= LR[0];
    LR[0] = LR[1];
    LR[1] = tmp;
  }
  std::swap(LR[0], LR[1]);
  result[0] = result[1] = 0;
  for (uint8_t i = 0; i < 32; i++) {
    uint8_t id = PI[i] - 1;
    result[0] |= ((LR[id >> 5] >> (31 - (id & 0x1f))) & 1) << (31 - i);
  }
  for (uint8_t i = 0; i < 32; i++) {
    uint8_t id = PI[32 + i] - 1;
    result[1] |= ((LR[id >> 5] >> (31 - (id & 0x1f))) & 1) << (31 - i);
  }
}