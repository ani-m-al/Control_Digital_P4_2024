#include "pulsantes.h"

// Definiciones de las variables globales
bool direccion = true; // true para adelante, false para atrás
unsigned long interval = 200;
unsigned long debounceDelay = 50;

bool leerTecla(int16_t tecla){
  bool val = !digitalRead(tecla);
  return val;
}

void buttonPressedSW1() {
  direccion = true;
}

void buttonPressedSW2() {
  direccion = false;
}

void buttonPressedSW3() {
  interval = 700;
}

void buttonPressedSW4() {
  interval = 200;
}

void inicializaMEF() {
  estadoActualSW1 = BUTTON_UP;
  estadoActualSW2 = BUTTON_UP;
  estadoActualSW3 = BUTTON_UP;
  estadoActualSW4 = BUTTON_UP;
}


void actualizaMEF(int16_t tecla, estado_t *estadoActual, unsigned long *lastDebounceTime, void (*accion)()) {
  switch(*estadoActual) {
    case BUTTON_UP:
      if (leerTecla(tecla)) {
        *estadoActual = BUTTON_FALLING;
        *lastDebounceTime = millis();
      }
      break;
    case BUTTON_FALLING:
      if ((millis() - *lastDebounceTime) >= debounceDelay) {
        if (leerTecla(tecla)) {
          *estadoActual = BUTTON_DOWN;
          accion();
        } else {
          *estadoActual = BUTTON_UP;
        }
      }
      break;
    case BUTTON_RAISING:
      if ((millis() - *lastDebounceTime) >= debounceDelay) {
        if (!leerTecla(tecla)) {
          *estadoActual = BUTTON_UP;
        } else {
          *estadoActual = BUTTON_DOWN;
        }
      }
      break;
    case BUTTON_DOWN:
      if (!leerTecla(tecla)) {
        *estadoActual = BUTTON_RAISING;
        *lastDebounceTime = millis();
      }
      break;
    default:
      inicializaMEF();
      break;
  }
}
