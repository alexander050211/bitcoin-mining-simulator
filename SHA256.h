// SHA256.h
#ifndef SHA256_H
#define SHA256_H

#include <string>
#include <cstdint>

class SHA256
{
public:
  // Constructor to initialize internal state
  SHA256();

  // Public methods for hashing
  void update(const uint8_t *data, size_t length); // Add data to the hash
  void update(const std::string &data);            // Add data to the hash from a string
  std::string final();                             // Get the final hash as a string
  void reset();                                    // Reset state to start hashing new data

  // Static convenience method for quick hashing
  static std::string hash(const std::string &data);

private:
  // Internal transformation method to process 512-bit chunks
  void transform();

  // Internal data members for SHA-256 state and data block
  uint8_t m_data[64];  // Current data block (64 bytes)
  uint32_t m_blocklen; // Length of current data block
  uint64_t m_bitlen;   // Total length of the message (in bits)
  uint32_t m_state[8]; // Internal state (hash values)

  // Static utility methods for bitwise operations used in SHA-256
  static uint32_t rotr(uint32_t x, uint32_t n);
  static uint32_t choose(uint32_t e, uint32_t f, uint32_t g);
  static uint32_t majority(uint32_t a, uint32_t b, uint32_t c);
  static uint32_t sig0(uint32_t x);
  static uint32_t sig1(uint32_t x);
  static uint32_t ep0(uint32_t x);
  static uint32_t ep1(uint32_t x);

  // Constants used in SHA-256
  static const uint32_t K[64];
};

#endif // SHA256_H
