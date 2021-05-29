#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Payment)
{
  RUN_TEST_CASE(Payment, TestPaymentLimit);
  RUN_TEST_CASE(Payment, TestPaymentValue);
  RUN_TEST_CASE(Payment, TestPaymentStatus);
}
