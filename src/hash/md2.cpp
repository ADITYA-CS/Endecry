#include <iomanip>
#include "md2.h"

void MD2::Hash(std::ifstream &in, std::ofstream &out) {
  std::array<unsigned char, 16> input{}, checksum{};
  std::array<unsigned char, 48> md_buffer{};
  checksum.fill(0);
  md_buffer.fill(0);

  char ch;
  uint8_t len = 0;
  unsigned char L = 0;

  while (in.get(ch)) {
    input[len] = ch;
    len = (len + 1) % 16;
    if (!len) {
      Checksum(input, checksum, L);
      Update(input, md_buffer);
    }
  }

  int8_t padding_len = 16 - len;
  for (int8_t i = len; i < 16; i++) {
    input[i] = (unsigned char) padding_len;
  }
  Checksum(input, checksum, L);
  Update(input, md_buffer);
  Update(checksum, md_buffer);
  for (uint8_t i = 0; i < 16; i++) {
    out << std::hex << std::setfill('0') << std::setw(2) << (uint) md_buffer[i];
  }
}

void MD2::Checksum(std::array<unsigned char, 16> &input,
                   std::array<unsigned char, 16> &checksum, unsigned char &L) {
  for (uint8_t i = 0; i < 16; i++) {
    checksum[i] ^= S[input[i] ^ L];
    L = checksum[i];
  }
}

void MD2::Update(std::array<unsigned char, 16> &input,
                 std::array<unsigned char, 48> &md_buffer) {
  for (uint8_t i = 0; i < 16; i++) {
    md_buffer[16 + i] = input[i];
    md_buffer[32 + i] = md_buffer[16 + i] ^ md_buffer[i];
  }
  uint8_t t = 0;
  for (uint8_t round = 0; round < 18; round++) {
    for (uint8_t k = 0; k < 48; k++) {
      md_buffer[k] ^= S[t];
      t = md_buffer[k];
    }
    t = (t + round) % 256;
  }
}