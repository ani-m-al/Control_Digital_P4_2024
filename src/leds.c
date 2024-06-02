#include "leds.h"

bool encenderLED(int16_t LED){
  switch (LED)
  {
  case LED_GREEN:
  case LED_YELLOW:
  case LED_RED:
  case LED_BLUE:
    digitalWrite(LED, HIGH);
  break;
  
  default:
    return false;
  }
  return true;
}

bool apagarLED(){
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, LOW);
}
