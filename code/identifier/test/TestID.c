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
//  TEST_ASSERT_EQUAL(0, identifier(' '));
  TEST_ASSERT_EQUAL(1, valid_s('A'));
  TEST_ASSERT_EQUAL(0, valid_s(' '));
  TEST_ASSERT_EQUAL(1, valid_s('Z'));
  TEST_ASSERT_NOT_EQUAL(1, valid_s('!'));
 // TEST_ASSERT_EQUAL(1, identifier('z'));
 // TEST_ASSERT_EQUAL(1, identifier('z'+1));
 // TEST_ASSERT_EQUAL(2, identifier('z'+1));
}

TEST(Identifier, validF)
{
  TEST_ASSERT_EQUAL(1, valid_f('A'));
  TEST_ASSERT_EQUAL(0, valid_f(' '));
  TEST_ASSERT_EQUAL(1, valid_f('Z'));
  TEST_ASSERT_EQUAL(1, valid_f('1'));
  TEST_ASSERT_NOT_EQUAL(1, valid_f('*'));

//  TEST_ASSERT_EQUAL(1,identifier());
}
