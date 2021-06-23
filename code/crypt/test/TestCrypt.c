#include "crypt.h"
#include "unity.h"
#include "unity_fixture.h"

#define ENCODE 1
#define DECODE 0


int type, enc_dec= ENCODE;
unsigned int cipher[4] = {0x0L,0x0L,0x0L,0x0L};
unsigned int ref[4];
unsigned int plan[4];
unsigned int key[8] = {
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL};


TEST_GROUP(Crypt);

TEST_SETUP(Crypt)
{
  if(enc_dec == ENCODE)
  {
    plan[0] = 0xA5A5A5A5L;
    plan[1] = 0x01234567L;
    plan[2] = 0xFEDCBA98L;
    plan[3] = 0x5A5A5A5AL;

  }


}

TEST_TEAR_DOWN(Crypt)
{
  int i;
  if(enc_dec == ENCODE)
  {
    enc_dec = DECODE;     
    for (i = 0; i < 4; i++)
    {
      ref[i] = plan[i];
      
      plan[i] = cipher[i];
      
    }
    /*
    printf("%08X %08X %08X %08X (Ref)\n", ref[0], ref[1], ref[2], ref[3]);
    printf("%08X %08X %08X %08X (Plan)\n", plan[0], plan[1], plan[2], plan[3]);
    printf("%08X %08X %08X %08X (Cipher)\n", cipher[0], cipher[1], cipher[2], cipher[3]);
      */
    
  }
  else
  {
    enc_dec = ENCODE;
  }

}

TEST(Crypt, XTEA128ENC)
{
  type = 0;
  ref[0] = 0x089975E9L;
  ref[1] = 0x2555F334L;
  ref[2] = 0xCE76E4F2L;
  ref[3] = 0x4D932AB3L;
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, XTEA128DEC)
{
  type = 0;
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, AES128ENC)
{
  ref[0] = 0x237549D4;
  ref[1] = 0xCDCEA7BE;  
  ref[2] = 0x0FE7D162;
  ref[3] = 0xCC9161D3;  
  type = 1;
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, AES128DEC)
{
  type = 1;
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, AES192ENC)
{
  ref[0] = 0xEBB4CD9E;
  ref[1] = 0xDA7CBDE0;  
  ref[2] = 0x9E520F4C;
  ref[3] = 0x54BE5A98;  
  type = 2;
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, AES192DEC)
{
  type = 2;
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, AES256ENC)
{
  ref[0] = 0x206BF119;
  ref[1] = 0x7A085AC8;  
  ref[2] = 0xB31B2AD0;
  ref[3] = 0x4843FFC1; 
  type = 3;
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, AES256DEC)
{
  type = 3;
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, BLOWFISH128ENC)
{
  ref[0] = 0x24B9C5E1;
  ref[1] = 0xB06FBF71;  
  ref[2] = 0x5527E5FA;
  ref[3] = 0x3502EE1A; 
  type = 4;

  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, BLOWFISH128DEC)
{
  type = 4;
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, BLOWFISH192ENC)
{
  ref[0] = 0xA5E31925;
  ref[1] = 0x25FE7048;  
  ref[2] = 0x4254F298;
  ref[3] = 0x4B71D955; 
  type = 5;
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, BLOWFISH192DEC)
{
  type = 5;
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, BLOWFISH256ENC)
{
  ref[0] = 0x24B9C5E1;
  ref[1] = 0xB06FBF71;  
  ref[2] = 0x5527E5FA;
  ref[3] = 0x3502EE1A; 
  type = 6;
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, BLOWFISH256DEC)
{
  type = 6;
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}



TEST(Crypt, INVTYPE)
{
  ref[0] = 0x237549D4;
  ref[1] = 0xCDCEA7BE;  
  ref[2] = 0x0FE7D162;
  ref[3] = 0xCC9161D3;  


  type = 7;
  crypt(key, plan, type, enc_dec, cipher);
  TEST_ASSERT_EQUAL_UINT_ARRAY(plan, cipher, 4);
}


///////////////// Testes que nao serao executados mas fazem parte dos testes de classes de equivalencia e de limite
TEST(Crypt, SMALLKEY)
{
  unsigned int keyTest[3] = {
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL};
  type = 1;
  enc_dec = ENCODE;
  ref[0] = 0x237549D4;
  ref[1] = 0xCDCEA7BE;  
  ref[2] = 0x0FE7D162;
  ref[3] = 0xCC9161D3;  


  crypt(keyTest, plan, type, enc_dec, cipher);
   printf("%08X %08X %08X %08X (Ref)\n", ref[0], ref[1], ref[2], ref[3]);
    printf("%08X %08X %08X %08X (Plan)\n", plan[0], plan[1], plan[2], plan[3]);
    printf("%08X %08X %08X %08X (Cipher)\n", cipher[0], cipher[1], cipher[2], cipher[3]);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 4);
}
TEST(Crypt, SMALLPLAN) /// Nao sabemos porque, mas o valor do smallPlan muda depois de executar o crypt.
{
  enc_dec = ENCODE;
  type = 1;
  ref[0] = 0x237549D4;
  ref[1] = 0xCDCEA7BE; 

  unsigned int cifra[2];
  unsigned int smallPlan[2] = {0xA5A5A5A5L,0x01234567L};
  printf("%08X (Plan antes)\n", plan[0]);
  crypt(key, smallPlan, type, enc_dec, cifra);
  printf("%08X (Ref)\n", ref[0]);
  printf("%08X (Plan depois)\n", plan[0]);
  printf("%08X (Cipher)\n", cifra[0]);
  TEST_ASSERT_EQUAL(ref[0], cifra[0]);
}
TEST(Crypt, BIGPLAN)
{
  enc_dec = ENCODE;
  type = 1;

  unsigned int ref[5]; 
  unsigned int cipher[5]; 
  ref[0] = 0x237549D4;
  ref[1] = 0xCDCEA7BE;  
  ref[2] = 0x0FE7D162;
  ref[3] = 0xCC9161D3;  
  ref[4] = 0xE3140040;
  unsigned int bigPlan[5] = {0xA5A5A5A5L,0x01234567L,0xFEDCBA98L, 0x5A5A5A5AL, 0x5A5A5A5AL};

  crypt(key, bigPlan, type, enc_dec, cipher);
  printf("%08X %08X %08X %08X %08X (Plan)\n", bigPlan[0], bigPlan[1], bigPlan[2], bigPlan[3],bigPlan[4]);
  printf("%08X %08X %08X %08X %08X (Cipher)\n", cipher[0], cipher[1], cipher[2], cipher[3],cipher[4]);
  TEST_ASSERT_EQUAL_UINT_ARRAY(ref, cipher, 5);
}
