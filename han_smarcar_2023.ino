#include "Bluetooth.h"
#include "LcdMenu.h"
#include "LineTracker.h"
#include "MotorFunction.h"
#include "UltraSensor.h"

void menuScroll();
void menuResetSelect();
void modeSelection();
void buttonsInit();

int buttonScrollState = 1;
int lastButtonScrollState = 0;
unsigned long lastDebounceTimeScroll = 0;

int buttonSelectState = 1;
int lastButtonSelectState = 0;
unsigned long lastDebounceTimeSelect = 0;

int mode = 3;
int menu = 3;
bool modeLock = false;

void setup() {
  Serial.begin(9600);

  bluetoothInit();
  motorInit();
  buttonsInit();
  lcdMenuInit();
  lineTrackerInit();
  initUltrasoon();
  userTimeInit();
}

void loop() {
  motorCheckBlinkers();
  modeSelection();
  menuResetSelect();
  userTimeUpdate();
  
  switch (mode) {
    case 0:
      //bluetooth
      bluetooth();
      printMode(0);
      break;

    case 1:
      //autonoom
      autonoomDriving();
      printMode(1);
      break;

    case 2:
      //slave
      lineTracker();
      printMode(2);
      break;

    case 3:
      //selection menu
      menuPrint(menu);
      break;

    default:
      break;
  }
}

void menuResetSelect() {
  int delay = 50;
  int reading = digitalRead(PIN_BUTTON2);

  if (reading != lastButtonSelectState) {
    lastDebounceTimeSelect = millis();
  }

  if ((millis() - lastDebounceTimeSelect) > delay) {
    if (reading != buttonSelectState) {
      buttonSelectState = reading;
      if (buttonSelectState == LOW) {
        modeLock = !modeLock;
      }
      motorFunction('S', 0);
    }
  }
  lastButtonSelectState = reading;
}

void menuScroll() {
  int delay = 50;
  int reading = digitalRead(PIN_BUTTON1);

  if (reading != lastButtonScrollState) {
    lastDebounceTimeScroll = millis();
  }

  if ((millis() - lastDebounceTimeScroll) > delay) {
    if (reading != buttonScrollState) {
      buttonScrollState = reading;
      if (buttonScrollState == LOW) {
        if (menu == 3) {
          menu = 0;
        } else {
          menu++;
        }
      }
    }
  }
  lastButtonScrollState = reading;
}

void modeSelection() {
  if (modeLock == false) {
    menuScroll();
    mode = 3;
  } else {
    mode = menu;
  }
}

void buttonsInit() {
  pinMode(PIN_BUTTON1, INPUT);
  pinMode(PIN_BUTTON2, INPUT);
}
