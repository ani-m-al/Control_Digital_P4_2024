#include "pulsantes.h"

bool leerTecla(int16_t tecla){
  bool val = !digitalRead(tecla);
  return val;
}