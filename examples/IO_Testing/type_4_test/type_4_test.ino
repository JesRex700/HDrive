#include "hdrive.h"

drive drive(6, 7);

void setup() {

  drive.init();
}

void loop() {

  drive.test();
}
