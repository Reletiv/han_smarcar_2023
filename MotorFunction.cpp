#include "motorfunction.h"

char motorDir;
int blinkerInterval = 500;
unsigned long previousMillisBlinkers;
bool ledState;


void motorInit() {
 // Set all the motor control pins to outputs
  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_ENB, OUTPUT);
  pinMode(PIN_INA, OUTPUT);
  pinMode(PIN_INB, OUTPUT);
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  
}

void motorCheckBlinkers()
{
  unsigned long currentMillisBlinkers = millis();

  if (currentMillisBlinkers - previousMillisBlinkers >= blinkerInterval) {
    // save the last time you blinked the LED
    previousMillisBlinkers = currentMillisBlinkers;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    // set the LED with the ledState of the variable:
    if(motorDir == 'L')
    {
      digitalWrite(PIN_LED1, ledState);
      digitalWrite(PIN_LED2, LOW);
    }
    else if(motorDir == 'R')
    {
      digitalWrite(PIN_LED2, ledState);
      digitalWrite(PIN_LED1, LOW);
    } else
    {
      digitalWrite(PIN_LED1, LOW);
      digitalWrite(PIN_LED2, LOW);
    }
  }
}



void motorFunction(char motorDirection, int motorSpeed)
{
//  Serial.println(motorDirection);
//  Serial.println(motorDirection);
//  Serial.println(motorDirection);
//  Serial.println(motorDirection);
//  Serial.println(motorDirection);
  
  switch(motorDirection) {
  // forwards
  case 'F':
    // set both motors in forward mode
    digitalWrite(PIN_INA, HIGH);
    digitalWrite(PIN_INB, HIGH);
    analogWrite(PIN_ENA, motorSpeed);
    analogWrite(PIN_ENB, motorSpeed);
    motorDir = 'F';
    setDirectionLcd('F');

    break;
  // backwards
  case 'B':
    // set both motors in backwards mode
    digitalWrite(PIN_INA, LOW);
    digitalWrite(PIN_INB, LOW); 
    analogWrite(PIN_ENA, motorSpeed);
    analogWrite(PIN_ENB, motorSpeed);  
    motorDir = 'B';
    setDirectionLcd('B');
    break;
  // left
  case 'R':
    // only PIN_ENAble the right motor, this results in turning left
    digitalWrite(PIN_INA, HIGH);
    digitalWrite(PIN_INB, HIGH); 
    analogWrite(PIN_ENA, motorSpeed);
    analogWrite(PIN_ENB, (motorSpeed / 2));
    motorDir = 'R';
    setDirectionLcd('R');
    break;
  // right
  case 'L':
    // only PIN_ENAble the right motor, this results in turning left
    digitalWrite(PIN_INA, HIGH);
    digitalWrite(PIN_INB, HIGH); 
    analogWrite(PIN_ENA, (motorSpeed / 2));
    analogWrite(PIN_ENB, motorSpeed);
    motorDir = 'L';
    setDirectionLcd('L');
    break; 
    // turn 
  case 'T':
    // making left and right motors run in opposite direction, this results in the robot turning
    digitalWrite(PIN_INA, HIGH);
    digitalWrite(PIN_INB, LOW); 
    analogWrite(PIN_ENA, motorSpeed);
    analogWrite(PIN_ENB, motorSpeed);
    motorDir = 'L';
    setDirectionLcd('L');
    break; 
  case 't':
    // making left and right motors run in opposite direction, this results in the robot turning
    digitalWrite(PIN_INA, LOW);
    digitalWrite(PIN_INB, HIGH); 
    analogWrite(PIN_ENA, motorSpeed);
    analogWrite(PIN_ENB, motorSpeed);
    motorDir = 'R';
    setDirectionLcd('R');
    break; 
  // stop
  case 'S':
    // disable both motors, this stops the robot 
    analogWrite(PIN_ENA, 0);
    analogWrite(PIN_ENB, 0);
    motorDir = 'S';
    setDirectionLcd('S');
    break; 
  }
}
