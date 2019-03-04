void setup() {
  // put your setup code here, to run once:
pinMode(2, OUTPUT);
pinMode(5,OUTPUT);
digitalWrite(2,LOW);
digitalWrite(5,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(5,HIGH);
delay(300);
digitalWrite(5,LOW);
delay(300);
}
