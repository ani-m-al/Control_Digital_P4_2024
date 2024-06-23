#include <stdint.h>
#include <stdlib.h>
#include <Arduino.h>

extern "C" {
  #include <leds.h>
  #include <pulsantes.h>
}

Nodo* cabeza = NULL;
Nodo* actual = NULL;
unsigned long prevMillis = 0;

estado_t estadoActualSW1, estadoActualSW2, estadoActualSW3, estadoActualSW4;
unsigned long lastDebounceTimeSW1 = 0;
unsigned long lastDebounceTimeSW2 = 0;
unsigned long lastDebounceTimeSW3 = 0;
unsigned long lastDebounceTimeSW4 = 0;

void inicializarLista() {
  insertarAlFinal(&cabeza, LED_GREEN);
  insertarAlFinal(&cabeza, LED_YELLOW);
  insertarAlFinal(&cabeza, LED_RED);
  insertarAlFinal(&cabeza, LED_BLUE);
  actual = cabeza;
}

void setup() {
    Serial.begin(115200);

    insertarAlFinal(&cabeza, LED_GREEN);
    insertarAlFinal(&cabeza, LED_YELLOW);
    insertarAlFinal(&cabeza, LED_RED);
    insertarAlFinal(&cabeza, LED_BLUE);
    actual = cabeza;
    prevMillis = millis();
}

void loop() {
  actualizaMEF(SW1, &estadoActualSW1, &lastDebounceTimeSW1, buttonPressedSW1);
  actualizaMEF(SW2, &estadoActualSW2, &lastDebounceTimeSW2, buttonPressedSW2);
  actualizaMEF(SW3, &estadoActualSW3, &lastDebounceTimeSW3, buttonPressedSW3);
  actualizaMEF(SW4, &estadoActualSW4, &lastDebounceTimeSW4, buttonPressedSW4);

  unsigned long currentMillis = millis();
  if ((currentMillis - prevMillis) >= interval) {
    apagarLED();
    if (direccion) {
      if (actual->siguiente != NULL) {
        actual = actual->siguiente;
      } else {
        actual = cabeza;
      }
    } else {
      if (actual->anterior != NULL) {
        actual = actual->anterior;
      } else {
        while (actual->siguiente != NULL) {
          actual = actual->siguiente;
        }
      }
    }
    encenderLED(actual->led);
    prevMillis = currentMillis;
  }
}