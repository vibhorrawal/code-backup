int gripPin = ;
int ungripPin = ;
//int timeWithload = ;
//int timeWithoutLoad = ;
void setup() {
  Serial.begin(9600);
  pinMode(gripPin, OUTPUT);
  pinMode(ungripPin, OUTPUT);
  digitalWrite(gripPin, LOW);
  digitalWrite(ungripPin, LOW);
  
}

void loop() {
  digitalWrite(gripPin, HIGH);
  delay(300);
  digitalWrite(gripPin, LOW);

}
