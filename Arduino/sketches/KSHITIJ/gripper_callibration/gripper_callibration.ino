int gripPin = 10;
int ungripPin = 11 ;
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

    digitalWrite(ungripPin, HIGH);
  delay(8000);
 digitalWrite(ungripPin, LOW);
  delay(2000);
}
