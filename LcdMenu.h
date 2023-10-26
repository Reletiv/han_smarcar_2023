 #ifndef LcdMenu
#define LcdMenu

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include "io_pins.h"
#include "Bluetooth.h"
#include "LineTracker.h"
#include "UltraSensor.h"


//declaring the function
void lcdMenuInit(void);
void menuPrint(int menu);
void printMode(int mode);
void userTimeUpdate(void);
void userTimeInit(void);
void setDirectionLcd(char dir);
void printDirectionArrow(void);


#endif //LcdMenu
