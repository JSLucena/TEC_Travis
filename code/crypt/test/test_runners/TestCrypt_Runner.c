#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Crypt)
{ //Teste tipo 0
  RUN_TEST_CASE(Crypt, XTEA128ENC);
  RUN_TEST_CASE(Crypt, XTEA128DEC);
  //Teste tipo 1
  RUN_TEST_CASE(Crypt, AES128ENC);
  RUN_TEST_CASE(Crypt, AES128DEC);
  //Teste tipo 2
  RUN_TEST_CASE(Crypt, AES192ENC);
  RUN_TEST_CASE(Crypt, AES192DEC);
  // Teste tipo 3
  RUN_TEST_CASE(Crypt, AES256ENC);
  RUN_TEST_CASE(Crypt, AES256DEC);
   // Teste tipo 4
  RUN_TEST_CASE(Crypt, BLOWFISH128ENC);
  RUN_TEST_CASE(Crypt, BLOWFISH128DEC);
   // Teste tipo 5
  RUN_TEST_CASE(Crypt, BLOWFISH192ENC);
  RUN_TEST_CASE(Crypt, BLOWFISH192DEC);
   // Teste tipo 6
  RUN_TEST_CASE(Crypt, BLOWFISH256ENC);
  RUN_TEST_CASE(Crypt, BLOWFISH256DEC);


  //Teste Limite Tipo
  RUN_TEST_CASE(Crypt, INVTYPE);

  

}
