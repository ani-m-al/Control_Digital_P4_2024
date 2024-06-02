#include <stdint.h>
#include <Arduino.h>

extern "C" {
  #include <leds.h>
  #include <pulsantes.h>
}

int interval = 500;
unsigned long prevTime;
bool flag = false;
int currSeq = 0;

//bool_t flagsControl[] = {FALSE, FALSE, FALSE, FALSE, FALSE};
typedef int gpioMap_t;
const gpioMap_t secuencia[] = {LED_GREEN, LED_YELLOW, LED_RED, LED_BLUE};
const uint8_t ultimoLed = sizeof(secuencia) / sizeof(secuencia[0]);

typedef struct {
  gpioMap_t * ptrLed;
  const gpioMap_t * ptrPrimerLed;
  const uint8_t * ptrUltimoLed;
} controlSecuencia_t;

void activarSecuencia(int16_t *psecuencia){
/* psecuencia apunta a una secuencia de leds o arreglo */
}

void setup() {
    Serial.begin(115200);

    pinMode(SW1, INPUT_PULLUP);
    pinMode(SW2, INPUT_PULLUP);
    pinMode(SW3, INPUT_PULLUP);
    pinMode(SW4, INPUT_PULLUP);

    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);

    prevTime = millis();
}

void loop() {
    unsigned long currTime = millis();

    if ((currTime - prevTime) >= interval) {
        // if (flag) {
        //     encenderLED(secuencia[currSeq]);
        //     currSeq++;
        //     if (currSeq >= ultimoLed) {
        //         currSeq = 0;
        //     }

        // }
        
        ///////Cambio de recorrido//////

        if (flag) {
            encenderLED(secuencia[currSeq]);
            currSeq--;
            if (currSeq < 0) {
                currSeq = ultimoLed - 1;
            }
        }

        ///////////////////////////////
        
         else {
            apagarLED();
        }
        flag = !flag;
        prevTime = currTime;
    }

    bool swval = leerTecla(SW1);
    Serial.println(swval);
}
