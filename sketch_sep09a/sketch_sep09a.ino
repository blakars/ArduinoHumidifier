int switchState = 0;
int ledR1 = 5;
int ledR2 = 4;
int ledG = 3;
int eingang = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledR1,OUTPUT);
  pinMode(ledR2,OUTPUT);
  pinMode(ledG,OUTPUT);
  pinMode(eingang,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(eingang);

  if (switchState == LOW) {
    digitalWrite(ledG,HIGH);
    digitalWrite(ledR2,LOW);
    digitalWrite(ledR1,LOW);
    
  }

  else {
    digitalWrite(ledG,LOW);
    digitalWrite(ledR2,HIGH);
    digitalWrite(ledR1,LOW);
    delay(250);
    digitalWrite(ledR2,LOW);
    digitalWrite(ledR1,HIGH);
    delay(250);
  }

  
}
