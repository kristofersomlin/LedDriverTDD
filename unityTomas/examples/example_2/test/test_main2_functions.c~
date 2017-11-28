#include "unity.h"
#include "unity_fixture.h"

TEST(ProductionCode3, test_MultiplyTwoNumbers)
{
  TEST_ASSERT_EQUAL_FLOAT(6.0, eff_enk(2.0, 3.0));
}

TEST_GROUP_RUNNER(ProductionCode3)
{
  RUN_TEST_CASE(ProductionCode3, test_MultiplyTwoNumbers);
}

static void RunAllTests2(void)
{
  RUN_TEST_GROUP(ProductionCode3);
}


int main(int argc, const char * argv[])
{
  return UnityMain(argc, argv, RunAllTests2);
}
