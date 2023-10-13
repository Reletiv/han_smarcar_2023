#ifndef LcdMenu
#define LcdMenu

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "io_pins.h"


//declaring the function
void lcdMenuInit(void);
void buttonsInit(void);
void modeSelection(void);
void menuPrint(void);

#endif //LcdMenu
