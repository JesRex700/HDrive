/*      ---LIBRERIA HDRIVE---
POR: Jesús Amezquita, KAME ELECTRONICS

Libreria capaz de controlar practicamente
cualquier tipo de controlador de motores 
basado en el Puente H, siendo 100%
compatible con funciones de PWM, freno
de emergerncia y giro libre de la rueda.
Limitado al control de solo dos motores
de forma directa por ahora.

         ---HDRIVE LIBRARY---
BY: Jesus Amezquita, KAME ELECTRONICS

Library for controlling nearly any motor 
driver based on an H Bridge architecture,
being 100% compatible with PWM, emergency
brake and freerun.
Limited for the moment at two motor direct
control.

©Jesus Amezquita ©Kame Electronics
v.1.1.0
*/
#ifndef _HDRIVE_H
#define _HDRIVE_H

#include <Arduino.h>

class drive {
private:
  byte motA1;
  byte motA2;
  byte motB1;
  byte motB2;
  byte pwmA;
  byte pwmB;
  byte stby;
public:
  drive(byte stby, byte motA1, byte motA2, byte motB1, byte motB2);
  void init();
  void off();
  void setpwm(byte pwmA , byte pwmB);
  void forward(int pwmVa = 255, int pwmVb = 255);
  void backward(int pwmVa = 255, int pwmVb = 255);
  void left(int pwmVa = 255, int pwmVb = 255);
  void right(int pwmVa = 255, int pwmVb = 255);
  void embrake(int pwmVa = 255, int pwmVb = 255);
  void freerun();
  void enbrun();
  void prueba(int pwmVa = 255, int pwmVb = 255);
};

#endif
