#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Identifier)
{
  RUN_TEST_CASE(Identifier, validS);
  RUN_TEST_CASE(Identifier, validF);
  //RUN_TEST_CASE(Foo, TestFoo2);
}
