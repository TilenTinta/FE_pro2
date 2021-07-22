#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

unsigned int stevilo = 0;
int stevilo_neg = 0;

char customKey;
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {7, 6, 5, 4};
byte colPins[COLS] = {3, 2, 1, 0};


Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
}


void loop()
{

  customKey = customKeypad.getKey();
  switch (customKey)
  {
    case '0' ... '9': // Zajem števila
      lcd.setCursor(0, 0);
      if (stevilo <= 2300) {
        stevilo = stevilo * 10 + (customKey - '0');
        lcd.print(stevilo);
      }
      break;

    case 'A': // Zamenjaj predznak
      lcd.setCursor(0, 1);
      lcd.print("                ");
      stevilo_neg = stevilo * (-1);
      lcd.setCursor(0, 1);
      lcd.print(stevilo_neg);
      break;

    case 'B': // Binarno
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("BIN:");
      lcd.setCursor(5, 1);
      lcd.print(stevilo, BIN);
      break;

    case 'C':
      stevilo = 0;
      stevilo_neg = 0;
      lcd.clear();
      break;

    case 'D': // Hex
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print("HEX:");
      lcd.setCursor(5, 1);
      lcd.print(stevilo, HEX);
      break;
  }
}