#include "LcdMenu.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

int lastButtonScrollState = 1;
int lastButtonScrollPressed = 0;
int selection = 3;
int lastButtonSelectState = 1;
int lastButtonSelectPressed = 0;
int select = 0;

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
  if (nuButtonSelectPressed >= lastButtonSelectPressed - delayButtonSelect) {
    if (lastButtonSelectState != buttonSelectState) {
      if (selection == 3) {
        selection = select;
      } else if (select < 3) {
        selection = 3;
      }
    }
  }
}

void menuScroll() {
  int delayButtonScroll = 50;
  int buttonScrollState = digitalRead(PIN_BUTTON1);
  int nuButtonScrollPressed = millis();

  if (nuButtonScrollPressed >= lastButtonScrollPressed - delayButtonScroll) {
    if (lastButtonScrollState != buttonScrollState) {
      if (buttonScrollState == 0) {
        if (select < 2) {
          select++;
        } else if (select == 2) {
          select = 0;
        }
      }
    }
  }
}
  

void modeSelection() {
  menuScroll();
  menuReset();

  
  //Selection of the mode
  switch (selection) {
    case 0:
    lcd.clear();
    lcd.print("Hoi");
    bluetooth();
    break;
    
    case 1:
    //ultraSoon
    break;

    case 2:
    //lineTracker
    break;

    case 3:
    menuPrint();
    break;

    default:
    break;
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
