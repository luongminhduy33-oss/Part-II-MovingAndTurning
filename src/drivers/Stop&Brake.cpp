#include <Arduino.h>

#define ENA 6
#define ENB 9
#define IN1 4
#define IN2 5
#define IN3 7
#define IN4 8

void stopMotor() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void brakeMotor() {
  analogWrite(ENA, 0);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, 0);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}
