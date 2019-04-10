#define SPEED 200
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
int lfmotor = 5;
int rfmotor = 8;
int lbmotor = 6;
int rbmotor = 7;
int trigPin = 11;
int echoPin = 9;
//rgb-10 11 12
long duration;
int gripperDown = 3;
int gripperUp = 2;
int red, green, blue;
int r[4], g[4], b[4];
int redLed = 10;
int blueLed = 11;
int greenLed = 12;
int input = A6;
void setup() {
  Serial.begin(9600);
  pinMode( lfmotor, OUTPUT );
  pinMode( rfmotor, OUTPUT );
  pinMode( lbmotor, OUTPUT );
  pinMode( rbmotor, OUTPUT );
  digitalWrite(lbmotor, LOW);
  digitalWrite(rbmotor, LOW);
  digitalWrite(lfmotor, LOW);
  digitalWrite(rfmotor, LOW);
  Serial.println("Place on White");
  delay(1000);

  for (i = 0; i < 6; i++)
  {
    s[i] = analogRead(s[i]);
    white[i] = s[i];
    Serial.print(white[i]);
    Serial.print("\t");
  } Serial.println(" ");
  delay(1000);

  Serial.println("Place on Black");
  delay(2000);

  for (i = 0; i < 6; i++)
  {
    s[i] = analogRead(s[i]);
    black[i] = s[i];
    Serial.print(black[i]);
    Serial.print("\t");
  } Serial.println(" ");

  for (i = 0; i < 6; i++)
  {
    avg[i] = (black[i] + white[i]) / 2;
  }
  pinMode(gripperDown, OUTPUT);
  pinMode(gripperUp, OUTPUT);
  digitalWrite(gripperDown, LOW);
  //digitalWrite(gripperUp, HIGH);
  delay(2000);
  //digitalWrite(gripperUp, LOW);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redLed,OUTPUT);
pinMode(greenLed,OUTPUT);
pinMode(blueLed,OUTPUT);
pinMode(input,INPUT);
}

int value()
{
  for (i = 0; i < 6; i++)
  {
    s[i] = analogRead(s[i]);
    ir[i] = s[i] > avg[i] ? 1 : 0;

  }
  return 16 * ir[0] + 8 * ir[1] + 4 * ir[2] + 2 * ir[3] + 1 * ir[4] + 1000 * ir[5];
}

void lrfb(int lf, int lb, int rf, int rb) {
  analogWrite(lfmotor, lf);
  analogWrite(lbmotor, lb);
  analogWrite(rfmotor, rf);
  analogWrite(rbmotor, rb);
}

void leftTurn()
{
  while (analogRead(s[2]) < avg[2])
  {
    lrfb(0, 0, SPEED, 0);
    Serial.println("left turn");
  }
}

void rightTurn()
{
  while (analogRead(s[2]) < avg[2])
  {
    lrfb(SPEED, 0, 0, 0);
    Serial.println("right turn");
  }
}

void left()
{
  lrfb(SLOWSPEED, 0, SPEED, 0);
  Serial.println("left");
}

void right()
{
  lrfb(SPEED, 0, SLOWSPEED, 0);
  Serial.println("right");
}

void forward()
{
  lrfb(SPEED, 0, SPEED, 0);
  Serial.println("fwd");
}
void Stop()
{
  lrfb(0, 0, 0, 0);
  Serial.println("Stop");
}

void reverseLeft()
{
  lrfb(0, 0, 0, SPEED);
  Serial.println("reverse left");
}

void reverseRight()
{
  lrfb(0, SPEED, 0, 0);
  Serial.println("reverse right");
}

void backward()
{
  lrfb(0, SPEED, 0, SPEED);
  Serial.println("bwd");
}

void rotate()
{
 //while (analogRead(A2) < avg[2])
 {
    lrfb(0, 0, SPEED, 0);
    Serial.println("rotate");
  }
}

void followLine()
{
  switch (value()) {

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

    case 1014:
    case 1004:
      forward();
      break;

    case 1012:
    case 1008:
    case 1024:
    case 1028:
    case 1030:
      forward();
      break;

    case 1016:
      left();
      break;

    case 1001:
      right();
      break;

    case 1006:
    case 1002:
    case 1003:
    case 1007:
    case 1015:
      forward();
      break;

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
  Serial.println(duration * 0.034 / 2);
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
      if ((red>0.9*r[variable3] && red<1.1*r[variable3]) && (green>0.9*g[variable3] && green<1.1*g[variable3]) && (blue>0.9*b[variable3] && blue<1.1*b[variable3]))
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

void colorSense(){
  
  //blink same color led and some color led in black too
  digitalWrite(redLed,HIGH);
delay(100);
Serial.print("r=");
red=analogRead(input);
Serial.print(red);
Serial.print("  ");
digitalWrite(redLed,LOW);
delay(100);
digitalWrite(greenLed,HIGH);
delay(100);
Serial.print("g=");
green=analogRead(input);
Serial.print(green);
Serial.print("  ");
digitalWrite(greenLed,LOW);
delay(100);

digitalWrite(blueLed,HIGH);
delay(100);
Serial.print("b=");
blue=analogRead(input);
Serial.print(blue);

Serial.print("  ");
digitalWrite(blueLed,LOW);
delay(100);
Serial.println(" ");
}

int colormatch(int r, int g, int b)
{
  if ((red>0.9*r && red<1.1*r) && (green>0.9*g && green<1.1*g) && (blue>0.9*b && blue<1.1*b))
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
  digitalWrite(gripperUp, HIGH);
}

void ungrip() {
  //while (value != 1031 || distance()>7)
  //followLine();
  Stop();
  digitalWrite(gripperDown, HIGH);
  digitalWrite(gripperUp, LOW);
  delay(GRIPPERWITHLOAD);
  digitalWrite(gripperDown, LOW);
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
