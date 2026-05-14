#include <Arduino.h>

#define ENA 6
#define ENB 9
#define IN1 4
#define IN2 5
#define IN3 7
#define IN4 8

int speedLeft;
int speedRight;

void setup()
{
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}
void setMotor(int speedLeft, int speedRight) {
  //Left Motor
  if(speedLeft >= 0) {
    analogWrite(ENA, speedLeft);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } 
  else
  {
    analogWrite(ENA, -speedLeft);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
  //Right Motor
  if(speedRight >= 0) {
    analogWrite(ENB, speedRight);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } 
  else 
  {
    analogWrite(ENB, -speedRight);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
}

//setMotor(100,100) -> move straight
//setMotor(-100,-100) -> move backward
//setMotor(-50, 50) -> turn left
//setMotor(50, -50) -> turn right
