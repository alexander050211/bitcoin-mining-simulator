#ifndef SHA256_H
#define SHA256_H

#include <string>
#include <vector>
#include <cstdint>

class SHA256
{
public:
  void init();
  void update(const uint8_t *message, uint32_t length);
  void final(uint8_t *digest);

private:
  void transform(const uint8_t *message, uint32_t block_num);

  uint8_t m_data[64];  // Current data block (64 bytes)
  uint32_t m_blocklen; // Length of current data block
  uint64_t m_bitlen;   // Total length of the message (in bits)
  uint32_t m_state[8]; // Internal state (hash values)

  // Constants used in SHA-256
  static const uint32_t K[64];

  // Static utility methods for bitwise operations used in SHA-256
  static uint32_t rotr(uint32_t x, uint32_t n);
  static uint32_t choose(uint32_t e, uint32_t f, uint32_t g);
  static uint32_t majority(uint32_t a, uint32_t b, uint32_t c);
  static uint32_t sig0(uint32_t x);
  static uint32_t sig1(uint32_t x);
  static uint32_t ep0(uint32_t x);
  static uint32_t ep1(uint32_t x);
};

std::string sha256(std::string input);

#endif // SHA256_H
