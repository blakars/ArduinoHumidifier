int gesendeterWert = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    gesendeterWert = Serial.read();
    if (gesendeterWert == '1') {
      Serial.println("Wert war 1");  
    }
    else {
      Serial.println("Wert war nicht 1");
    }
  }
  delay(500);
  
}
