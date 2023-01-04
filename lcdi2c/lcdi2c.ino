#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int pressure; //Wertebereich von 0 bis 1023 -> 1023 entspricht 10kg

void setup() {

pinMode(A0,INPUT);
Serial.begin(9600);

  lcd.init();
  //String s="Test";
  //int luftF_soll=50;
  //int luftF_ist=48;

  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hallo, gleich...");
  //lcd.print("Soll: " +String(luftF_soll)+"%");
  lcd.setCursor(0,1);
  //lcd.print("Ist:  "+String(luftF_ist)+"%");
  lcd.print("startet Messung.");

}

void loop() {
  pressure=analogRead(A0);
  lcd.clear();
  lcd.print("Druck:");
  lcd.setCursor(0,1);
  lcd.print(String(pressure));
  Serial.println(pressure);
  delay(1000);



}
