#include "Bluetooth.h"
#include "LcdMenu.h"
#include "LineTracker.h"
#include "MotorFunction.h"
#include "UltraSensor.h"

void modeSelection(int selection);

void setup() {
  Serial.begin(9600);
  
  bluetoothInit();
  motorInit();
  buttonsInit(); 
  lcdMenuInit();
}

void loop() {
 modeSelection();
 

}

void modeSelection(int selection) {
  
}

