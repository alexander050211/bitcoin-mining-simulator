// SHA256.cpp
#include "SHA256.h"
#include <cstring>
#include <sstream>
#include <iomanip>

// Constants defined in the SHA-256 algorithm.
const uint32_t SHA256::K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

SHA256::SHA256()
{
  reset();
}

void SHA256::reset()
{
  m_blocklen = 0;
  m_bitlen = 0;
  m_state[0] = 0x6a09e667;
  m_state[1] = 0xbb67ae85;
  m_state[2] = 0x3c6ef372;
  m_state[3] = 0xa54ff53a;
  m_state[4] = 0x510e527f;
  m_state[5] = 0x9b05688c;
  m_state[6] = 0x1f83d9ab;
  m_state[7] = 0x5be0cd19;
}

void SHA256::update(const uint8_t *data, size_t length)
{
  for (size_t i = 0; i < length; ++i)
  {
    m_data[m_blocklen++] = data[i];
    if (m_blocklen == 64)
    {
      transform();
      m_bitlen += 512;
      m_blocklen = 0;
    }
  }
}

void SHA256::update(const std::string &data)
{
  update(reinterpret_cast<const uint8_t *>(data.c_str()), data.size());
}

std::string SHA256::final()
{
  uint32_t i = m_blocklen;

  // Padding
  if (m_blocklen < 56)
  {
    m_data[i++] = 0x80;
    while (i < 56)
      m_data[i++] = 0x00;
  }
  else
  {
    m_data[i++] = 0x80;
    while (i < 64)
      m_data[i++] = 0x00;
    transform();
    memset(m_data, 0, 56);
  }

  // Append length
  m_bitlen += m_blocklen * 8;
  m_data[63] = static_cast<uint8_t>(m_bitlen);
  m_data[62] = static_cast<uint8_t>(m_bitlen >> 8);
  m_data[61] = static_cast<uint8_t>(m_bitlen >> 16);
  m_data[60] = static_cast<uint8_t>(m_bitlen >> 24);
  m_data[59] = static_cast<uint8_t>(m_bitlen >> 32);
  m_data[58] = static_cast<uint8_t>(m_bitlen >> 40);
  m_data[57] = static_cast<uint8_t>(m_bitlen >> 48);
  m_data[56] = static_cast<uint8_t>(m_bitlen >> 56);
  transform();

  // Convert hash to string
  uint8_t hash[32];
  for (int i = 0; i < 4; ++i)
  {
    hash[i] = (m_state[0] >> (24 - i * 8)) & 0x000000ff;
    hash[i + 4] = (m_state[1] >> (24 - i * 8)) & 0x000000ff;
    hash[i + 8] = (m_state[2] >> (24 - i * 8)) & 0x000000ff;
    hash[i + 12] = (m_state[3] >> (24 - i * 8)) & 0x000000ff;
    hash[i + 16] = (m_state[4] >> (24 - i * 8)) & 0x000000ff;
    hash[i + 20] = (m_state[5] >> (24 - i * 8)) & 0x000000ff;
    hash[i + 24] = (m_state[6] >> (24 - i * 8)) & 0x000000ff;
    hash[i + 28] = (m_state[7] >> (24 - i * 8)) & 0x000000ff;
  }

  std::stringstream ss;
  for (int i = 0; i < 32; ++i)
    ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);

  reset(); // Ready for next usage
  return ss.str();
}

void SHA256::transform()
{
  uint32_t maj, ch, t1, t2, m[64];
  uint32_t state[8];

  // Prepare message schedule
  for (uint8_t i = 0, j = 0; i < 16; ++i, j += 4)
    m[i] = (m_data[j] << 24) | (m_data[j + 1] << 16) | (m_data[j + 2] << 8) | (m_data[j + 3]);
  for (uint8_t k = 16; k < 64; ++k)
    m[k] = sig1(m[k - 2]) + m[k - 7] + sig0(m[k - 15]) + m[k - 16];

  // Initialize working variables to current hash value
  for (uint8_t i = 0; i < 8; ++i)
    state[i] = m_state[i];

  // Compression function main loop
  for (uint8_t i = 0; i < 64; ++i)
  {
    ch = choose(state[4], state[5], state[6]);
    maj = majority(state[0], state[1], state[2]);
    t1 = state[7] + ep1(state[4]) + ch + K[i] + m[i];
    t2 = ep0(state[0]) + maj;

    state[7] = state[6];
    state[6] = state[5];
    state[5] = state[4];
    state[4] = state[3] + t1;
    state[3] = state[2];
    state[2] = state[1];
    state[1] = state[0];
    state[0] = t1 + t2;
  }

  // Update hash value
  for (uint8_t i = 0; i < 8; ++i)
    m_state[i] += state[i];
}

// Utility functions
uint32_t SHA256::rotr(uint32_t x, uint32_t n)
{
  return (x >> n) | (x << (32 - n));
}

uint32_t SHA256::choose(uint32_t e, uint32_t f, uint32_t g)
{
  return (e & f) ^ (~e & g);
}

uint32_t SHA256::majority(uint32_t a, uint32_t b, uint32_t c)
{
  return (a & b) ^ (a & c) ^ (b & c);
}

uint32_t SHA256::sig0(uint32_t x)
{
  return rotr(x, 7) ^ rotr(x, 18) ^ (x >> 3);
}

uint32_t SHA256::sig1(uint32_t x)
{
  return rotr(x, 17) ^ rotr(x, 19) ^ (x >> 10);
}

uint32_t SHA256::ep0(uint32_t x)
{
  return rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22);
}

uint32_t SHA256::ep1(uint32_t x)
{
  return rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25);
}

// Static convenience method
std::string SHA256::hash(const std::string &data)
{
  SHA256 sha256;
  sha256.update(data);
  return sha256.final();
}
