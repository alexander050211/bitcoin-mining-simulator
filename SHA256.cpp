#include "SHA256.h"
#include <cstring>
#include <sstream>
#include <iomanip>

const uint32_t SHA256::K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

void SHA256::init()
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

void SHA256::transform(const uint8_t *message, uint32_t block_num)
{
  uint32_t w[64];
  uint32_t a, b, c, d, e, f, g, h;
  uint32_t t1, t2;
  const uint8_t *sub_block;

  sub_block = message + (block_num << 6);

  // Initialize message schedule
  for (int i = 0; i < 16; i++)
  {
    w[i] = (sub_block[i * 4] << 24) | (sub_block[i * 4 + 1] << 16) |
           (sub_block[i * 4 + 2] << 8) | (sub_block[i * 4 + 3]);
  }

  for (int i = 16; i < 64; i++)
  {
    w[i] = sig1(w[i - 2]) + w[i - 7] + sig0(w[i - 15]) + w[i - 16];
  }

  // Initialize working variables
  a = m_state[0];
  b = m_state[1];
  c = m_state[2];
  d = m_state[3];
  e = m_state[4];
  f = m_state[5];
  g = m_state[6];
  h = m_state[7];

  // Main loop
  for (int i = 0; i < 64; i++)
  {
    t1 = h + ep1(e) + choose(e, f, g) + K[i] + w[i];
    t2 = ep0(a) + majority(a, b, c);
    h = g;
    g = f;
    f = e;
    e = d + t1;
    d = c;
    c = b;
    b = a;
    a = t1 + t2;
  }

  // Update state
  m_state[0] += a;
  m_state[1] += b;
  m_state[2] += c;
  m_state[3] += d;
  m_state[4] += e;
  m_state[5] += f;
  m_state[6] += g;
  m_state[7] += h;
}

void SHA256::update(const uint8_t *message, uint32_t length)
{
  uint32_t have = m_blocklen;
  uint32_t need = 64 - have;

  // Update bitlen
  m_bitlen += length * 8;

  // Handle any remaining bytes from last update
  if (m_blocklen > 0 && length >= need)
  {
    memcpy(&m_data[m_blocklen], message, need);
    transform(m_data, 0);
    message += need;
    length -= need;
    m_blocklen = 0;
  }

  // Handle complete blocks
  while (length >= 64)
  {
    transform(message, 0);
    message += 64;
    length -= 64;
  }

  // Handle remaining bytes
  if (length > 0)
  {
    memcpy(&m_data[m_blocklen], message, length);
    m_blocklen += length;
  }
}

void SHA256::final(uint8_t *digest)
{
  uint32_t i = m_blocklen;

  // Pad whatever data is left in the buffer
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
    transform(m_data, 0);
    memset(m_data, 0, 56);
  }

  // Append total bit length
  m_data[63] = m_bitlen & 0xff;
  m_data[62] = (m_bitlen >> 8) & 0xff;
  m_data[61] = (m_bitlen >> 16) & 0xff;
  m_data[60] = (m_bitlen >> 24) & 0xff;
  m_data[59] = (m_bitlen >> 32) & 0xff;
  m_data[58] = (m_bitlen >> 40) & 0xff;
  m_data[57] = (m_bitlen >> 48) & 0xff;
  m_data[56] = (m_bitlen >> 56) & 0xff;

  transform(m_data, 0);

  // Since this implementation uses little endian byte ordering and SHA uses big endian,
  // reverse all the bytes when copying the final state to the output hash.
  for (i = 0; i < 4; i++)
  {
    digest[i] = (m_state[0] >> (24 - i * 8)) & 0x000000ff;
    digest[i + 4] = (m_state[1] >> (24 - i * 8)) & 0x000000ff;
    digest[i + 8] = (m_state[2] >> (24 - i * 8)) & 0x000000ff;
    digest[i + 12] = (m_state[3] >> (24 - i * 8)) & 0x000000ff;
    digest[i + 16] = (m_state[4] >> (24 - i * 8)) & 0x000000ff;
    digest[i + 20] = (m_state[5] >> (24 - i * 8)) & 0x000000ff;
    digest[i + 24] = (m_state[6] >> (24 - i * 8)) & 0x000000ff;
    digest[i + 28] = (m_state[7] >> (24 - i * 8)) & 0x000000ff;
  }
}

std::string sha256(std::string input)
{
  SHA256 sha;
  uint8_t digest[32];
  std::string hash;

  sha.init();
  sha.update((const uint8_t *)input.c_str(), input.length());
  sha.final(digest);

  std::stringstream ss;
  for (int i = 0; i < 32; i++)
  {
    ss << std::hex << std::setw(2) << std::setfill('0') << (int)digest[i];
  }
  return ss.str();
}