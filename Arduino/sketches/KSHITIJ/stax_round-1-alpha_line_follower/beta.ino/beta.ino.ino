#define SPEED 150
#define SLOWSPEED 100
#define WHEELSOFF 100 //delay for changing line
#define WHEELSOFFWIDTH 500 //delay for crossing width of line
#define MINDISTANCE 5 //ultrasonic reading for color detection
#define GRIPPINGDISTANCE 0
#define EXTRADELAYFORGRIPPERDOWN 0
#define MOVEFWDFORGRIPPING 0
#define GRIPPERWITHLOAD 0 //delay for moving gripper
//extra time for gripper down
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
int trigPin = 11;
int echoPin = 10;
//rgb-10 11 12
long duration;
int gripperDown = 6;
int gripperUp = 7;
int red, green, blue;
int r[4], g[4], b[4];
int redLed = 4;
int blueLed = 2;
int greenLed = 7;
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
  while (analogRead(s[2]) < avg[2])
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
  while (analogRead(s[2]) < avg[2])
  {
    analogWrite(lfmotor, SPEED);
    analogWrite(lbmotor, 0);
    analogWrite(rfmotor, 0);
    analogWrite(rbmotor, 0);
    Serial.println("right turn");
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

void reverseLeft()
{
  analogWrite(lfmotor, 0);
  analogWrite(lbmotor, 0);
  analogWrite(rfmotor, 0);
  analogWrite(rbmotor, SPEED);
  Serial.println("reverse left");
}

void reverseRight()
{
  analogWrite(lfmotor, 0);
  analogWrite(lbmotor, SPEED);
  analogWrite(rfmotor, 0);
  analogWrite(rbmotor, 0);
  Serial.println("reverse right");
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
  //while (analogRead(A2) < avg[2])
  {
    analogWrite(lfmotor, 0);
    analogWrite(lbmotor, 0);
    analogWrite(rfmotor, SPEED);
    analogWrite(rbmotor, 0);
    Serial.println("rotate");
  }
}

void followLine()
{ int value1 = value();
  if (value1 > 1000)
    value1 -= 1000;
  switch (value1) {

    case 14:
    case 4:
      forward();
      break;

    case 12:
    case 8:
    case 24:
    case 28:
    case 30:
      left();
      break;

    case 16:
      leftTurn();
      break;

    case 1:
      rightTurn();
      break;

    case 6:
    case 2:
    case 3:
    case 7:
    case 15:
      right();
      break;
    //
    //    case 1014:
    //    case 1004:
    //      forward();
    //      break;
    //
    //    case 1012:
    //    case 1008:
    //    case 1024:
    //    case 1028:
    //    case 1030:
    //      left();
    //      break;
    //
    //    case 1016:
    //      leftTurn();
    //      break;
    //
    //    case 1001:
    //      rightTurn();
    //      break;
    //
    //    case 1006:
    //    case 1002:
    //    case 1003:
    //    case 1007:
    //    case 1015:
    //      right();
    //      break;

    default:
      rotate();
  }
}

void reverseLine()
{
  switch (value()) {

    case 14:
    case 4:
      backward();
      break;

    case 12:
    case 8:
    case 24:
    case 28:
    case 30:
    case 16:
      reverseLeft();
      break;

    case 1:
    case 2:
    case 3:
    case 6:
    case 7:
    case 15:
      reverseRight();
      break;

    case 1014:
    case 1004:
      backward();
      break;

    case 1012:
    case 1008:
    case 1024:
    case 1028:
    case 1030:
    case 1016:
      reverseLeft();
      break;

    case 1001:
    case 1006:
    case 1002:
    case 1003:
    case 1007:
    case 1015:
      reverseRight();
      break;

    default:
      rotate();
  }
}

int distance()
{
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

int variable3 = 0;
void colorSave() {
  int t = 0;
  if (variable3 == 0)
  {
    r[0] = red;
    g[0] = green;
    b[0] = blue;
    variable3++;
    Serial.println("Color Saved");
  }
  else
  {
    for (i = variable3; i >= 0; i--)
    {
      if ((red > 0.9 * r[variable3] && red < 1.1 * r[variable3]) && (green > 0.9 * g[variable3] && green < 1.1 * g[variable3]) && (blue > 0.9 * b[variable3] && blue < 1.1 * b[variable3]))
        t = 1;
    }
    if (t = 0)
    {
      r[variable3] = red;
      g[variable3] = green;
      b[variable3] = blue;
      variable3++;
      Serial.println("Color Saved");
    }
  }
}

void colorSense() {
  int r[11], g[11], b[11];
  for (i = 0; i < 10; i++) {

    //blink same color led and some color led in black too
    digitalWrite(redLed, HIGH);
    delay(50);
    //Serial.print("r=");
    r[i] = analogRead(input);
    //Serial.print(red);
    //Serial.print("  ");
    digitalWrite(redLed, LOW);
    delay(50);
    digitalWrite(greenLed, HIGH);
    delay(50);
    //Serial.print("g=");
    g[i] = analogRead(input);
    //Serial.print(green);
    //Serial.print("  ");
    digitalWrite(greenLed, LOW);
    delay(50);

    digitalWrite(blueLed, HIGH);
    delay(50);
    //Serial.print("b=");
    b[i] = analogRead(input);
    //Serial.print(blue);

    //Serial.print("  ");
    digitalWrite(blueLed, LOW);
    delay(50);
    //Serial.println(" ");
  }
  r[10] = 0;
  g[10] = 0;
  b[10] = 0;
  for (i = 0; i < 9; i++) {
    r[10] += r[i];
    g[10] += g[i];
    b[10] += b[i];
  }

  red = r[10] / 10;
  green = g[10] / 10;
  blue = b[10] / 10;
}

int colormatch(int r, int g, int b)
{
  if ((red > 0.9 * r && red < 1.1 * r) && (green > 0.9 * g && green < 1.1 * g) && (blue > 0.9 * b && blue < 1.1 * b))
    return 1;
  else return 0;
}

int variable = 0;
void Task1() {
  while (variable < 3) {
    do {
      followLine();
    } while (distance() > MINDISTANCE);

    colorSense();
    colorSave();

    do {
      reverseLine();
    } while (analogRead(s[0]) < avg[0] || analogRead(s[4]), avg[4]);

    if (analogRead(s[0]) > avg[0])
    {
      leftTurn();
      variable++;
    }
    else if (analogRead(s[4]) > avg[4])
    {
      rightTurn();
      variable++;
    }

  }
  do {
    followLine();
  } while (value() != 1031 );
}

int variable2 = 0;
void Task2() {

  //block 1
  pickup(2);
  for (i = 0; i < 2; i++)
  {
    if (colormatch(r[0], g[0], b[0]))
      dropin(2, 1);
    else dropin(2, 3);
  }
  if (colormatch(r[0], g[0], b[0]))
    while (value() != 1031)
      reverseLine();
  //  back2node();
  else {
    dropin(2, 3);
    pickup(1);
    dropin(1, 2);
  }

  //block 2
  pickup(3);

  if (colormatch(r[1], g[1], b[1]))
  {
    dropin(3, 2);
    pickup(3); //block 3
    dropin(3, 2);
    //  back2node();
  }
  else
  {
    dropin(3, 1);
    pickup(3);
    dropin(3, 2);
    pickup(1);  //block 3
    dropin(1, 2);
    //   back2node();
  }
}

void pickup(int stack) {
  if (stack == 1)
    leftTurn();

  else if (stack == 2)
    forward();

  else if (stack == 3)
    rightTurn();

  do {
    followLine();
  } while (distance() > MINDISTANCE);
  colorSense();
}

void dropin(int currentStack, int nextStack) {
  grip();

  if (currentStack == 1)
  {

    while (value() != 1031 && distance() > 15)
      reverseLine();


    reverseLeft();
    delay(WHEELSOFF);
    while (analogRead(s[5]) < avg[5])
      reverseLeft();

    if (nextStack == 2)
    {
      forward();
      delay(WHEELSOFFWIDTH);
    }
    else if (nextStack == 3)
    {
      reverseLeft();
      delay(WHEELSOFF);
      while (analogRead(s[5]) < avg[5])
        reverseLeft();

      forward();
      delay(WHEELSOFFWIDTH);
    }
  }

  else if (currentStack == 2)
  {
    while (value() != 1031 && distance() > 15)
      reverseLine();

    if (nextStack == 1)
    {
      reverseRight();
      delay(WHEELSOFF);
      while (analogRead(s[5]) < avg[5])
        reverseRight();

      forward();
      delay(WHEELSOFFWIDTH);
    }
    else if (nextStack == 3)
    {
      reverseLeft();
      delay(WHEELSOFF);
      while (analogRead(s[5]) < avg[5])
        reverseLeft();

      forward();
      delay(WHEELSOFFWIDTH);
    }

  }
  else   if (currentStack == 3)
  {

    while (value() != 1031 && distance() > 15)
      reverseLine();


    reverseRight();
    delay(WHEELSOFF);
    while (analogRead(s[5]) < avg[5])
      reverseRight();

    if (nextStack == 2)
    {
      forward();
      delay(WHEELSOFFWIDTH);
    }
    else if (nextStack == 1)
    {
      reverseRight();
      delay(WHEELSOFF);
      while (analogRead(s[5]) < avg[5])
        reverseRight();

      forward();
      delay(WHEELSOFFWIDTH);
    }
  }
  while (distance() > 7)
    followLine();
  ungrip();
  while (value() != 1031 && distance() > 15)
    reverseLine();

  if (nextStack == 1)
  {
    reverseLeft();
    delay(WHEELSOFF);
    while (analogRead(s[5]) < avg[5])
      reverseLeft();
  }

  else if (nextStack == 3)
  {
    reverseRight();
    delay(WHEELSOFF);
    while (analogRead(s[5]) < avg[5])
      reverseRight();
  }
}

void grip() {
  while ( distance() < GRIPPINGDISTANCE )
  {
    reverseLine();
    digitalWrite(gripperDown, HIGH);
    digitalWrite(gripperUp, LOW);
  }
  delay(EXTRADELAYFORGRIPPERDOWN);
  digitalWrite(gripperDown, LOW);
  followLine();
  delay(MOVEFWDFORGRIPPING);
  Stop();
  digitalWrite(gripperDown, LOW);
  digitalWrite(gripperUp, HIGH);
  delay(GRIPPERWITHLOAD);
  digitalWrite(gripperUp, LOW);
}

void ungrip() {
  //while (value != 1031 || distance()>7)
  //followLine();
  Stop();
  digitalWrite(gripperDown, HIGH);
  digitalWrite(gripperUp, LOW);
  delay(GRIPPERWITHLOAD);
  digitalWrite(gripperDown, LOW);
  while (distance() < GRIPPINGDISTANCE)
    reverseLine();
  digitalWrite(gripperUp, HIGH);
  delay(GRIPPERWITHLOAD);
  digitalWrite(gripperUp, LOW);

}

void loop() {

  //  Task1();
  //  Task2();
  followLine();
}
