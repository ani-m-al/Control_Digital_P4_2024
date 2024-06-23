#include <stdint.h>
#include <Arduino.h>
#include <hal.h>

bool encenderLED(int16_t LED);
bool apagarLED();

// Declaración de la estructura Nodo
typedef struct Nodo {
    int led;
    struct Nodo* siguiente;
    struct Nodo* anterior;
} Nodo;

Nodo* crearNodo(int led);

void insertarAlFinal(Nodo** cabeza, int led);
void inicializarLista();