#include "main2_functions.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(ProductionCode3);

//sometimes you may want to get at local data in a module.
//for example: If you plan to pass by reference, this could be useful
//however, it should often be avoided
//extern int Counter;

TEST_SETUP(ProductionCode3)
{
  //This is run before EACH TEST
  //Counter = 0x5a5a;
}

TEST_TEAR_DOWN(ProductionCode3)
{
}


TEST(ProductionCode3, test_MultiplyTwoNumbers)
{
  //Counter = 0x1234;
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
