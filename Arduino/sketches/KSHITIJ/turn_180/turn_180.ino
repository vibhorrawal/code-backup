#define SPEED 150
#define SLOWSPEED 100
#define VSLOWSPEED 80
int s[6] = {A0, A1, A2, A3, A4, A5};
int avg[6];
int val[6];
int white[6];
int black[6];
int i, j;
int ir[6];
int lfmotor = 3;
int rfmotor = 6;
int lbmotor = 5;
int rbmotor = 9;
int trigPin = 13;
int echoPin = 12;

long duration;
int gripperDown = 11;
int gripperUp = 10;
int red, green, blue;
int r[4], g[4], b[4];
int redLed = 10;
int blueLed = 13;
int greenLed = 12;
int input = A6;
void setup() {
  Serial.begin(9600);
  pinMode( lfmotor, OUTPUT );
  pinMode( rfmotor, OUTPUT );
  pinMode( lbmotor, OUTPUT );
  pinMode( rbmotor, OUTPUT );
  analogWrite(lbmotor, 0);
  analogWrite(rbmotor, 0);
  analogWrite(lfmotor, 0);
  analogWrite(rfmotor, 0);

  Serial.println("Place on White");
  delay(2000);

  for (i = 0; i < 6; i++)
  {
    white[i] = analogRead(s[i]);
    Serial.print(white[i]);
    Serial.print("\t");
  } Serial.println(" ");
  delay(1000);

  Serial.println("Place on Black");
  delay(2000);

  for (i = 0; i < 6; i++)
  {
    black[i] = analogRead(s[i]);
    Serial.print(black[i]);
    Serial.print("\t");
  } Serial.println("");
  Serial.println(" Average:");
  delay(1000);
  for (i = 0; i < 6; i++)
  {
    avg[i] = (black[i] + white[i]) / 2;
    Serial.print(avg[i]);
    Serial.print("\t");
  } Serial.println(" ");
  delay(1000);

  pinMode(gripperDown, OUTPUT);
  pinMode(gripperUp, OUTPUT);
  digitalWrite(gripperDown, LOW);
  //digitalWrite(gripperUp, HIGH);
  delay(2000);
  //digitalWrite(gripperUp, LOW);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(input, INPUT);
}
void Stop()
{
  analogWrite(lfmotor, 0);
  analogWrite(lbmotor, 0);
  analogWrite(rfmotor, 0);
  analogWrite(rbmotor, 0);
  Serial.println("Stop");
}
void fullturn()
{
    while (!(analogRead(s[2]) < avg[2]))
  {
    analogWrite(lfmotor, 0);
    analogWrite(lbmotor, SLOWSPEED);
    analogWrite(rfmotor, SLOWSPEED);
    analogWrite(rbmotor, 0);
    Serial.println("full turn");
  }
  while (!(analogRead(s[2]) > avg[2]))
  {
    analogWrite(lfmotor, 0);
    analogWrite(lbmotor, SLOWSPEED);
    analogWrite(rfmotor, SLOWSPEED);
    analogWrite(rbmotor, 0);
    Serial.println("full turn");
    Stop();
  }
}
void loop() {
  // put your main code here, to run repeatedly:
fullturn();
Stop();
delay(5000);
}
