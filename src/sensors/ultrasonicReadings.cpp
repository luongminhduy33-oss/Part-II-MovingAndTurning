#include <Arduino.h>

#define TRIG_F 10
#define ECHO_F 11

#define TRIG_L 12
#define ECHO_L A3

#define TRIG_R A4
#define ECHO_R A5

long durationFront;
long durationLeft;
long durationRight;

int cmF;
int cmL;
int cmR;

void setup(){
  pinMode(TRIG_F, OUTPUT);
  pinMode(TRIG_L, OUTPUT);
  pinMode(TRIG_R, OUTPUT);

  pinMode(ECHO_F, INPUT);
  pinMode(ECHO_L, INPUT);
  pinMode(ECHO_R, INPUT);
}

long microsecondsToCentimeters(long microseconds) {
  //The speed of sound is 340m/s -> 29 microseconds per centimer, the ping travels forth and back -> half the distance travelled
  return microseconds / 29 / 2;
}

long readSensors(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 3200); //3200 microseconds -> 55cm max distance 
  return duration;
}

void isWallDistance() {
  //Front sensor
  cmF = microsecondsToCentimeters(readSensors(TRIG_F, ECHO_F));
  //Left sensor
  cmL = microsecondsToCentimeters(readSensors(TRIG_L, ECHO_L));
  //Right sensor
  cmR = microsecondsToCentimeters(readSensors(TRIG_R, ECHO_R));
  //We can't trigger all of the signals simutaneously because of cross-talk between sensors
}
