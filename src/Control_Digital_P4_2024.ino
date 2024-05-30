
#include <stdint.h>
#include <Arduino.h>

#define LED_GREEN 8
#define LED_YELLOW 9
#define LED_BLUE 10
#define LED_RED 11

#define SW1 2
#define SW2 3
#define SW3 4
#define SW4 5



int flag;

typedef int gpioMap_t;
const gpioMap_t secuencia[] = {LED_GREEN, LED_YELLOW, LED_BLUE, LED_RED};
const uint8_t ultimoLED = sizeof(secuencia)/sizeof(gpioMap_t);

int currSeq;

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

}


void setup() {
  
}
void loop() {
  
}