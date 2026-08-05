// This example uses a Type 0 driver, like the TB612FNG. Also its meant to be used with an arduino nano, uno or mega; with a HC-05 or HC-06 bt modules
//Este ejemplo usa un driver Type 0, como el TB6612FNG. Tambien esta pensado para ser usado con un arduino nano, uno o mega; usando un modulo bt HC-05 o HC-06

#include <hdrive.h>

drive avanzar(6, 7, 10, 9, 8, 5, 11);
char blue;

void setup() {
  Serial.begin(9600);
  avanzar.init();
}

void loop() {
  blue = Serial.read();
  switch (blue) {
    case 'F':
      avanzar.atras();
      break;
    case 'B':
      avanzar.adelante();
      break;
    case 'L':
      avanzar.izquierda();
      break;
    case 'R':
      avanzar.derecha();
      break;
    case 'S':
      avanzar.off();
      break;
  }
}
