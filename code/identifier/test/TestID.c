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
  TEST_ASSERT_EQUAL(0, valid_s(' '));
  TEST_ASSERT_EQUAL(0, valid_s('A'-1));
  TEST_ASSERT_EQUAL(1, valid_s('A'));
  TEST_ASSERT_EQUAL(1, valid_s('z'));
  TEST_ASSERT_EQUAL(1, valid_s('z'+1));
}

//TEST(Identifier, TestFoo2)
//{
  // This test will fail
  //TEST_ASSERT_EQUAL(2, foo(1,2));
//}
