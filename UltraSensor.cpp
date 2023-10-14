//STAN
#include <Arduino.h>
#include "UltraSensor.h"
#define ECHO 12        // Pin received echo pulse
#define TRIGGER 13     // Pin sends shot pulse

int distance; // the distance in cms
unsigned long previousMicros = 0; // will sotre last time TRIGGER was updated
long OnTime = 10; //microseconds of on-time
long OffTime = 2; //microseconds of off-time
unsigned long previousMillis = 0; //will store last time viewTime was updated
int triggerState = LOW; // triggerState used to set it up
long duration;
void initUltrasoon()
{
  Serial.begin(9600);
  pinMode(ECHO, INPUT);
  pinMode(TRIGGER, OUTPUT);
}

void ultrasoon()
{
  // check to see if it's time to change the state of the TRIGGER
  unsigned long currentMicros = micros();
  if ((triggerState == LOW) && (currentMicros - previousMicros >= OffTime))
  {
    triggerState = HIGH; // turn it on
    previousMicros = currentMicros; // remember the time
    digitalWrite(TRIGGER, triggerState); // update the actual trigger
  }
  else if ((triggerState == HIGH) && (currentMicros - previousMicros >= OnTime))
  {
    triggerState = LOW; // turn it off
    previousMicros = currentMicros; // remember the time
    digitalWrite(TRIGGER, triggerState); // update the actual trigger
  }



  duration = pulseIn(ECHO, HIGH  );
  distance = ((duration * 0.034) / 2);
  if (distance > 0) {
    Serial.print("distance: ");
    Serial.println(distance);
  }
  if (distance > 30 && distance < 1000) {
    motorFunction('F', 100);
    Serial.println(distance);
  }
  else if (distance <= 30 || distance > 350) {
    motorFunction('T', 150);
    Serial.println(distance);
  }
}
