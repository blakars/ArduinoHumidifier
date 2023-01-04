#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
//int pressure; //Wertebereich von 0 bis 1023 -> 1023 entspricht 10kg
long duration;
int distance;

const int trig = 12;
const int echo = 13;

void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);

//pinMode(A0,INPUT);
//Serial.begin(9600);

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
  //pressure=analogRead(A0);
  distance=calculateDistance();
  lcd.clear();
  lcd.print("Abstand:");
  lcd.setCursor(0,1);
  lcd.print(String(distance));
  Serial.println(distance);
  delay(1000);

}

int calculateDistance(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2*10;
  return distance;
}
