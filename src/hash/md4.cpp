#include "md4.h"
#include <array>

#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (y)) | ((x) & (z)) | ((y) & (z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))
#define FF(a, b, c, d, x, s) { \
      (a) += F((b), (c), (d)) + (x); \
      (a) = ROTATE_LEFT ((a), (s)); \
    }
#define GG(a, b, c, d, x, s) { \
      (a) += G((b), (c), (d)) + (x) + (uint32_t)0x5a827999; \
      (a) = ROTATE_LEFT ((a), (s)); \
    }
#define HH(a, b, c, d, x, s) { \
      (a) += H((b), (c), (d)) + (x) + (int32_t)0x6ed9eba1; \
      (a) = ROTATE_LEFT ((a), (s)); \
    }

void MD4::ChangeEndianess(uint32_t &n) {
  uint32_t t = (n & (uint32_t) 0xFF) << (uint8_t) 24;
  t = t | (n & (uint32_t) 0xFF00) << (uint8_t) 8;
  t = t | (n & (uint32_t) 0xFF0000) >> (uint8_t) 8;
  t = t | (n & (uint32_t) 0xFF000000) >> (uint8_t) 24;
  n = t;
}

void MD4::Hash(std::istream &in, std::ostream &out) {
  std::array<uint32_t, 4> md_buffer{0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476};
  std::array<uint32_t, 16> block{0};
  std::array<uint32_t, 2> msg_len{0, 0};
  std::array<uint32_t, 4> shift{24, 16, 8, 0};
  uint32_t len = 0, tmp;
  uint64_t l = 0;
  char ch;
  while (in.get(ch)) {
    l += 8;
    tmp = (uint32_t) (uint8_t) ch;
    block[len >> (uint8_t) 5] =
        (!len || len / 8 % 4 == 0) ? tmp << shift[0] : (block[len >> (uint8_t) 5]
            | (tmp << shift[len / 8 % 4]));
    len = (len + 8) % 512;
    if (len == 0) {
      Update(block, md_buffer);
    }
  }
  if (len >= 448) {
    if (len < 480) block[15] = 0;
    block[len >> (uint8_t) 5] = (!len || len / 8 % 4 == 0) ? (uint32_t) 1 << (shift[0] + 7): (block[len >> (uint8_t) 5]
        | ((uint32_t) 1 << ((shift[len / 8 % 4]) + 7)));
    Update(block, md_buffer);
    for (int i = 0; i < 14; i++) block[i] = 0;
  } else {
    block[len >> (uint8_t) 5] = (!len || len / 8 % 4 == 0) ? (uint32_t) 1 << (shift[0] + 7): (block[len >> (uint8_t) 5]
        | ((uint32_t) 1 << ((shift[len / 8 % 4]) + 7)));
    for (int8_t i = (len >> (uint8_t) 5) + 1; i < 14; i++) {
      block[i] = 0;
    }
  }
  block[14] = (uint32_t) l;
  block[15] = l >> (uint32_t) 32;
  ChangeEndianess(block[14]);
  ChangeEndianess(block[15]);
  Update(block, md_buffer);

  std::string hex = "0123456789abcdef";
  for (int i = 0; i < 4; i++) {
    ChangeEndianess(md_buffer[i]);
    for (uint8_t j = 0, s = 24; j < 4; j++, s -= 8) {
      uint8_t t = md_buffer[i] >> s;
      out << hex[t / 16] << hex[t % 16];
    }
    md_buffer[i] = 0;
  }
}

void MD4::Update(std::array<uint32_t, 16> &X, std::array<uint32_t, 4> &md_buffer) {

  for (uint8_t i = 0; i < 16; i++) {
    ChangeEndianess(X[i]);
  }
  uint32_t A = md_buffer[0];
  uint32_t B = md_buffer[1];
  uint32_t C = md_buffer[2];
  uint32_t D = md_buffer[3];
  // round 1
  FF(A, B, C, D, X[0], 3)
  FF(D, A, B, C, X[1], 7)
  FF(C, D, A, B, X[2], 11)
  FF(B, C, D, A, X[3], 19)

  FF(A, B, C, D, X[4], 3)
  FF(D, A, B, C, X[5], 7)
  FF(C, D, A, B, X[6], 11)
  FF(B, C, D, A, X[7], 19)

  FF(A, B, C, D, X[8], 3)
  FF(D, A, B, C, X[9], 7)
  FF(C, D, A, B, X[10], 11)
  FF(B, C, D, A, X[11], 19)

  FF(A, B, C, D, X[12], 3)
  FF(D, A, B, C, X[13], 7)
  FF(C, D, A, B, X[14], 11)
  FF(B, C, D, A, X[15], 19)

  // round 2
  GG(A, B, C, D, X[0], 3)
  GG(D, A, B, C, X[4], 5)
  GG(C, D, A, B, X[8], 9)
  GG(B, C, D, A, X[12], 13)

  GG(A, B, C, D, X[1], 3)
  GG(D, A, B, C, X[5], 5)
  GG(C, D, A, B, X[9], 9)
  GG(B, C, D, A, X[13], 13)

  GG(A, B, C, D, X[2], 3)
  GG(D, A, B, C, X[6], 5)
  GG(C, D, A, B, X[10], 9)
  GG(B, C, D, A, X[14], 13)

  GG(A, B, C, D, X[3], 3)
  GG(D, A, B, C, X[7], 5)
  GG(C, D, A, B, X[11], 9)
  GG(B, C, D, A, X[15], 13)

  // round 3
  HH(A, B, C, D, X[0], 3)
  HH(D, A, B, C, X[8], 9)
  HH(C, D, A, B, X[4], 11)
  HH(B, C, D, A, X[12], 15)

  HH(A, B, C, D, X[2], 3)
  HH(D, A, B, C, X[10], 9)
  HH(C, D, A, B, X[6], 11)
  HH(B, C, D, A, X[14], 15)

  HH(A, B, C, D, X[1], 3)
  HH(D, A, B, C, X[9], 9)
  HH(C, D, A, B, X[5], 11)
  HH(B, C, D, A, X[13], 15)

  HH(A, B, C, D, X[3], 3)
  HH(D, A, B, C, X[11], 9)
  HH(C, D, A, B, X[7], 11)
  HH(B, C, D, A, X[15], 15)

  md_buffer[0] += A;
  md_buffer[1] += B;
  md_buffer[2] += C;
  md_buffer[3] += D;
}