/*      ---LIBRERIA HDRIVE---
POR: Jesús Amezquita, KAME ELECTRONICS

Libreria capaz de controlar practicamente
cualquier tipo de controlador de motores 
basado en el Puente H, siendo 100%
compatible con funciones de PWM, freno
de emergerncia y giro libre de la rueda.
Limitado al control de solo dos motores
de forma directa por ahora.
            Versión 2.0.0

         ---HDRIVE LIBRARY---
BY: Jesus Amezquita, KAME ELECTRONICS

Library for controlling nearly any motor 
driver based on an H Bridge architecture,
being 100% compatible with PWM, emergency
brake and freerun.
Limited for the moment at two motor direct
control.

©Jesus Amezquita ©Kame Electronics
              Version 2.0.0
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
  byte inp1;
  byte inp2;
  byte inp3;
  byte inp4;
  byte en1;
  byte en2;
  int type;
  int idf;
public:
  drive(byte motA1, byte motA2, byte motB1, byte motB2, byte stby, byte pwmA, byte pwmB);
  drive(byte motA1, byte motA2, byte motB1, byte motB2, int idf = 0);
  drive(byte motA1, byte motA2, byte motB1, byte motB2, byte en1, byte en2);
  drive(byte motA1, byte motA2, byte motB1, byte motB2);
  drive(byte motA1, byte motA2);
  void init();
  void off();
  void forward(int pwmVa = 255, int pwmVb = 255);
  void backward(int pwmVa = 255, int pwmVb = 255);
  void left(int pwmVa = 255, int pwmVb = 255);
  void right(int pwmVa = 255, int pwmVb = 255);
  void brake(int pwmVa = 255, int pwmVb = 255);
  void sleep();
  void wakeUp();
  void test(int pwmVa = 255, int pwmVb = 255);
};

#endif
