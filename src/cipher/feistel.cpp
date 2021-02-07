#include <iostream>
#include "feistel.h"

uint32_t FeistelNetwork::f(const uint32_t &R, const std::bitset<48> &key) {
  uint32_t higher_bits = 0;
  uint16_t lower_bits = 0;
  for (uint8_t i = 0; i < 32; i++) {
    higher_bits |= (((R >> (31 - E[i])) & 1) ^ key[47 - i]) << (31 - i);
  }
  for (uint8_t i = 0; i < 16; i++) {
    lower_bits |= (((R >> (31 - E[32 + i])) & 1) ^ key[47 - (32 + i)]) << (15 - i);
  }

  uint32_t pre_permutation = 0, result = 0;
  uint8_t r, c, t;

  for (uint8_t i = 31; i > 1; i -= 6) {
    r = ((higher_bits >> i) & (uint8_t) 1) << (uint8_t) 1;
    r |= (higher_bits >> (uint8_t) (i - 5)) & (uint8_t) 1;
    c = (higher_bits >> (uint8_t) (i - 4)) & 0xF;
    pre_permutation |= S[5 - i / 6][r][c] << (28 - 4 * (5 - i / 6));
  }

  r = higher_bits & 2;
  r |= lower_bits >> 12 & 1;
  c = (higher_bits & 1) << 3;
  c |= (lower_bits >> 13) & 7;
  pre_permutation |= S[5][r][c] << 8;

  for (int i = 11; i >= 0; i -= 6) {
    r = ((lower_bits >> i) & (uint8_t) 1) << (uint8_t) 1;
    r |= ((lower_bits >> (uint8_t) (i - 5)) & (uint8_t) 1);
    c = (lower_bits >> (uint8_t) (i - 4)) & (uint8_t) 0xF;
    pre_permutation |= S[7 - i / 6][r][c] << (uint8_t) 4 * (i / 11);
  }

  for (int i = 0; i < 32; i++) {
    result |= ((pre_permutation >> (31 - P[i])) & 1) << (31 - i);
  }
  return result;
}