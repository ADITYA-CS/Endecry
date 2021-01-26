#ifndef ENDECRY_SRC_HASH_MD4_H_
#define ENDECRY_SRC_HASH_MD4_H_

#include <iostream>
#include <array>

class MD4 {
  static void Update(std::array<uint32_t, 16> &, std::array<uint32_t, 4> &);
  static void ChangeEndianess(uint32_t&);
 public:
  MD4() = delete;
  ~MD4() = default;
  MD4(const MD4 &) = delete;
  MD4(MD4 &&) = delete;
  MD4 &operator=(const MD4 &) = delete;
  MD4 &operator=(MD4 &&) = delete;
  static void Hash(std::istream &in, std::ostream &out);
};

#endif //ENDECRY_SRC_HASH_MD4_H_
