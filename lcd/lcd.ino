#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  lcd.begin(16,2);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Heellooo!");
  lcd.setCursor(0,1);
  lcd.print("Schau mal...");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("...ist das nicht");
  lcd.setCursor(0,1);
  lcd.print("toll? :D");
  delay(5000);
  lcd.clear();
}