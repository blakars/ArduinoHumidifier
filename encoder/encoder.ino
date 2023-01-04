#include <Encoder.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
const int clk=2;
const int dt=3;
long altePosition=0;
float humSollInit=50;
float encData=0;

Encoder myEncoder(dt,clk);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Luft-Befeuchter");
  lcd.setCursor(0,1);
  lcd.print("wird gestartet");

}

void loop() {
  long neuePosition=myEncoder.read();
  if(neuePosition!=altePosition) {
    altePosition=neuePosition;
    Serial.println(neuePosition);
    encData=neuePosition/4;
  }
  float humSoll=humSollInit+encData;
  if(humSoll<0){
    humSoll=0;
    myEncoder.write(-200);
  }
  if(humSoll>100){
    humSoll=100;
    myEncoder.write(200);
  }
  lcd.clear();
  lcd.print(humSoll);
  // put your main code here, to run repeatedly:

}
