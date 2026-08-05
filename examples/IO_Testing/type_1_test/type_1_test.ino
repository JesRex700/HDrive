#include "hdrive.h"

drive drive(5, 6, 7, 8, 0);

void setup() {

  drive.init();
}

void loop() {

  drive.test();
}
