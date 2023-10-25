 #ifndef LcdMenu
#define LcdMenu

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "io_pins.h"
#include "Bluetooth.h"
#include "LineTracker.h"
#include "UltraSensor.h"


//declaring the function
void lcdMenuInit(void);
void buttonsInit(void);
void modeSelection(void);
void menuPrint(void);
void menuScroll(void);
void menuReset(void);

#endif //LcdMenu
