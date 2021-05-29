#include "payment.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(Payment);

TEST_SETUP(Payment)
{
}

TEST_TEAR_DOWN(Payment)
{
}

TEST(Payment, TestPaymentLimit)
{
	TEST_ASSERT_EQUAL(0, payment(0.01,"regular"));
	TEST_ASSERT_EQUAL(0, payment(99999.00,"regular"));
	TEST_ASSERT_EQUAL(1, payment(0.009,"regular"));
	TEST_ASSERT_EQUAL(1, payment(99999.01,"regular"));
	
}

TEST(Payment, TestPaymentValue)
{
  // This test will fail
	TEST_ASSERT_EQUAL(1, payment(250000.00,"aposentado"));
	TEST_ASSERT_EQUAL(1, payment(0.009,"VIP"));
	TEST_ASSERT_EQUAL(1, payment('D',"aposentado"));
}
TEST(Payment, TestPaymentStatus)
{
  // This test will fail
	TEST_ASSERT_EQUAL(2, payment(1000.0,"professor"));
	TEST_ASSERT_EQUAL(2, payment(1000.0,"estudantee"));
	TEST_ASSERT_EQUAL(0, payment(10000.0,"estudante"));
}
