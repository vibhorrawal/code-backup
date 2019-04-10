int redLed = 2;
int blueLed = 4;
int greenLed = 3;
int input = A0;
void setup() {
  Serial.begin(9600);
pinMode(redLed,OUTPUT);
pinMode(greenLed,OUTPUT);
pinMode(blueLed,OUTPUT);
pinMode(input,INPUT);
}

void loop() {
  
digitalWrite(redLed,HIGH);
delay(100);
Serial.print("r=");

Serial.print(analogRead(input));
Serial.print("  ");
digitalWrite(redLed,LOW);
delay(100);
digitalWrite(greenLed,HIGH);
delay(100);
Serial.print("g=");
Serial.print(analogRead(input));
Serial.print("  ");
digitalWrite(greenLed,LOW);
delay(100);

digitalWrite(blueLed,HIGH);
delay(100);
Serial.print("b=");

Serial.print(analogRead(input));

Serial.print("  ");
digitalWrite(blueLed,LOW);
delay(100);
Serial.println(" ");


}
