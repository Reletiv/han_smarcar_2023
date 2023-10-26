#include "LcdMenu.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

int EEPROMaddr = 0;
unsigned long userTime = 0;
unsigned long lastTimeUpdate = 0;

unsigned long lastPrint = 0;
int printDelay = 500;

char direction = 'F';

void lcdMenuInit() {
  lcd.backlight();
  lcd.init();

  byte pijl_links[8] = { B00000, B00000, B00000, B00100, B00010, B11111, B00010, B00100 };
  byte pijl_rechts[8] = { B00000, B00000, B00000, B00100, B01000, B11111, B01000, B00100 };
  byte pijl_achteruit[8] = { B00000, B00000, B00100, B01110, B10101, B00100, B00100, B00000 };
  byte pijl_vooruit[8] = { B00000, B00000, B00100, B00100, B10101, B01110, B00100, B00000 };

  lcd.createChar(0, pijl_rechts);
  lcd.createChar(1, pijl_links);
  lcd.createChar(2, pijl_vooruit);
  lcd.createChar(3, pijl_achteruit);
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
        lcd.print("min");
        break;
      case 1:
        lcd.clear();
        lcd.print("Autonoom");
        lcd.setCursor(0, 1);
        lcd.print("time ");
        lcd.print(userTime);
        lcd.print("min");
        break;
      case 2:
        lcd.clear();
        lcd.print("Slave");
        lcd.setCursor(0, 1);
        lcd.print("time ");
        lcd.print(userTime);
        lcd.print("min");
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
        lcd.print(">Remote");
        printDirectionArrow();
        lcd.setCursor(0, 1);
        lcd.print("time ");
        lcd.print(userTime);
        lcd.print("min");
        break;

      case 1:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(">Autonoom");
        printDirectionArrow();
        lcd.setCursor(0, 1);
        lcd.print("time ");
        lcd.print(userTime);
        lcd.print("min");
        break;

      case 2:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(">Slave");
        printDirectionArrow();
        lcd.setCursor(0, 1);
        lcd.print("time ");
        lcd.print(userTime);
        lcd.print("min");
        break;
    }
    lastPrint = millis();
  }
}

void userTimeUpdate() {
  unsigned long timeNow = millis();
  long delay = 60000;  // amount of milli seconds in a minute
  if (timeNow >= delay + lastTimeUpdate) {
    userTime++;
    EEPROM.write(EEPROMaddr, userTime);
    lastTimeUpdate = timeNow;
  }
}

void userTimeInit() {
  userTime = EEPROM.read(EEPROMaddr);
}

void setDirectionLcd(char dir) {
  direction = dir;
}

void printDirectionArrow() {
  if (direction == 'F') {
    lcd.setCursor(15, 0);
    lcd.write(byte(2));
  } else if (direction == 'R') {
    lcd.setCursor(15, 0);
    lcd.write(byte(0));
  } else if (direction == 'L') {
    lcd.setCursor(15, 0);
    lcd.write(byte(1));
  } else if (direction == 'B') {
    lcd.setCursor(15, 0);
    lcd.write(byte(3));
  }
}
