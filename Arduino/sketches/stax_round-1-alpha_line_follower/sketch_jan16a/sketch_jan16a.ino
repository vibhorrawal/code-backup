#define SPEED 150
#define SLOWSPEED 130
#define VSLOWSPEED 150
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
int trigPin = 7;
int echoPin = 8;

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
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
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

int value()
{
  for (i = 0; i < 6; i++)
  {
    ir[i] = ( analogRead(s[i]) > avg[i] ? 1 : 0 );
    Serial.print(ir[i]);
    Serial.print("\t");
  }
  Serial.println("");
  return 16 * ir[0] + 8 * ir[1] + 4 * ir[2] + 2 * ir[3] + 1 * ir[4] + 1000 * ir[5];
}


void leftTurn()
{
//  while (!(analogRead(s[2]) < avg[2]))
//  {
//    analogWrite(lfmotor, 0);
//    analogWrite(lbmotor, 0);
//    analogWrite(rfmotor, SPEED);
//    analogWrite(rbmotor, 0);
//    Serial.println("left turn");
//  }
//  while (!(analogRead(s[2]) > avg[2]))
//  {
//    analogWrite(lfmotor, 0);
//    analogWrite(lbmotor, 0);
//    analogWrite(rfmotor, SPEED);
//    analogWrite(rbmotor, 0);
//    Serial.println("left turn");
//  }
while(analogRead(s[0]) < avg[0])
{
     analogWrite(lfmotor, 0);
    analogWrite(lbmotor, 0);
    analogWrite(rfmotor, SPEED);
    analogWrite(rbmotor, 0);
    Serial.println("left turn");
  }
}

void rightTurn()
{
//  while (!(analogRead(s[2]) < avg[2]))
//  {
//    analogWrite(lfmotor, SPEED);
//    analogWrite(lbmotor, 0);
//    analogWrite(rfmotor, 0);
//    analogWrite(rbmotor, 0);
//    Serial.println("right turn");
//  }
//  while (!(analogRead(s[2]) > avg[2]))
//  {
//    analogWrite(lfmotor, SPEED);
//    analogWrite(lbmotor, 0);
//    analogWrite(rfmotor, 0);
//    analogWrite(rbmotor, 0);
//    Serial.println("right turn");
//  }
while ((analogRead(s[4]) < avg[4]))
  {
    analogWrite(lfmotor, SPEED);
    analogWrite(lbmotor, 0);
    analogWrite(rfmotor, 0);
    analogWrite(rbmotor, 0);
    Serial.println("right turn");
  }
}
void leftTurnWithBreak()
{
  while (!(analogRead(s[2]) < avg[2]))
  {
    analogWrite(lfmotor, 0);
    analogWrite(lbmotor, 0);
    analogWrite(rfmotor, SPEED);
    analogWrite(rbmotor, 0);
    Serial.println("left turn");
    if(value()==1031)
    break;
  }
  while (!(analogRead(s[2]) > avg[2]))
  {
    analogWrite(lfmotor, 0);
    analogWrite(lbmotor, 0);
    analogWrite(rfmotor, SPEED);
    analogWrite(rbmotor, 0);
    Serial.println("left turn");
    if(value()==1031)
    break;
  }
}

void rightTurnWithBreak()
{
  while (!(analogRead(s[2]) < avg[2]))
  {
    analogWrite(lfmotor, SPEED);
    analogWrite(lbmotor, 0);
    analogWrite(rfmotor, 0);
    analogWrite(rbmotor, 0);
    Serial.println("right turn");
    if(value()==1031)
    break;
  }
  while (!(analogRead(s[2]) > avg[2]))
  {
    analogWrite(lfmotor, SPEED);
    analogWrite(lbmotor, 0);
    analogWrite(rfmotor, 0);
    analogWrite(rbmotor, 0);
    Serial.println("right turn");
    if(value()==1031)
    break;
  }
}

void left()
{
  analogWrite(lfmotor, SLOWSPEED);
  analogWrite(lbmotor, 0);
  analogWrite(rfmotor, SPEED);
  analogWrite(rbmotor, 0);
  Serial.println("left");
}

void right()
{
  analogWrite(lfmotor, SPEED);
  analogWrite(lbmotor, 0);
  analogWrite(rfmotor, SLOWSPEED);
  analogWrite(rbmotor, 0);
  Serial.println("right");
}

void forward()
{
  analogWrite(lfmotor, SPEED);
  analogWrite(lbmotor, 0);
  analogWrite(rfmotor, SPEED);
  analogWrite(rbmotor, 0);
  Serial.println("fwd");
}
void Stop()
{
  analogWrite(lfmotor, 0);
  analogWrite(lbmotor, 0);
  analogWrite(rfmotor, 0);
  analogWrite(rbmotor, 0);
  Serial.println("Stop");
}


void backward()
{
  analogWrite(lfmotor, 0);
  analogWrite(lbmotor, SPEED);
  analogWrite(rfmotor, 0);
  analogWrite(rbmotor, SPEED);
  Serial.println("bwd");
}

void rotate()
{
  {
    analogWrite(lfmotor, SPEED);
    analogWrite(lbmotor, 0);
    analogWrite(rfmotor, 0);
    analogWrite(rbmotor, 0);
    Serial.println("rotate");
  }
}

void fullturn()
{
    while (!(analogRead(s[2]) < avg[2]))
  {
    analogWrite(lfmotor, 0);
    analogWrite(lbmotor, VSLOWSPEED);
    analogWrite(rfmotor, VSLOWSPEED);
    analogWrite(rbmotor, 0);
    Serial.println("full turn");
  }
  while (!(analogRead(s[2]) > avg[2]))
  {
    analogWrite(lfmotor, 0);
    analogWrite(lbmotor, VSLOWSPEED);
    analogWrite(rfmotor, VSLOWSPEED);
    analogWrite(rbmotor, 0);
    Serial.println("full turn");
    Stop();
  }
}
void followLine()
{ int value1 = value();
  if (value1 > 1000)
    value1 -= 1000;
  switch (value1) {

    case 14:
    case 4:
    case 17:
    case 10:
    case 5:
    case 31:
      forward();
      break;

    case 12:
    case 8:
    case 24:
    case 28:
case 25:
case 26:
      left();
      break;

    case 16:
    case 30:
      leftTurn();
      break;

    case 1:
    case 15:
      rightTurn();
      break;

    case 6:
    case 2:
    case 3:
    case 7:
    case 11:
    case 19:
      right();
      break;

    default:
      rotate();
  }
}

int distance(){
  
   // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  return duration * 0.034 / 2;
}
void grip() {
while(distance()>5)
followLine();

Stop();
while(distance()<9)
backward();
Stop();
digitalWrite(gripperDown,HIGH);
digitalWrite(gripperUp,LOW);
delay(3000);
digitalWrite(gripperDown,LOW);
while(distance()>5)
followLine();
Stop();
digitalWrite(gripperUp,HIGH);
digitalWrite(gripperDown,LOW);
delay(3000);
digitalWrite(gripperUp,LOW);
}

void loop() {

  grip();
  backward();
  delay(1000);
  Stop();
  delay(5000);
}

