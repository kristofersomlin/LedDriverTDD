#include "unity/src/unity.h"
uint16_t virtual_bit = 0xffff;


void TEST_LEDS() {
  TEST_ASSERT_EQUAL(0, virtual_bit);
}

void INIT_LEDS() {
  virtual_bit = 0x0000;
}

void TURN_OFF_LED(int LedNR) {
  if(LedNR >= 0 && LedNR < 16) {
    virtual_bit &= ~(1<<LedNR);
  }
}
void TURN_ON_LED(int LedNR) {
  if(LedNR >= 0 && LedNR < 16) {
    virtual_bit |= (1<<LedNR);
  }
}

void PRINT_LED_VALUES(uint16_t num) {
  int bit=0;
   for(;bit<(sizeof(unsigned int) * 8); bit++)
   {
      printf("%i ", num & 0x01);
      num = num >> 1;
   }
   printf("\n");
}

int main(void) {

  INIT_LEDS();




  UNITY_BEGIN();
  RUN_TEST(TEST_LEDS);
  return UNITY_END();
}
