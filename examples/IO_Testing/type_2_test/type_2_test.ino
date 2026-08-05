#include "hdrive.h"

drive drive(6, 7, 9, 10, 5, 11);

void setup() {

  drive.init();
}

void loop() {

  drive.test();
}
