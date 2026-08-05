#include "hdrive.h"

drive drive(5, 6, 7, 8, 0); //The zero on the end is an idetifier, it means that you are not using PWM on the inputs (You can use any number).
                            //If removed, it will send PWM signals to the inputs and change to a type 3 driver.
void setup() {

  drive.init();
}

void loop() {

  drive.test();
}
