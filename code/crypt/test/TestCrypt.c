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

TEST(Crypt, test)
{
  int i, type, enc_dec;
  unsigned int cipher[4];
  // Write key
  unsigned int key[8] = {
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
    0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL
  };

  // Write type
  // 0: XTEA, 1: AES-128, 2: AES-192, 3: AES-256
  // 4: BLOWFISH-128, 5: BLOWFISH-192, 6: BLOWFISH-256
  type = 3;

  //---------------------------------------------------------------------------
  // Write plantext
  unsigned int plan[4] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL};
  // Write enc_dec
  enc_dec = 1;
  // All of these should pass
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL(0x206BF119, cipher[0]);

}

