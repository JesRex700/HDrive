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

//  ---2 Motors, 1 Stanby/En, 2 Independent PWM Channels--
//  ---2 Motores, 1 Standby/En, 2 Canales de PWM independientes---

  drive(byte motA1, byte motA2, byte motB1, byte motB2, byte stby, byte pwmA, byte pwmB);

//  ---2 Motors, No Stanby/En, No PWM---
//  ---2 Motores, No Stanby/En, No PWM---

  drive(byte inp1, byte inp2, byte inp3, byte inp4, int idf);

//  ---2 Motors, 2 Enable/Stby, Enable pins are also for PWM---
//  ---2 Motores, 2 Enable/Stby, Los pines Enable tambien son para PWM---

  drive(byte inp1, byte inp2, byte inp3, byte inp4, byte en1, byte en2);

//  ---2 Motors, No Stby/En, No PWM/ PWM via Input---
//  ---2 Motores, No Stby/En, No PWM/ PWM via Input---

  drive(byte motA1, byte motA2, byte motB1, byte motB2);

//  ---1 Motor, PWM  via input---

  drive(byte motA1, byte motA2);

//  ---1 Motor, no PWM---

  drive(byte motA1, byte motA2, int idf);
 
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
