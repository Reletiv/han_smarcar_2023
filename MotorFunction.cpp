#include "motorfunction.h"


void motorInit() {
 // Set all the motor control pins to outputs
  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_ENB, OUTPUT);
  pinMode(PIN_INA, OUTPUT);
  pinMode(PIN_INB, OUTPUT);
  
}

void motorCheckBlinkers()
{
  /*
  unsigned long currentMillisBlinkers = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
  */
}



void motorFunction(char motorDirection, int motorSpeed)
{
  Serial.println(motorDirection);
  Serial.println(motorDirection);
  Serial.println(motorDirection);
  Serial.println(motorDirection);
  Serial.println(motorDirection);
  
  switch(motorDirection) {
  // forwards
  case 'F':
    // set both motors in forward mode
    digitalWrite(PIN_INA, HIGH);
    digitalWrite(PIN_INB, HIGH);
    analogWrite(PIN_ENA, motorSpeed);
    analogWrite(PIN_ENB, motorSpeed);
    break;
  // backwards
  case 'B':
    // set both motors in backwards mode
    digitalWrite(PIN_INA, LOW);
    digitalWrite(PIN_INB, LOW); 
    analogWrite(PIN_ENA, motorSpeed);
    analogWrite(PIN_ENB, motorSpeed);  
    break;
  // left
  case 'R':
    // only PIN_ENAble the right motor, this results in turning left
    digitalWrite(PIN_INA, HIGH);
    digitalWrite(PIN_INB, HIGH); 
    analogWrite(PIN_ENA, motorSpeed);
    analogWrite(PIN_ENB, (motorSpeed / 1.75));
    break;
  // right
  case 'L':
    // only PIN_ENAble the right motor, this results in turning left
    digitalWrite(PIN_INA, HIGH);
    digitalWrite(PIN_INB, HIGH); 
    analogWrite(PIN_ENA, (motorSpeed / 1.75));
    analogWrite(PIN_ENB, motorSpeed);
    break; 
    // turn 
  case 'T':
    // making left and right motors run in opposite direction, this results in the robot turning
    digitalWrite(PIN_INA, HIGH);
    digitalWrite(PIN_INB, LOW); 
    analogWrite(PIN_ENA, motorSpeed);
    analogWrite(PIN_ENB, motorSpeed);
    break; 
  case 't':
    // making left and right motors run in opposite direction, this results in the robot turning
    digitalWrite(PIN_INA, LOW);
    digitalWrite(PIN_INB, HIGH); 
    analogWrite(PIN_ENA, motorSpeed);
    analogWrite(PIN_ENB, motorSpeed);
    break; 
  // stop
  case 'S':
    // disable both motors, this stops the robot 
    analogWrite(PIN_ENA, 0);
    analogWrite(PIN_ENB, 0);
    break; 

    
  }
}
