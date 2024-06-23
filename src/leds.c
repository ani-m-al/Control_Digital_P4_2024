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
  return true;
}

Nodo* crearNodo(int led) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->led = led;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->anterior = NULL;
    return nuevoNodo;
}

void insertarAlFinal(Nodo** cabeza, int led) {
    Nodo* nuevoNodo = crearNodo(led);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        return;
    }
    Nodo* ultimo = *cabeza;
    while (ultimo->siguiente != NULL) {
        ultimo = ultimo->siguiente;
    }
    ultimo->siguiente = nuevoNodo;
    nuevoNodo->anterior = ultimo;
}
