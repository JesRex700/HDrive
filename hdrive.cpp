#include "hdrive.h"

//  ---2 Motors, 1 Stanby/En, 2 Independent PWM Channels--
//  ---2 Motores, 1 Standby/En, 2 Canales de PWM independientes---
//  ---For: TB6612FNG or similars---
//  ---Para: TB6612FNG o similares---

drive::drive(byte stby, byte motA1, byte motA2, byte motB1, byte motB2, byte pwmA, byte pwmB) {
  this->motA1 = motA1;  //Motor A, Input 1
  this->motB1 = motB1;  //Motor B, Input 1
  this->motB2 = motB2;  //Motor B, Input 2 //Motor Izquierdo / Left Motor
  this->stby = stby;    //Stanby
  this->pwmB = pwmB;    //Pin PWM Motor B
  this->pwmA = pwmA;    //Pin PWM Motor A
  this->type = 0;
}

//  ---2 Motors, 1 Stanby/En, No PWM---
//  ---2 Motores, 1 Stanby/En, No PWM---
//  ---For: L293D(MC enabled) or similars---
//  ---Para: L293D(Activado mediante MC) o similares---

drive::drive(byte motA1, byte motA2, byte motB1, byte motB2, int idf) {
  this->motA1 = motA1;  //Motor A, Input 1
  this->motA2 = motA2;  //Motor A, Input 2 //Motor Derecho / Right Motor
  this->motB1 = motB1;  //Motor B, Input 1
  this->motB2 = motB2;  //Motor B, Input 2 //Motor Izquierdo / Left Motor
  this->idf = 0;    //Place holder
  this->type = 1;
}

//  ---2 Motors, 2 Enable/Stby, Enable pins are also for PWM---
//  ---2 Motores, 2 Enable/Stby, Los pines Enable tambien son para PWM---
//  ---For: L298N or similars---
//  ---Para: L298N o similares---

drive::drive(byte inp1, byte inp2, byte inp3, byte inp4, byte en1, byte en2) {
  this->inp1 = motA1;  //Input 1
  this->inp2 = motA2;  //Input 2 //Motor Derecho / Right Motor
  this->inp3 = motB1;  //Input 3
  this->inp4 = motB2;  //Input 4 //Motor Izquierdo / Left Motor
  this->en1 = en1;     //Enable 1
  this->en2 = en2;     //Enable 2
  this->type = 2;
}

//  ---2 Motors, No Stby/En, No PWM/ PWM via Input
//  ---2 Motores, No Stby/En, No PWM/ PWM via Input
//  ---For: DRV88XX or similars---
//  ---Para: DRV88XX o similares---

drive::drive(byte motA1, byte motA2, byte motB1, byte motB2) {
  this->motA1 = motA1;  //Motor A, Input 1
  this->motA2 = motA2;  //Motor A, Input 2 //Motor Derecho / Right Motor
  this->motB1 = motB1;  //Motor B, Input 1
  this->motB2 = motB2;  //Motor B, Input 2 //Motor Izquierdo / Left Motor
  this->type = 3;
}

drive::drive(byte motA1, byte motA2) {
  this->motA1 = motA1;  //Motor Input 1
  this->motA2 = motA2;  //Motor Input 2
  this->type = 4;
}

void drive::init() {       //Inicia todos los pines del microcontrolador asociados al controlador, estos estan pensados para arduino, otros microcontroladores tal vez requieran configuracion adicional
  pinMode(motA1, OUTPUT);  //Initialize all the microcontrolles driver ralated pins, this are designed for arduino, other microcontrollers might need extra configuration
  pinMode(motA2, OUTPUT);
  pinMode(motB1, OUTPUT);
  pinMode(motB2, OUTPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(stby, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  digitalWrite(stby, HIGH);
  digitalWrite(en1, HIGH);
  digitalWrite(en2, HIGH);
  off();
}

void drive::off() {          //Apaga los motores
  digitalWrite(motA1, LOW);  //Turns off the motors
  digitalWrite(motA2, LOW);
  digitalWrite(motB1, LOW);
  digitalWrite(motB2, LOW);
}

void drive::forward(int pwmVa, int pwmVb) {  //Drive Forward / Avanzar hacia adelante
  switch (type) {

      //2 Motors, PWM via dedicated channel

    case 0:
      analogWrite(pwmA, pwmVa);
      digitalWrite(motA1, HIGH);
      digitalWrite(motA2, LOW);
      analogWrite(pwmB, pwmVb);
      digitalWrite(motB1, HIGH);
      digitalWrite(motB2, LOW);
      break;

      //2 Motors, no PWM

    case 1:
      digitalWrite(motA1, HIGH);
      digitalWrite(motA2, LOW);
      digitalWrite(motB1, HIGH);
      digitalWrite(motB2, LOW);
      break;

      //2 Motors, PWM via enable

    case 2:
      analogWrite(en1, pwmVa);
      digitalWrite(motA1, HIGH);
      digitalWrite(motA2, LOW);
      analogWrite(en2, pwmVb);
      digitalWrite(motB1, HIGH);
      digitalWrite(motB2, LOW);
      break;

      //2 Motors, No PWM/ PWM via input

    case 3:
      analogWrite(motA1, pwmVa);
      digitalWrite(motA2, LOW);
      analogWrite(motB1, pwmVb);
      digitalWrite(motB2, LOW);
      break;

      //1 Motor

    case 4:
      analogWrite(motA1, pwmVa);
      digitalWrite(motA2, LOW);
      break;
  }
}

void drive::backward(int pwmVa, int pwmVb) {  //Drive Backwards / Avanzar hacia atras
  switch (type) {

      //2 Motors, PWM via dedicated channel

    case 0:
      analogWrite(pwmA, pwmVa);
      digitalWrite(motA1, LOW);
      digitalWrite(motA2, HIGH);
      analogWrite(pwmB, pwmVb);
      digitalWrite(motB1, LOW);
      digitalWrite(motB2, HIGH);
      break;

      //2 Motors, No PWM

    case 1:
      digitalWrite(motA1, LOW);
      digitalWrite(motA2, HIGH);
      digitalWrite(motB1, LOW);
      digitalWrite(motB2, HIGH);
      break;

      //2 Motors, PWM via enable

    case 2:
      analogWrite(en1, pwmVa);
      digitalWrite(motA1, LOW);
      digitalWrite(motA2, HIGH);
      analogWrite(en2, pwmVb);
      digitalWrite(motB1, LOW);
      digitalWrite(motB2, HIGH);
      break;

      //2 Motors, No PWM/ PWM via input

    case 3:
      analogWrite(motA1, LOW);
      digitalWrite(motA2, pwmVa);
      analogWrite(motB1, LOW);
      digitalWrite(motB2, pwmVb);
      break;

      //1 Motor

    case 4:
      analogWrite(motA1, LOW);
      digitalWrite(motA2, pwmVa);
      break;
  }
}

void drive::left(int pwmVa, int pwmVb) {  //Drive Leftward / Avanzar a la izquierda
  switch (type) {

      //2 Motors, PWM via dedicated channel

    case 0:
      analogWrite(pwmA, pwmVa);
      digitalWrite(motA1, HIGH);
      digitalWrite(motA2, LOW);
      analogWrite(pwmB, pwmVb);
      digitalWrite(motB1, LOW);
      digitalWrite(motB2, HIGH);
      break;

      //2 Motors, No PWM

    case 1:
      digitalWrite(motA1, HIGH);
      digitalWrite(motA2, LOW);
      digitalWrite(motB1, LOW);
      digitalWrite(motB2, HIGH);
      break;

      //2 Motors, PWM via enable

    case 2:
      analogWrite(en1, pwmVa);
      digitalWrite(motA1, HIGH);
      digitalWrite(motA2, LOW);
      analogWrite(en2, pwmVb);
      digitalWrite(motB1, LOW);
      digitalWrite(motB2, HIGH);
      break;

      //2 Motors, No PWM/ PWM via input

    case 3:
      analogWrite(motA1, pwmVa);
      digitalWrite(motA2, LOW);
      analogWrite(motB1, LOW);
      digitalWrite(motB2, pwmVb);
      break;

      //1 Motor

    case 4:
      analogWrite(motA1, pwmVa);
      digitalWrite(motA2, LOW);
      break;
  }
}
void drive::right(int pwmVa, int pwmVb) {  //Drive Rightward / Avanzar a la Derecha
  switch (type) {

      //2 Motors, PWM via dedicated channel

    case 0:
      analogWrite(pwmA, pwmVa);
      digitalWrite(motA1, LOW);
      digitalWrite(motA2, HIGH);
      analogWrite(pwmB, pwmVb);
      digitalWrite(motB1, HIGH);
      digitalWrite(motB2, LOW);
      break;

      //2 Motors, No PWM

    case 1:
      digitalWrite(motA1, LOW);
      digitalWrite(motA2, HIGH);
      digitalWrite(motB1, HIGH);
      digitalWrite(motB2, LOW);
      break;

      //2 Motors, PWM via enable

    case 2:
      analogWrite(en1, pwmVa);
      digitalWrite(motA1, LOW);
      digitalWrite(motA2, HIGH);
      analogWrite(en2, pwmVb);
      digitalWrite(motB1, HIGH);
      digitalWrite(motB2, LOW);
      break;

      //2 Motors, No PWM/ PWM via input

    case 3:
      analogWrite(motA1, LOW);
      digitalWrite(motA2, pwmVa);
      analogWrite(motB1, pwmVb);
      digitalWrite(motB2, LOW);
      break;

      //1 Motor

    case 4:
      analogWrite(motA1, LOW);
      digitalWrite(motA2, pwmVa);
      break;
  }
}
void drive::brake(int pwmVa, int pwmVb) {  //Brake, depending on the driver it can be soft or hard braking. Chek the used drivers datasheet for more info
  switch (type) {                          //Freno, puede ser suave o repentino dependiendo del controlador. Revisa la hoja de datos del controlador a usar para mas informacion

      //2 Motors, PWM via dedicated channel

    case 0:
      analogWrite(pwmA, pwmVa);
      digitalWrite(motA1, HIGH);
      digitalWrite(motA2, HIGH);
      analogWrite(pwmB, pwmVb);
      digitalWrite(motB1, HIGH);
      digitalWrite(motB2, HIGH);
      break;

      //2 Motors, No PWM

    case 1:
      digitalWrite(motA1, LOW);
      digitalWrite(motA2, LOW);
      digitalWrite(motB1, LOW);
      digitalWrite(motB2, LOW);
      break;

      //2 Motors, PWM via enable

    case 2:
      digitalWrite(en1, LOW);
      digitalWrite(motA1, LOW);
      digitalWrite(motA2, LOW);
      digitalWrite(en2, LOW);
      digitalWrite(motB1, LOW);
      digitalWrite(motB2, LOW);
      break;

      //2 Motors, No PWM/ PWM via input

    case 3:
      digitalWrite(motA1, HIGH);
      digitalWrite(motA2, HIGH);
      digitalWrite(motB1, HIGH);
      digitalWrite(motB2, HIGH);
      break;

      //1 Motor

    case 4:
      analogWrite(motA1, LOW);
      digitalWrite(motA2, LOW);
  }
}
void drive::sleep() {      //Desactiva el Enable o Standby, en algunos controladores esto activa el movimiento libre
  digitalWrite(en1, LOW);  //Turns of the Enable or Stanby pins, on some drivers this activates the freerun
  digitalWrite(en2, LOW);
  digitalWrite(stby, LOW);
}
void drive::wakeUp() {       //Vuelve a activar Stanby
  digitalWrite(stby, HIGH);  //Turns back on the Stanby pin
}
void drive::prueba(int pwmVa, int pwmVb) {  //Codigo de prueba, activa en secuencia todas las funciones de movimiento
  forward(pwmVa, pwmVb);                    //Test code, activates on secuence all the movility functions
  delay(750);
  backward(pwmVa, pwmVb);
  delay(750);
  left(pwmVa, pwmVb);
  delay(750);
  right(pwmVa, pwmVb);
  delay(750);
}
