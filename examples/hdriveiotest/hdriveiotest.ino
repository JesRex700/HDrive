#include "hdrive.h"

drive avanzar(8, 6, 7, 9, 10);

void setup() {
  avanzar.init();
  avanzar.setpwm(5, 11);
}

void loop() {
  avanzar.prueba();
}