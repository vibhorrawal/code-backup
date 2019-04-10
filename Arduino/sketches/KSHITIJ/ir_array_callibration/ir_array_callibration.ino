int i;
int s[6];
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  s[0] = analogRead(A0);
  s[1] = analogRead(A1);
  s[2] = analogRead(A2);
  s[3] = analogRead(A3);
  s[4] = analogRead(A4);
  s[5] = analogRead(A5);

  for (i = 0; i < 6; i++)
  {
    Serial.print(s[i]);
    Serial.print("\t");
    
  }
Serial.println(" ");
delay(100);
}
