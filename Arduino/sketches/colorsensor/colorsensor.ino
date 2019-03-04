int s0 = 13;
int s1 = 5;
int s2 = 7;
int s3 = 8;
int out = 10;
int r, g, b;



void setup() {
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  pinMode(2, OUTPUT);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);

digitalWrite(2,HIGH);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  r = pulseIn(out, LOW);
  r = map(r, 250, 1000, 255, 0);
  // r = constrain(r,0,255);
  Serial.print("\tR= ");
  Serial.print(r);
  Serial.print("\t");
  delay(100);

  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  g = pulseIn(out, LOW);
  g = map(g, 250, 1000, 255, 0);
  // g = constrain(g,0,255);
  Serial.print("\tG= ");
  Serial.print(g);
  Serial.print("\t");
  delay(100);

  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  b = pulseIn(out, LOW);
  b = map(b, 250, 1000, 255, 0);
  // b = constrain(b,0,255);
  Serial.print("\tB= ");
  Serial.print(b);
  Serial.println("\t");
  delay(100);

}
