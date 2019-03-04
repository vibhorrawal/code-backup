#define SPEED 200
#define HIGHSPEED 230
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
int leftStack = 0, rightStack = 0, centreStack = 6;
long duration;
int gripperDown = 11;
int gripperUp = 10;
int red, green, blue;
int r[4], g[4], b[4];
int redLed = 10;
//int blueLed = 13;
int greenLed = 12;
//int s0 = 11; --- 5 volts
//int s1 = 10; --- ground
int s2 = 13;
int s3 = 2;
int out = 4;
//int oe= 9; ---- ground

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

  analogWrite(lbmotor, 0);
  analogWrite(rbmotor, 0);
  analogWrite(lfmotor, SLOWSPEED);
  analogWrite(rfmotor, SLOWSPEED);
  delay(2000);
  analogWrite(lbmotor, 0);
  analogWrite(rbmotor, 0);
  analogWrite(lfmotor, 0);
  analogWrite(rfmotor, 0);
  for (i = 0; i < 6; i++)
  {
    white[i] = analogRead(s[i]);
    Serial.print(white[i]);
    Serial.print("\t");
  } Serial.println(" ");
  delay(1000);

  Serial.println("Place on Black");

  analogWrite(lbmotor, SLOWSPEED);
  analogWrite(rbmotor, SLOWSPEED);
  analogWrite(lfmotor, 0);
  analogWrite(rfmotor, 0);
  delay(2000);
  analogWrite(lbmotor, 0);
  analogWrite(rbmotor, 0);
  analogWrite(lfmotor, 0);
  analogWrite(rfmotor, 0);

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
  digitalWrite(gripperUp, LOW);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  //  pinMode(blueLed, OUTPUT);

  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);

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
  while (!(analogRead(s[2]) < avg[2]))
  {
    analogWrite(lfmotor, 0);
    analogWrite(lbmotor, 0);
    analogWrite(rfmotor, SPEED);
    analogWrite(rbmotor, 0);
    Serial.println("left turn");
  }
  while (!(analogRead(s[2]) > avg[2]))
  {
    analogWrite(lfmotor, 0);
    analogWrite(lbmotor, 0);
    analogWrite(rfmotor, SPEED);
    analogWrite(rbmotor, 0);
    Serial.println("left turn");
  }
  //while(analogRead(s[0]) < avg[0])
  //{
  //     analogWrite(lfmotor, 0);
  //    analogWrite(lbmotor, SPEED);
  //    analogWrite(rfmotor, HIGHSPEED);
  //    analogWrite(rbmotor, 0);
  //    Serial.println("left turn");
  //}
}

void rightTurn()
{
  while (!(analogRead(s[2]) < avg[2]))
  {
    analogWrite(lfmotor, SPEED);
    analogWrite(lbmotor, 0);
    analogWrite(rfmotor, 0);
    analogWrite(rbmotor, 0);
    Serial.println("right turn");
  }
  while (!(analogRead(s[2]) > avg[2]))
  {
    analogWrite(lfmotor, SPEED);
    analogWrite(lbmotor, 0);
    analogWrite(rfmotor, 0);
    analogWrite(rbmotor, 0);
    Serial.println("right turn");
  }
  //while ((analogRead(s[4]) < avg[4]))
  //  {
  //    analogWrite(lfmotor, HIGHSPEED);
  //    analogWrite(lbmotor, 0);
  //    analogWrite(rfmotor, 0);
  //    analogWrite(rbmotor, SPEED);
  //    Serial.println("right turn");
  //  }
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
    if (value() == 1031)
      break;
  }
  while (!(analogRead(s[2]) > avg[2]))
  {
    analogWrite(lfmotor, 0);
    analogWrite(lbmotor, 0);
    analogWrite(rfmotor, SPEED);
    analogWrite(rbmotor, 0);
    Serial.println("left turn");
    if (value() == 1031)
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
    if (value() == 1031)
      break;
  }
  while (!(analogRead(s[2]) > avg[2]))
  {
    analogWrite(lfmotor, SPEED);
    analogWrite(lbmotor, 0);
    analogWrite(rfmotor, 0);
    analogWrite(rbmotor, 0);
    Serial.println("right turn");
    if (value() == 1031)
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

void fullTurn()
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
{
  int value1 = value();

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
      leftTurnWithBreak();
      break;

    case 1:
    case 15:
      rightTurnWithBreak();
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

int distance() {

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
  while (distance() > 5)
    followLine();
  colorSense();
  Stop();
  blinkLed();
  while (distance() < 9)
    backward();
  Stop();
  digitalWrite(gripperDown, HIGH);
  digitalWrite(gripperUp, LOW);
  delay(3000);
  digitalWrite(gripperDown, LOW);
  while (distance() > 5)
    followLine();
  Stop();
  digitalWrite(gripperUp, HIGH);
  digitalWrite(gripperDown, LOW);
  delay(3000);
  digitalWrite(gripperUp, LOW);
}

void unGrip() {
  while (distance() > 10)
    followLine();
  Stop();
  digitalWrite(gripperDown, HIGH);
  digitalWrite(gripperUp, LOW);
  delay(3000);
  digitalWrite(gripperDown, LOW);
  while (distance() < 9)
    backward();
  Stop();
  digitalWrite(gripperUp, HIGH);
  digitalWrite(gripperDown, LOW);
  delay(3000);
  digitalWrite(gripperUp, LOW);
}

void Task1() {
  while (value() == 1031 || value() == 1000 || value() == 31) //to compensate starting line
    forward();


  for (i = 0; i < 4; i++) {
    while (distance() > 5)
      followLine();
    colorSave();
    while (value() != 1007 || value() != 1028)
    {
      backward();
    }
    if (value() == 1007)
      rightTurn();
    else
      leftTurn();
    while (value() != 1031)
      followLine();
  }
}

void Task2() {
  forward();
  delay(400);
  grip();
  for (i = 0; i < 5; i++) {
    if (colorMatch(r[0], g[0], b[0])) {
      dropIn(2, 1);
      returnToCentre(1);
      grip();
    }
    else {
      dropIn(2, 3);
      returnToCentre(3);
      grip();
    }

  }
  if (colorMatch(r[0], g[0], b[0])) {
    unGrip();
  }
  else {
    dropIn(2, 3);
    pickUp(3, 1);
    dropIn(1, 2);
  }
  while (distance() > 10)
    backward();
  fullTurn();
  while (value() != 1031)
    followLine();
  leftTurn();
  grip();
  for (i = 0; i < 4; i++) {
    if (colorMatch(r[1], g[1], b[1])) {
      dropIn(3, 2);
      pickUp(2, 3);
    }
    else {
      dropIn(3, 1);
      pickUp(1, 3);
    }
  }
  if (colorMatch(r[1], g[1], b[1])) {
    dropIn(3, 2);
    pickUp(2, 1);
  }
  else {
    dropIn(3, 1);
    grip();
  }
  for (i = 0; i < 3; i++) {
    if (colorMatch(r[2], g[2], b[2])) {
      dropIn(1, 2);
      pickUp(2, 1);
    }
    else
    {
      dropIn(1, 3);
      pickUp(3, 1);
    }
  }
  if (colorMatch(r[2], g[2], b[2])) {
    dropIn(1, 2);
    pickUp(2, 3);
  }
  else
  {
    dropIn(1, 3);
    grip();
  }
  for (i = 0; i < 2; i++) {
    if (colorMatch(r[3], g[3], b[3])) {
      dropIn(3, 2);
      pickUp(2, 3);
    }
    else {
      dropIn(3, 1);
      pickUp(1, 3);
    }
  }
  if (colorMatch(r[3], g[3], b[3])) {
    dropIn(3, 2);
    while(distance()>10)
    backward();
    fullTurn();
    while(value()!=1031)
    followLine();
    Stop();
  }
  else {
    unGrip();
    while(distance()>10)
    backward();
    fullTurn();
    while(value()!=1031)
    followLine();
  }

}

void returnToCentre(int n) {
  if (n == 1)
  {
    while (distance() > 10)
      backward();
    fullTurn();
    while (value() != 1031)
      followLine();
    leftTurn();
    while (distance() > 20)
      followLine();
    Stop();
  }
  if (n == 3)
  {
    while (distance() > 10)
      backward();
    fullTurn();
    while (value() != 1031)
      followLine();
    rightTurn();
    while (distance() > 20)
      followLine();
    Stop();
  }
}

void returnToNode() {
  while (distance() < (7 - centreStack) * 10)
    backward();
  fullTurn();
  while (value != 1031)
    followLine();
  Stop();
}

void colorSense() {

  int r, g, b;
  int rsum = 0, gsum = 0, bsum = 0;

  for (i = 0; i < 5; i++) {
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
    r = pulseIn(out, LOW);
    //r = map(r, 250, 1000, 255, 0);
    // r = constrain(r,0,255);
    Serial.print("\tR= ");
    Serial.print(r);
    Serial.print("\t");
    delay(100);

    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);
    g = pulseIn(out, LOW);
    //g = map(g, 250, 1000, 255, 0);
    // g = constrain(g,0,255);
    Serial.print("\tG= ");
    Serial.print(g);
    Serial.print("\t");
    delay(100);

    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
    b = pulseIn(out, LOW);
    // b = map(b, 250, 1000, 255, 0);
    // b = constrain(b,0,255);
    Serial.print("\tB= ");
    Serial.print(b);
    Serial.println("\t");
    delay(100);
    rsum += r;
    gsum += g;
    bsum += b;
  }
  red = rsum / 5;
  green = gsum / 5;
  blue = bsum / 5;
}

int colorSaveVariable = 0;
void colorSave() {
  int t = 0;
  colorSense();
  for (i = 0; i <= colorSaveVariable; i++)
  {
    if (red > 0.9 * r[i] && red < 1.1 * r[i] && green > 0.9 * g[i] && green < 1.1 * g[i] && blue > 0.9 * b[i] && blue < 1.1 * b[i])
      t = 1;
  }
  if (t == 0)
  {
    r[colorSaveVariable] = red;
    g[colorSaveVariable] = green;
    b[colorSaveVariable] = blue;
    colorSaveVariable++;
    Serial.println("Color is saved");
  }

}

int colorMatch(int r, int g, int b) {
  if (red > 0.9 * r && red < 1.1 * r && green > 0.9 * g && green < 1.1 * g && blue > 0.9 * b && blue < 1.1 * b)
  {
    return 1;
  }
  else return 0;
}

void pickUp(int currentStack, int nextStack)
{
  if (currentStack == 1)
  {
    while (distance() < (6 - leftStack) * 10)
      backward();
    fullTurn();

    while (value() != 1031)
      followLine();

    if (nextStack == 2)
    {
      leftTurn();
      centreStack--;
    }

    else if (nextStack == 3)
    {
      forward();
      delay(400);
      rightStack--;
    }
    grip();


  }

  else if ( currentStack == 2)
  {
    while (distance() < (8 - centreStack) * 10)
      backward();
    fullTurn();

    while (value() != 1031)
      followLine();

    if (nextStack == 1)
    {
      rightTurn();
      leftStack--;
    }

    else if (nextStack == 3)
    {
      leftTurn();
      rightStack--;
    }

    grip();
  }

  else if ( currentStack == 3)
  {
    while (distance() < (6 - rightStack) * 10)
      backward();
    fullTurn();

    while (value() != 1031)
      followLine();

    if (nextStack == 2)
    {
      rightTurn();
      centreStack--;
    }

    else if (nextStack == 1)
    {
      forward();
      delay(400);
      leftStack--;
    }
    grip();
  }
}

void dropIn(int currentStack, int nextStack) {
  if (currentStack == 1)
  {
    if (nextStack == 2)
    {
      while (distance() < (6 - leftStack) * 10)
        backward();
      fullTurn();
      while (value() != 1031)
        followLine();
      leftTurn();
      unGrip();
      centreStack++;
    }
    if (nextStack == 3)
    {
      while (distance() < (6 - rightStack) * 10)
        backward();
      fullTurn();
      while (value() != 1031)
        followLine();
      forward();
      delay(400);
      rightStack++;
    }
  }
  if (currentStack == 2)
  { if (nextStack == 1)
    {
      while (distance() < (6 - leftStack) * 10)
        backward();
      fullTurn();
      while (value() != 1031)
        followLine();
      rightTurn();
      unGrip();
      leftStack++;
    }
    if (nextStack == 3)
    {
      while (distance() < (6 - leftStack) * 10)
        backward();
      fullTurn();
      while (value() != 1031)
        followLine();
      leftTurn();
      unGrip();
      rightStack++;
    }
  }
  if (currentStack == 3)
  {
    if (nextStack == 1)
    {
      while (distance() < (6 - leftStack) * 10)
        backward();
      fullTurn();
      while (value() != 1031)
        followLine();
      forward();
      delay(400);
      unGrip();
      leftStack++;
    }
    if (nextStack == 2)
    {
      while (distance() < (6 - leftStack) * 10)
        backward();
      fullTurn();
      while (value() != 1031)
        followLine();
      rightTurn();
      unGrip();
      centreStack++;
    }


  }
}

void blinkLed() {
  if (red > 0.9 * r[0] && red < 1.1 * r[0] && green > 0.9 * g[0] && green < 1.1 * g[0] && blue > 0.9 * b[0] && blue < 1.1 * b[0])
  {
    analogWrite(redLed, 255);
    delay(500);
    analogWrite(redLed, 0);
  }
  else if (red > 0.9 * r[1] && red < 1.1 * r[1] && green > 0.9 * g[1] && green < 1.1 * g[1] && blue > 0.9 * b[1] && blue < 1.1 * b[1])
  {
    analogWrite(greenLed, 255);
    delay(500);
    analogWrite(greenLed, 0);
  }
  else if (red > 0.9 * r[2] && red < 1.1 * r[2] && green > 0.9 * g[2] && green < 1.1 * g[2] && blue > 0.9 * b[2] && blue < 1.1 * b[2])
  {
    analogWrite(redLed, 255);
    analogWrite(greenLed, 125);
    delay(500);
    analogWrite(greenLed, 0);
    analogWrite(redLed, 0);
  }
  else if (red > 0.9 * r[3] && red < 1.1 * r[3] && green > 0.9 * g[3] && green < 1.1 * g[3] && blue > 0.9 * b[3] && blue < 1.1 * b[3])
  {
    analogWrite(redLed, 255);
    analogWrite(greenLed, 255);
    delay(500);
    analogWrite(greenLed, 0);
    analogWrite(redLed, 0);
  }
}
void loop() {
  Task1();
  Task2();
}

