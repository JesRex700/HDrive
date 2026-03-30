#include "hdrive.h"

drive::drive(byte stby, byte motA1, byte motA2, byte motB1, byte motB2) { //Esta seccion declara los pines que se usaran fisicamente en el microcontrolador para cada entrada del controlador; stby debe conectarse fisicamente a los 2 enable en caso de tenerlos el controlador a usar
  this->motA1 = motA1;//Motor A, Input 1                                  //This secction declares the pins that will be used physically on the microcontroller for eachn of the drivers inputs; stby muist be connected physically to both enable pins in case of having them
  this->motA2 = motA2;//Motor A, Input 2 //Motor Derecho / Right Motor
  this->motB1 = motB1;//Motor B, Input 1
  this->motB2 = motB2;//Motor B, Input 2 //Motor Izquierdo / Left Motor
  this->stby = stby;  //Stanby / Enable
}
void drive::init() {        //Inicia todos los pines del microcontrolador asociados al controlador, estos estan pensados para arduino, otros microcontroladores tal vez requieran configuracion adicional
  pinMode(motA1, OUTPUT);   //Initialize all the microcontrolles driver ralated pins, this are designed for arduino, other microcontrollers might need extra configuration
  pinMode(motA2, OUTPUT);
  pinMode(motB1, OUTPUT);
  pinMode(motB2, OUTPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(stby, OUTPUT);
  digitalWrite(stby, HIGH);
  off();
}
void drive::off() {
  digitalWrite(motA1, LOW);
  digitalWrite(motA2, LOW);
  digitalWrite(motB1, LOW);
  digitalWrite(motB2, LOW);
}
void drive::setpwm(byte pwmA, byte pwmB) { //Activa la funcion pwm, si no se necesita dedbe dejarse fuera del codigo para evitar problemas
  this->pwmA = pwmA;//Pin PWM Motor A      //Activates the pwm function, if not needed this must be left out to aviod problems
  this->pwmB = pwmB;//Pin PWM Motor B
}
void drive::forward(int pwmv) { //Movimiento frontal
  analogWrite(pwmA, pwmv);      //Forwards movement
  digitalWrite(motA1, HIGH);
  digitalWrite(motA2, LOW);
  analogWrite(pwmB, pwmv);
  digitalWrite(motB1, HIGH);
  digitalWrite(motB2, LOW);
}
void drive::backward(int pwmv) {  //Movimiento hacia atra
  analogWrite(pwmA, pwmv);        //Backwards movement
  digitalWrite(motA1, LOW);
  digitalWrite(motA2, HIGH);
  analogWrite(pwmB, pwmv);
  digitalWrite(motB1, LOW);
  digitalWrite(motB2, HIGH);
}
void drive::left(int pwmv) {  //Giro hacia la Izquierda, asumiendo que el motor B esta a la derecha
  analogWrite(pwmA, pwmv);    //Left turn, asuming that motor B is on the left side
  digitalWrite(motA1, HIGH);
  digitalWrite(motA2, LOW);
  analogWrite(pwmB, pwmv);
  digitalWrite(motB1, LOW);
  digitalWrite(motB2, HIGH);
}
void drive::right(int pwmv) { //Giro hacia la derecha, asumiendo que el motor B esta a la derecha
  analogWrite(pwmA, pwmv);    //Right turn, asuming that motor B is on the left side
  digitalWrite(motA1, LOW);
  digitalWrite(motA2, HIGH);
  analogWrite(pwmB, pwmv);
  digitalWrite(motB1, HIGH);
  digitalWrite(motB2, LOW);
}
void drive::embrake(int pwmv) { //Freno de emergencia. Usar con precaucion, comprobado solo en el controlador TB6612FNG 
    analogWrite(pwmA, pwmv);    //Emergency brake. Use with caution, proved only on driver TB6612FNG
  digitalWrite(motA1, HIGH);
  digitalWrite(motA2, HIGH);
  analogWrite(pwmB, pwmv);
  digitalWrite(motB1, HIGH);
  digitalWrite(motB2, HIGH);
}
void drive::freerun(){        //Desactiva el Enable o Standby, en algunos controladores esto activa el movimiento libre
  digitalWrite(stby, LOW);    //Turns of the Enable or Stanby pins, on some drivers this activates the freerun
}
void drive::enbrun(){         //Vuelve a activar el Enable o Stanby
  digitalWrite(stby, HIGH);   //Turns back on the Enable or Stanby pins
}
void drive::prueba(int pwmv) {  //Codigo de prueba, activa en secuencia todas las funciones de movimiento
  adelante(pwmv);               //Test code, activates on secuence all the movility functions
  delay(750);
  atras(pwmv);
  delay(750);
  izquierda(pwmv);
  delay(750);
  derecha(pwmv);
  delay(750);
}
