#include "Arduino.h"
#include "LcdMenu.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

int lastButtonScrollState = 1;
int lastButtonScrollPressed = 0;
int selection = 3;
int lastButtonSelectState = 1;
int lastButtonSelectPressed = 0;
int select = 0;
int lastPrint = 0;
int printDelay = 500;

void lcdMenuInit() {
  lcd.backlight();
  lcd.init();
}

void buttonsInit() {
  pinMode(PIN_BUTTON1, INPUT);
  pinMode(PIN_BUTTON2, INPUT);
}

void menuReset() {
  int delayButtonSelect = 50;
  int buttonSelectState = digitalRead(PIN_BUTTON2);
  int nuButtonSelectPressed = millis();
  if (nuButtonSelectPressed >= lastButtonSelectPressed + delayButtonSelect) {
    if (lastButtonSelectState != buttonSelectState) {
      if (buttonSelectState == LOW) {
        if (selection == 3) {
          selection = select;
        } else if (select < 3) {
          selection = 3;
          motorFunction('S', 0);
        }
      }
      lastButtonSelectPressed = nuButtonSelectPressed;\
    }
  }
}

void menuScroll() {
  int delayButtonScroll = 50;
  int buttonScrollState = digitalRead(PIN_BUTTON1);
  int nuButtonScrollPressed = millis();

  if (nuButtonScrollPressed >= lastButtonScrollPressed + delayButtonScroll) {
    if (lastButtonScrollState != buttonScrollState) {
      if (buttonScrollState == 0) {
        if (select < 2) {
          select++;
        } else if (select == 2) {
          select = 0;
        }
      }
      lastButtonScrollPressed = nuButtonScrollPressed;
    }
  }
}


void modeSelection() {
  menuScroll();
  menuReset();


  //Selection of the mode
<<<<<<< HEAD
  int nuPrintTime = millis();
  if (nuPrintTime >= lastPrint + printDelay) {
    switch (selection) {
      case 0:
        //bluetooth
        lcd.clear();
        lcd.print("Hoi");
        bluetooth();
        break;
=======
  switch (selection) {
    case 0:
    lcd.clear();
    lcd.print("Hoi");
    bluetooth();
    lcd.clear();
    lcd.print("Hoi");
    break;
    
    case 1:
    //ultraSoon
    break;
>>>>>>> d9cf4a19f1712b657a0e5f1e70b788f408259bdc

      case 1:
        //ultraSoon
        ultrasoon();
        lcd.clear();
        lcd.print("hey Stan");
        break;

      case 2:
        //Linetracker
        lineTracker();
        lcd.clear();
        lcd.print("test");
        break;

      case 3:
        menuPrint();
        break;

      default:
        break;
    }
    lastPrint = nuPrintTime;
  }
}

void menuPrint() {
  switch (select) {
    case 0:
      lcd.clear();
      lcd.print("Bluetooth");
      break;
    case 1:
      lcd.clear();
      lcd.print("Autonoom");
      break;
    case 2:
      lcd.clear();
      lcd.print("Slave");
      break;
    default:
      break;
  }
}
