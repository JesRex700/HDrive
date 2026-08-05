#include "hdrive.h"

drive drive(8, 6, 7, 9, 10, 5, 11); //Constructor for a TB6612FNG Driver

void setup() {

  drive.init();
}

void loop() {

  drive.test();
}
