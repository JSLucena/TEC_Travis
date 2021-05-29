#include "sort.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(Sort);

TEST_SETUP(Sort)
{
}

TEST_TEAR_DOWN(Sort)
{
}

TEST(Sort, TestSortA)
{
  int ref[] = {1,2,3,4,5};

  int sample[] = {2,1,5,3,4};
 
  cj_sort(sample, 5);

  // All of these should pass
  //TEST_ASSERT_EQUAL(-2, foo(1,2));
  //TEST_ASSERT_EQUAL(-1, foo(2,2));

  TEST_ASSERT_EQUAL(ref[0],sample[0]);
  TEST_ASSERT_EQUAL(ref[1],sample[1]);
  TEST_ASSERT_EQUAL(ref[2],sample[2]);
  TEST_ASSERT_EQUAL(ref[3],sample[3]);
  TEST_ASSERT_EQUAL(ref[4],sample[4]);
}

TEST(Sort, TestSortB)
{
  // This test will fail
  //TEST_ASSERT_EQUAL(2, foo(1,2));
}
