#include "LineTracker.h"


bool sensorOne = 0;
bool sensorTwo = 0;
bool sensorThree = 0;
bool sensorFour = 0;

int SlaveSpeed = 120;

void lineTrackerInit() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}

void lineTracker() {
  // put your main code here, to run repeatedly:

  sensorOne = digitalRead(A0);
  sensorTwo = digitalRead(A1);
  sensorThree = digitalRead(A2);
  sensorFour = digitalRead(A3);

  // Serial.print(sensorOne);
  // Serial.print(" ");
  // Serial.print(sensorTwo);
  // Serial.print(" ");
  // Serial.print(sensorThree);
  // Serial.print(" ");
  // Serial.print(sensorFour);
  // Serial.println(" ");


  if (sensorOne == 0 && sensorTwo == 0 && sensorThree == 0 && sensorFour == 0) {
    //forward
    motorFunction('F', SlaveSpeed);
    Serial.println("Forward");
  }
  else if (sensorOne == 0 && sensorTwo == 0 && sensorThree == 1 && sensorFour == 0) {
    //left
    motorFunction('T', SlaveSpeed);
    Serial.println("Left");
  }
  else if (sensorOne == 0 && sensorTwo == 1 && sensorThree == 0 && sensorFour == 0) {
    //right
    motorFunction('t', SlaveSpeed);
    Serial.println("right");
  }
  else if (sensorOne == 0 && sensorTwo == 0 && sensorThree == 1 || sensorFour == 1) {
    //big left
    motorFunction('T', 200);
    Serial.println("Left");
  }
  else if (sensorOne == 1 || sensorTwo == 1 && sensorThree == 0 && sensorFour == 0) {
    //big right
    motorFunction('t', 200);
    Serial.println("right");
  }
  else if (sensorOne == 0 && sensorTwo == 1 && sensorThree == 1 && sensorFour == 0) {
    //forward
    motorFunction('F', 100);
    Serial.println("Forward");
  }
}

