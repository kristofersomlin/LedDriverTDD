#include "unity/src/unity.h"
uint16_t virtual_bit = 0xffff;
void TURN_OFF_LED(int LedNR)
{
  if(LedNR >= 0 && LedNR < 16)
  {
    virtual_bit &= ~(1<<LedNR);
  }
}

void TURN_ON_LED(int LedNR)
{
  if(LedNR >= 0 && LedNR < 16)
  {
    virtual_bit |= (1<<LedNR);
  }
}

void CHANGE_ALL_LEDS(int on)
{
  int i=0;
  for (;i<16;i++)
  {
    if(on)
    {
      TURN_ON_LED(i);
    }
    else
    {
      TURN_OFF_LED(i);
    }
  }
}

void PRINT_LED_VALUES(uint16_t num)
{
  int bit=0;
  for(;bit<(sizeof(unsigned int) * 8); bit++)
  {
    printf("%i ", num & 0x01);
    num = num >> 1;
  }
  printf("\n");
}







void TEST_ALL_LEDS()
{
  CHANGE_ALL_LEDS(0);
  TEST_ASSERT_EQUAL(0, virtual_bit);
  CHANGE_ALL_LEDS(1);
  TEST_ASSERT_EQUAL(65535, virtual_bit);
}

void TEST_ONE_LED()
{
  CHANGE_ALL_LEDS(0);
  TURN_ON_LED(0);   // 0000 0000 0000 0001
  TEST_ASSERT_EQUAL(1, virtual_bit);
  TURN_ON_LED(2);  // 0000 0000 0000 0101 since the first bit is already set
  TEST_ASSERT_EQUAL(5, virtual_bit);
  TURN_OFF_LED(0);
  TEST_ASSERT_EQUAL(4, virtual_bit);
}

int main(void)
{
  UNITY_BEGIN();
  RUN_TEST(TEST_ALL_LEDS);
  RUN_TEST(TEST_ONE_LED);
  return UNITY_END();
}
