#ifndef MotorFunction 
#define MotorFunction

#include <Arduino.h>
#include "io_pins.h"
#include "LcdMenu.h"



//declaring the functions
void motorFunction(char motorDirection, int motorSpeed);
void motorInit(void);
void motorCheckBlinkers(void);

#endif // MotorFunction
