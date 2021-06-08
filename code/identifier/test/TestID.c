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
  TEST_ASSERT_EQUAL(0, valid_s(' '));
  TEST_ASSERT_EQUAL(1, valid_s('z'));
  TEST_ASSERT_EQUAL(0, valid_s('z'+ 1));
  TEST_ASSERT_NOT_EQUAL(1, valid_s('!'));
  TEST_ASSERT_EQUAL(0, valid_s(32));

}

TEST(Identifier, validF)
{
  TEST_ASSERT_EQUAL(1, valid_f('A'));
  TEST_ASSERT_EQUAL(0, valid_f(' '));
  TEST_ASSERT_EQUAL(1, valid_f('z'));
  TEST_ASSERT_EQUAL(0, valid_f('0' - 1));
  TEST_ASSERT_EQUAL(0, valid_s('z'+ 1));
  TEST_ASSERT_NOT_EQUAL(1, valid_f('*'));
  TEST_ASSERT_EQUAL(0, valid_s(32));

}
TEST(Identifier, id)
{
  TEST_ASSERT_EQUAL(1, identifier("A00000\n"));
  TEST_ASSERT_EQUAL(0, identifier("A0000\n"));
  TEST_ASSERT_EQUAL(0, identifier("zzzzz\n"));
  TEST_ASSERT_EQUAL(1, identifier("A000/\n"));
  TEST_ASSERT_EQUAL(1, identifier("zzzz{\n"));
  TEST_ASSERT_EQUAL(1, identifier("2AC2\n"));
  TEST_ASSERT_EQUAL(1, identifier("1\n"));
}
