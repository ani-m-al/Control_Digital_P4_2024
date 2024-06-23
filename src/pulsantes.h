#include <stdint.h>
#include <Arduino.h>
#include <hal.h>

//Variables para control de pulsantes
extern bool direccion;
extern unsigned long interval;
extern unsigned long debounceDelay;

typedef enum {
  BUTTON_UP, 
  BUTTON_FALLING,
  BUTTON_RAISING,
  BUTTON_DOWN,
} estado_t;

// Declaración de las variables globales
extern estado_t estadoActualSW1;
extern estado_t estadoActualSW2;
extern estado_t estadoActualSW3;
extern estado_t estadoActualSW4;

//Funciones de la MEF
void inicializaMEF();
void actualizaMEF(int16_t tecla, estado_t *estadoActual, unsigned long *lastDebounceTime, void (*accion)());

//Funciones de los botones
void buttonPressedSW1();
void buttonPressedSW2();
void buttonPressedSW3();
void buttonPressedSW4();
bool leerTecla(int16_t tecla);