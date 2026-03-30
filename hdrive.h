/*      ---LIBRERIA HDRIVE---
POR: D.CHUY, KAME ELECTRONICS

Libreria capaz de controlar practicamente
cualquier tipo de controlador de motores 
basado en el Puente H, siendo 100%
compatible con funciones de PWM, freno
de emergerncia y giro libre de la rueda.
Limitado al control de solo dos motores
de forma directa por ahora.

         ---HDRIVE LIBRARY---
BY: D.CHUY, KAME ELECTRONICS

Library for controlling nearly any motor 
driver based on an H Bridge architecture,
being 100% compatible with PWM, emergency
brake and freerun.
Limited for the moment at two motor direct
control.

©D. Chuy ©Kame Electronics*/
#ifndef _HDRIVE_H
#define _HDRIVE_H

#include <Arduino.h>

class drive {
private:
  byte mot1a;
  byte mot2a;
  byte mot1b;
  byte mot2b;
  byte pwma; 
  byte pwmb;
  byte stby;
public:
  drive(byte stby, byte mot1a, byte mot2a, byte mot1b, byte mot2b); 
  void init();
  void off();
  void setpwm(byte pwma, byte pwmb);
  void forward(int pwmv);
  void backward(int pwmv);
  void left(int pwmv);
  void right(int pwmv);
  void embrake(int pwmv); 
void freerun();
void enbrun();
  void prueba(int pwmv);
};

#endif