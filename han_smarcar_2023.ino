#include "Bluetooth.h"
#include "LcdMenu.h"
#include "LineTracker.h"
#include "MotorFunction.h"
#include "UltraSensor.h"


void setup() 
{
  Serial.begin(9600);

  bluetoothInit();
  motorInit();
  buttonsInit();
  lcdMenuInit();
  lineTrackerInit();
<<<<<<< HEAD
  initUltrasoon();
}

void loop() {
  modeSelection();
=======
  
}

void loop() 
{
//  modeSelection();
  motorCheckBlinkers();
  bluetooth();
>>>>>>> d9cf4a19f1712b657a0e5f1e70b788f408259bdc
}
