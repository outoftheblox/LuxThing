#include <Thing.h>
#include <BlinkPattern.h>
#include "MAX44009.h"
#include <Arduino.h>

using namespace g3rb3n;

#define ON 0
#define OFF 1

Thing thing;
BlinkPattern led(BUILTIN_LED);
MAX44009 sensor;

BlinkPattern::Pattern<2> panic{{1,1},25};
BlinkPattern::Pattern<2> start{{1,9},25};
BlinkPattern::Pattern<2> normal{{1,39},25};
BlinkPattern::Pattern<0> disable{{},1000};

void setup() 
{
  Serial.begin(230400);
  Serial.println();
  Serial.println("Client:" + thing.clientId());

  led.setPattern(start);
  
  thing.onStateChange([](const String& msg){
    Serial.println(msg);
  });

  thing.addSensor(String("sensor/lux/") + thing.clientId(), 1000, [](Value& value){
    digitalWrite(BUILTIN_LED, ON);
    float lux = sensor.lux();
    Serial.println(lux);
    digitalWrite(BUILTIN_LED, OFF);
    value = lux;
  });

  thing.begin();
  led.setPattern(disable);
}

void loop()
{
  thing.handle();
  led.handle();
}
