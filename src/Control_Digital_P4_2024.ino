#include <stdint.h>
#include <stdlib.h>
#include <Arduino.h>

extern "C" {
  #include <leds.h>
  #include <pulsantes.h>
}

Nodo* cabeza = NULL;
Nodo* actual = NULL;
bool direccion = true; // true para adelante, false para atrás
unsigned long prevMillis = 0;
unsigned long interval = 200;

// Variables para el anti-rebote del pulsante
unsigned long debounceDelay = 50;

bool lastButtonStateSW1 = true;
bool buttonStateSW1 = true;
unsigned long lastDebounceTimeSW1 = 0;
bool lastButtonStateSW2 = true;
bool buttonStateSW2 = true;
unsigned long lastDebounceTimeSW2 = 0;
bool lastButtonStateSW3 = true;
bool buttonStateSW3 = true;
unsigned long lastDebounceTimeSW3 = 0;
bool lastButtonStateSW4 = true;
bool buttonStateSW4 = true;
unsigned long lastDebounceTimeSW4 = 0;

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
    unsigned long currentMillis = millis();
    // Leer el estado de SW1 usando leerTecla (opcional, para pruebas)
    bool sw1State = leerTecla(SW1);
    bool sw2State = leerTecla(SW2);
    bool sw3State = leerTecla(SW3);
    bool sw4State = leerTecla(SW4);
    //Serial.println(sw1State);

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

    // Anti-rebote del pulsante SW1
    if (sw1State != lastButtonStateSW1) {
        lastDebounceTimeSW1 = millis();
    }

    if ((millis() - lastDebounceTimeSW1) > debounceDelay) {
        if (sw1State != buttonStateSW1) {
            buttonStateSW1 = sw1State;
            if (buttonStateSW1 == LOW) {
                direccion = true; // Cambia la dirección
            }
        }
    }
    lastButtonStateSW1 = sw1State;

    if (sw2State != lastButtonStateSW2) {
        lastDebounceTimeSW2 = millis();
    }

    if ((millis() - lastDebounceTimeSW2) > debounceDelay) {
        if (sw2State != buttonStateSW2) {
            buttonStateSW2 = sw2State;
            if (buttonStateSW2 == LOW) {
                direccion = false; // Cambia la dirección
            }
        }
    }
    lastButtonStateSW2 = sw2State;

    if (sw3State != lastButtonStateSW3) {
        lastDebounceTimeSW3 = millis();
    }

    if ((millis() - lastDebounceTimeSW3) > debounceDelay) {
        if (sw3State != buttonStateSW3) {
            buttonStateSW3 = sw3State;
            if (buttonStateSW3 == LOW) {
                interval = 200; // Cambia el tiempo
            }
        }
    }
    lastButtonStateSW3 = sw3State;

    if (sw4State != lastButtonStateSW4) {
        lastDebounceTimeSW4 = millis();
    }

    if ((millis() - lastDebounceTimeSW4) > debounceDelay) {
        if (sw4State != buttonStateSW4) {
            buttonStateSW4 = sw1State;
            if (buttonStateSW4 == LOW) {
                interval = 750; // Cambia el tiempo
            }
        }
    }
    lastButtonStateSW4 = sw4State;
    
}