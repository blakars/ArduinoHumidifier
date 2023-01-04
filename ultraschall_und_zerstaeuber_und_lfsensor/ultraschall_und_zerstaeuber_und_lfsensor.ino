#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Encoder.h>
LiquidCrystal_I2C lcd(0x27,16,2);
long duration;
int distance;
float hum;
float temp;

const int clk = 2;
const int dt = 3;
const int trig = 12;
const int echo = 13;
const int atomizer =5;
const int dhtpin =10;
long altePosition = 0;
float humSollInit =50;
float encData=0;

DHT dht(dhtpin,DHT22);
Encoder myEnc(dt,clk);

void setup() {
  
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(atomizer,OUTPUT);
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Luft-Befeuchter");
  lcd.setCursor(0,1);
  lcd.print("wird gestartet");
}

void loop() {
  long neuePosition=myEnc.read();
  if (neuePosition!=altePosition){
    altePosition=neuePosition;
    Serial.println(neuePosition);
    encData=neuePosition/4;
  }
  float humSoll=humSollInit+encData;
  if(humSoll<0){
    humSoll=0;
    myEnc.write(-200);
  }
  if(humSoll>100){
    humSoll=100;
    myEnc.write(200);
  }
  distance=calculateDistance();
  //Serial.println(distance);
  if(distance>=40){
    digitalWrite(atomizer,LOW);
    lcd.setCursor(0,0);
    lcd.print("Bitte Wasser....");
    lcd.setCursor(0,1);
    lcd.print("....nachfuellen.");
    Serial.println(distance);
  }
  else{
    hum=dht.readHumidity();
    temp=dht.readTemperature();
    //Serial.println(temp);
    lcd.setCursor(0,0);
    lcd.print("I: ");
    lcd.print(round(hum));
    lcd.print("%    S: ");
    lcd.print(round(humSoll));
    lcd.print("%");
    lcd.setCursor(0,1);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print("C    ");
    if(hum<humSoll) {
      digitalWrite(atomizer,HIGH);
    }
    else{
      digitalWrite(atomizer,LOW);
    }
  }
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
