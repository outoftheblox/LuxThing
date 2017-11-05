#include <Arduino.h>
#include <unity.h>

#include "MAX44009.h"

#ifdef UNIT_TEST

MAX44009 sensor;

void readsProperValue() 
{
  float value = sensor.lux();
  TEST_ASSERT_FLOAT_WITHIN(100, 100, value);
}

void setup() 
{
  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  delay(2000);
  UNITY_BEGIN();
}

void loop() 
{
  uint8_t count = 100;
  while(--count)
  {
    RUN_TEST(readsProperValue);
  }
  UNITY_END();
}

#endif
