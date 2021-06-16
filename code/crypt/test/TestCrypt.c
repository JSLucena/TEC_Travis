#include "crypt.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(Crypt);

TEST_SETUP(Crypt)
{
}

TEST_TEAR_DOWN(Crypt)
{
}

TEST(Crypt, XTEA128ENC)
{
  int i, type, enc_dec;
  unsigned int cipher[4];
  // Write key
  unsigned int key[8] = {
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL};
  unsigned int ref[4] = { 0x089975E9, 0x2555F334, 0xCE76E4F2, 0x4D932AB3};

  // Write type 
  // 0: XTEA, 1: AES-128, 2: AES-192, 3: AES-256
  // 4: BLOWFISH-128, 5: BLOWFISH-192, 6: BLOWFISH-256
  type = 0;
  enc_dec = 1;
  unsigned int plan[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};

  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, XTEA128DEC)
{
  int i, type, enc_dec;
  unsigned int cipher[4];
  // Write key
  unsigned int key[8] = {
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL};
  unsigned int plan[4] = { 0x089975E9, 0x2555F334, 0xCE76E4F2, 0x4D932AB3};
  unsigned int ref[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};
  // Write type
  // 0: XTEA, 1: AES-128, 2: AES-192, 3: AES-256
  // 4: BLOWFISH-128, 5: BLOWFISH-192, 6: BLOWFISH-256
  type = 0;
  enc_dec = 0;
  // All of these should pass
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}


TEST(Crypt, AES128ENC)
{
  int i, type, enc_dec;
  unsigned int cipher[4];
  // Write key
  unsigned int key[8] = {
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL};
  unsigned int ref[4] = {0x237549D4, 0xCDCEA7BE, 0x0FE7D162, 0xCC9161D3};

  // Write type 
  // 0: XTEA, 1: AES-128, 2: AES-192, 3: AES-256
  // 4: BLOWFISH-128, 5: BLOWFISH-192, 6: BLOWFISH-256
  type = 1;
  enc_dec = 1;
  unsigned int plan[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};

  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, AES128DEC)
{
  int i, type, enc_dec;
  unsigned int cipher[4];
  // Write key
  unsigned int key[8] = {
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL};
  unsigned int plan[4] = {0x237549D4, 0xCDCEA7BE, 0x0FE7D162, 0xCC9161D3};
  unsigned int ref[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};
  // Write type
  // 0: XTEA, 1: AES-128, 2: AES-192, 3: AES-256
  // 4: BLOWFISH-128, 5: BLOWFISH-192, 6: BLOWFISH-256
  type = 1;
  enc_dec = 0;
  // All of these should pass
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}



TEST(Crypt, AES192ENC)
{
  int i, type, enc_dec;
  unsigned int cipher[4];
  // Write key
  unsigned int key[8] = {
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL};
  unsigned int ref[4] = {0xEBB4CD9E, 0xDA7CBDE0, 0x9E520F4C, 0x54BE5A98};

  // Write type 
  // 0: XTEA, 1: AES-128, 2: AES-192, 3: AES-256
  // 4: BLOWFISH-128, 5: BLOWFISH-192, 6: BLOWFISH-256
  type = 2;
  enc_dec = 1;
  unsigned int plan[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};

  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, AES192DEC)
{
  int i, type, enc_dec;
  unsigned int cipher[4];
  // Write key
  unsigned int key[8] = {
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL};
  unsigned int plan[4] = {0xEBB4CD9E, 0xDA7CBDE0, 0x9E520F4C, 0x54BE5A98};
  unsigned int ref[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};
  // Write type
  // 0: XTEA, 1: AES-128, 2: AES-192, 3: AES-256
  // 4: BLOWFISH-128, 5: BLOWFISH-192, 6: BLOWFISH-256
  type = 2;
  enc_dec = 0;
  // All of these should pass
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}



TEST(Crypt, AES256ENC)
{
  int i, type, enc_dec;
  unsigned int cipher[4];
  // Write key
  unsigned int key[8] = {
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL};
  unsigned int ref[4] = {0x206BF119, 0x7A085AC8, 0xB31B2AD0, 0x4843FFC1};

  // Write type
  // 0: XTEA, 1: AES-128, 2: AES-192, 3: AES-256
  // 4: BLOWFISH-128, 5: BLOWFISH-192, 6: BLOWFISH-256
  type = 3;
  enc_dec = 1;
  unsigned int plan[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};

  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, AES256DEC)
{
  int i, type, enc_dec;
  unsigned int cipher[4];
  // Write key
  unsigned int key[8] = {
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL};
  unsigned int plan[4] = {0x206BF119, 0x7A085AC8, 0xB31B2AD0, 0x4843FFC1};
  unsigned int ref[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};
  // Write type
  // 0: XTEA, 1: AES-128, 2: AES-192, 3: AES-256
  // 4: BLOWFISH-128, 5: BLOWFISH-192, 6: BLOWFISH-256
  type = 3;
  enc_dec = 0;
  // All of these should pass
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}

TEST(Crypt, BLOWFISH128ENC)
{
  int i, type, enc_dec;
  unsigned int cipher[4];
  // Write key
  unsigned int key[8] = {
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL};
  unsigned int ref[4] = {0x24B9C5E1, 0xB06FBF71, 0x5527E5FA, 0x3502EE1A};

  // Write type
  // 0: XTEA, 1: AES-128, 2: AES-192, 3: AES-256
  // 4: BLOWFISH-128, 5: BLOWFISH-192, 6: BLOWFISH-256
  type = 4;
  enc_dec = 1;
  unsigned int plan[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};

  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, BLOWFISH128DEC)
{
  int i, type, enc_dec;
  unsigned int cipher[4];
  // Write key
  unsigned int key[8] = {
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL};
  unsigned int plan[4] = {0x24B9C5E1, 0xB06FBF71, 0x5527E5FA, 0x3502EE1A};
  unsigned int ref[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};
  // Write type
  // 0: XTEA, 1: AES-128, 2: AES-192, 3: AES-256
  // 4: BLOWFISH-128, 5: BLOWFISH-192, 6: BLOWFISH-256
  type = 4;
  enc_dec = 0;
  // All of these should pass
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}

TEST(Crypt, BLOWFISH192ENC)
{
  int i, type, enc_dec;
  unsigned int cipher[4];
  // Write key
  unsigned int key[8] = {
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL};
  unsigned int ref[4] = {0xA5E31925, 0x25FE7048, 0x4254F298, 0x4B71D955};

  // Write type
  // 0: XTEA, 1: AES-128, 2: AES-192, 3: AES-256
  // 4: BLOWFISH-128, 5: BLOWFISH-192, 6: BLOWFISH-256
  type = 5;
  enc_dec = 1;
  unsigned int plan[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};

  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, BLOWFISH192DEC)
{
  int i, type, enc_dec;
  unsigned int cipher[4];
  // Write key
  unsigned int key[8] = {
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL};
  unsigned int plan[4] = {0xA5E31925, 0x25FE7048, 0x4254F298, 0x4B71D955};
  unsigned int ref[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};
  // Write type
  // 0: XTEA, 1: AES-128, 2: AES-192, 3: AES-256
  // 4: BLOWFISH-128, 5: BLOWFISH-192, 6: BLOWFISH-256
  type = 5;
  enc_dec = 0;
  // All of these should pass
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}

TEST(Crypt, BLOWFISH256ENC)
{
  int i, type, enc_dec;
  unsigned int cipher[4];
  // Write key
  unsigned int key[8] = {
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL};
  unsigned int ref[4] = {0x24B9C5E1, 0xB06FBF71, 0x5527E5FA, 0x3502EE1A};

  // Write type
  // 0: XTEA, 1: AES-128, 2: AES-192, 3: AES-256
  // 4: BLOWFISH-128, 5: BLOWFISH-192, 6: BLOWFISH-256
  type = 6;
  enc_dec = 1;
  unsigned int plan[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};

  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, BLOWFISH256DEC)
{
  int i, type, enc_dec;
  unsigned int cipher[4];
  // Write key
  unsigned int key[8] = {
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL};
  unsigned int plan[4] = {0x24B9C5E1, 0xB06FBF71, 0x5527E5FA, 0x3502EE1A};
  unsigned int ref[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};
  // Write type
  // 0: XTEA, 1: AES-128, 2: AES-192, 3: AES-256
  // 4: BLOWFISH-128, 5: BLOWFISH-192, 6: BLOWFISH-256
  type = 6;
  enc_dec = 0;
  // All of these should pass
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}