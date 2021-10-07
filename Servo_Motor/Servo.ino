#include <Servo.h>    //Incluimos uma biblioteca do servo

Servo servo_7;        //Definimos o nome "servo_7" para o servo motor

void setup()
{
  servo_7.attach(7);
}

void loop()
{
  int pot = analogRead(0);
  int angulo=map(pot, 0, 1023, 0, 180);
  servo_7.write(angulo);
  Serial.print( "O angulo é: ");
  Serial.print (angulo);
  delay(40);
}
