#include <hdrive.h>

drive avanzar(8, 6, 7, 10, 9);
char blue;

void setup() {
  Serial.begin(9600);
  avanzar.init();
  avanzar.setpwm(5,11);
}

void loop() {
  blue = Serial.read();
  switch (blue) {
    case 'F':
      avanzar.atras(255);
      break;
    case 'B':
      avanzar.adelante(255);
      break;
    case 'L':
      avanzar.izquierda(255);
      break;
    case 'R':
      avanzar.derecha(255);
      break;
    case 'S':
      avanzar.off();
      break;
  }
}
