
#include "Bluetooth.h"

SoftwareSerial HM10(2, 100); // RX = 2, TX = 3

char appData;  
String inData = "";

int motorSpeed = 200;
char lastDirection = 'S';

void bluetooth() {
  HM10.listen();  // listen the HM10 port

  while (HM10.available() > 0) {   // if HM10 sends something then read

    appData = HM10.read();

    inData = String(appData);  // save the data in string format

    Serial.write(appData);
    Serial.println();
    Serial.print("inData = ");
    Serial.println(inData);
  }

  if (inData == "F") {
    Serial.println("Car go forward");
    motorFunction('F', motorSpeed);
  } else if (inData == "S") {
    Serial.println("Car stop");
    motorFunction('S', 0);
  } else if (inData == "R") {
  motorFunction('R', motorSpeed);
  } else if (inData == "L") {
    motorFunction('L', 250);
  } else if (inData == "T") {
    motorFunction('T', motorSpeed);
  } else if (inData == "B") {
    motorFunction('B', motorSpeed);
  } else if (inData == "t") {
    motorFunction('t', motorSpeed);
  } else if (inData == "V") {
    if (motorSpeed <= 250) {
      motorSpeed = motorSpeed + 10;
      motorFunction(lastDirection, motorSpeed);
    } 
  } else if (inData == "v") {
    if (motorSpeed > 100) {
      motorSpeed = motorSpeed - 10;
      motorFunction(lastDirection, motorSpeed);
    }
  }
}

void bluetoothInit() {
  // set the bluetooth serial baudrate too 9600
  Serial.println("HM10 serial started at 9600");

  HM10.begin(9600);
}
