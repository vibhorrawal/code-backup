int s0 = 5;
int s1 = 3;
int s2 = 9;
int s3 = 10;
int out = 11;//6;
int r, g, b;



void setup() {
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  pinMode(6, OUTPUT);
digitalWrite(6,LOW);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  r = pulseIn(out, LOW);
  Serial.print("\tR= ");
  Serial.print(r);
  Serial.print("\t");
  delay(100);

  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  g = pulseIn(out, LOW);
  Serial.print("\tG= ");
  Serial.print(g);
  Serial.print("\t");
  delay(100);

  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  b = pulseIn(out, LOW);
  Serial.print("\tB= ");
  Serial.print(b);
  Serial.println("\t");
  delay(100);

}
