#include "identifier.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(Identifier);

TEST_SETUP(Identifier)
{
}

TEST_TEAR_DOWN(Identifier)
{
}

TEST(Identifier, validS)
{
  // All of these should pass
  TEST_ASSERT_EQUAL(1, valid_s('A'));
  TEST_ASSERT_EQUAL(0, valid_s('A'- 1));
  TEST_ASSERT_EQUAL(1, valid_s('z'));
  TEST_ASSERT_EQUAL(1, valid_s('D'));
  TEST_ASSERT_EQUAL(0, valid_s('z'+ 1));
  TEST_ASSERT_EQUAL(0, valid_s(' '));

}

TEST(Identifier, validF)
{
  TEST_ASSERT_EQUAL(1, valid_f('0'));
  TEST_ASSERT_EQUAL(0, valid_f(' '));
  TEST_ASSERT_EQUAL(1, valid_f('z'));
  TEST_ASSERT_EQUAL(1, valid_f('5'));
  TEST_ASSERT_EQUAL(0, valid_f('0' - 1));
  TEST_ASSERT_EQUAL(0, valid_f('z'+ 1));

}
TEST(Identifier, equivalencia)
{
  TEST_ASSERT_EQUAL(0, identifier("T1C\n"));
  TEST_ASSERT_EQUAL(1, identifier("D!C8\n"));
  TEST_ASSERT_EQUAL(1, identifier("0AC9\n"));
 
 
}
TEST(Identifier, limiteTamanho)
{
  TEST_ASSERT_EQUAL(0, identifier("A\n"));
  TEST_ASSERT_EQUAL(0, identifier("A00000\n"));
  TEST_ASSERT_EQUAL(1, identifier("A000000\n"));
  TEST_ASSERT_EQUAL(1, identifier("\n"));
 
}
TEST(Identifier, limiteValor)
{
  TEST_ASSERT_EQUAL(1, identifier("A000/\n"));
  TEST_ASSERT_EQUAL(1, identifier("zzzz{\n"));
  TEST_ASSERT_EQUAL(1, identifier("{\n"));
  TEST_ASSERT_EQUAL(1, identifier("@\n"));
 
}
