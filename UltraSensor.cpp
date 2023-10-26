//STAN
#include <Arduino.h>//wordt geinclude in je code als je meerdere keren ultrasoon gebruikt hoeft fity niet nog een keer daarom #ifndef
#include "UltraSensor.h"
#define ECHO 12        // Pin received echo pulse
#define TRIGGER 13     // Pin sends shot pulse


unsigned long previousMicros = 0; // will sotre last time TRIGGER was updated
unsigned long previousMicros1 = 0; // will sotre last time TRIGGER was updated
unsigned long previousMicros2 = 0; // will sotre last time TRIGGER was updated
unsigned long executeTime = 0; // will sotre last time TRIGGER was updated


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

void autonoomDriving()
{
  int distance = ultrasonicSensor();//places distance variable here so that it is available in orther file where the funtion is included
//  if (distance > 0) {//dit kan bijten beschouwing zodat 
//    Serial.print("distance: ");
//    Serial.println(distance);
//  }
  if (distance > 30 && distance <= 1000) {
    motorFunction('F', 100);
    Serial.println(distance);
  }
  else if ((distance <= 30 || distance > 1000) && distance != 0) {
    motorFunction('T', 150);
    Serial.println(distance);
  }
}

int ultrasonicSensor() 
{
  int distance; // the distance in cms
  //kijk of je de sensor 10 microseconde hoog kunt houden en 2 microseconde laag
  // check to see if it's time to change the state of the TRIGGER
  unsigned long currentMicros = micros();
//      previousMicros1 = currentMicros; // remember the time

  if ((triggerState == LOW) && (currentMicros - previousMicros >= OffTime))//checks if the the trigger is OFF long enough to see if turn it on
  {
    triggerState = HIGH; // turn it on
    previousMicros = currentMicros; // remember the time
    digitalWrite(TRIGGER, triggerState); // update the actual trigger
  }
  else if ((triggerState == HIGH) && (currentMicros - previousMicros >= OnTime))//checks if the the trigger is ON long enough to see if turn it off
  { 
    triggerState = LOW; // turn it off
    previousMicros = currentMicros; // remember the time
    digitalWrite(TRIGGER, triggerState); // update the actual trigger
  }
  duration = pulseIn(ECHO, HIGH);//maximaal 10x per seconde? can put a time in microsecond after high ",time"
  distance = (duration * 0.017);//comagetallen rekenen duurt lang. *0.017 = 0.034/2 (distance = duration / (58+(14/17)))
 // distance = (duration / (58+(14/17));//comagetallen rekenen duurt lang. distance = duration : 58
// previousMicros2 = currentMicros; // remember the time
// executeTime = previousMicros2 - previousMicros1;
// Serial.print("executeTime:");
// Serial.println(executeTime);
 return distance;
}
