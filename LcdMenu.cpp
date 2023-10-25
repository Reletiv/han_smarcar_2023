#include "LcdMenu.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

int EEPROMaddr = 0;
unsigned long userTime = 0;
int lastTimeUpdate = 0;

unsigned long lastPrint = 0;
int printDelay = 500;

void lcdMenuInit() {
  lcd.backlight();
  lcd.init();
}

void menuPrint(int menu) {
  if (lastPrint + printDelay < millis()) {
    switch (menu) {
      case 0:
        lcd.clear();
        lcd.print("Bluetooth");
        lcd.setCursor(0, 1);
        lcd.print("time ");
        lcd.print(userTime);
        break;
      case 1:
        lcd.clear();
        lcd.print("Autonoom");
        break;
      case 2:
        lcd.clear();
        lcd.print("Slave");
        break;

      case 3:
        lcd.clear();
        lcd.print("Team Antimotive");
        lcd.setCursor(0, 1);
        lcd.print("DeBuggy");
        break;

      default:
        break;
    }
    lastPrint = millis();
  }
}

void printMode(int mode) {
  if (lastPrint + printDelay < millis()) {
    switch (mode) {
      case 0:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Remote 1234 m/s>");  //">"is placeholder voor richtingspijltje
        break;

      case 1:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Auto 1234567 m/s");
        break;

      case 2:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Slave 123456 m/s");
        break;
    }
    lastPrint = millis();
  }
}

void userTimeUpdate() {
  unsigned long timeNow = millis();
  int delay = 60000; // amount of milli seconds in a minute
  if (timeNow > delay + lastTimeUpdate) {
    userTime++;
    EEPROM.write(EEPROMaddr, userTime);
  }
}

void userTimeInit() {
  userTime = EEPROM.read(EEPROMaddr);
}


byte pijl_rechts[] = {
  B00000,
  B00000,
  B00000,
  B00100,
  B00010,
  B11111,
  B00010,
  B00100
};

byte pijl_links[] = {
  B00000,
  B00000,
  B00000,
  B00100,
  B01000,
  B11111,
  B01000,
  B00100
};

byte pijl_vooruit[] = {
  B00000,
  B00000,
  B00000,
  B00100,
  B01110,
  B10101,
  B00100,
  B00100
};

byte pijl_achteruit[] = {
  B00000,
  B00000,
  B00000,
  B00100,
  B00100,
  B10101,
  B01110,
  B00100
};
