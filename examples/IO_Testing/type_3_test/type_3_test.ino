#include "hdrive.h"

drive drive(6, 7, 9, 10);

void setup() {

  drive.init();
}

void loop() {

  drive.test();
}
