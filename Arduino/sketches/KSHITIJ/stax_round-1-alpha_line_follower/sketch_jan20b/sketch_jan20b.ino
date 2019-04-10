#define SPEED 200
#define HIGHSPEED 230
#define SLOWSPEED 130
#define VSLOWSPEED 150
#define DELAY3  300//delay for crossing 3cm line)
#define DELAY3BACK 300
#define DELAYFORTURN 1000
//#define FORWARDDELAY
int s[6] = {A0, A1, A2, A3, A4, A2};
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
int trigPin = 8;
int echoPin = 7;
int leftStack = 2, rightStack = 2, centreStack = 6;
long duration;
int gripperDown = 11;
int gripperUp = 10;
int red, green, blue;
int r[4], g[4], b[4];
int redLed = 12;
int blueLed = 13;
int greenLed = 2;
//int s0 = 11; --- 5 volts
//int s1 = 10; --- ground
//int s2 = 13;
//int s3 = 12;
//int out = 2;
//int oe= 9; ---- ground
int input=A5;
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
    pinMode(blueLed, OUTPUT);
    digitalWrite(redLed,LOW);
pinMode(input,INPUT);
//  pinMode(s2, OUTPUT);
//  pinMode(s3, OUTPUT);
//  pinMode(out, INPUT);

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
  return 16 * ir[0] + 8 * ir[1] + 4 * ir[2] + 2 * ir[3] + 1 * ir[4] + 1000;
}


void leftTurn()
{
 // while (!(analogRead(s[2]) < avg[2]))
  {
    analogWrite(lfmotor, 0);
    analogWrite(lbmotor, 0);
    analogWrite(rfmotor, SPEED);
    analogWrite(rbmotor, 0);
    Serial.println("left turn");
  }
  //while (!(analogRead(s[2]) > avg[2]))
  {
    analogWrite(lfmotor, 0);
    analogWrite(lbmotor, 0);
    analogWrite(rfmotor, SPEED);
    analogWrite(rbmotor, 0);
    Serial.println("left turn");
    delay(DELAYFORTURN);
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
  //while (!(analogRead(s[2]) < avg[2]))
  {
    analogWrite(lfmotor, SPEED);
    analogWrite(lbmotor, 0);
    analogWrite(rfmotor, 0);
    analogWrite(rbmotor, 0);
    Serial.println("right turn");
  }
  //while (!(analogRead(s[4]) > avg[4]))//while (!(analogRead(s[2]) > avg[2]))
  {
    analogWrite(lfmotor, SPEED);
    analogWrite(lbmotor, 0);
    analogWrite(rfmotor, 0);
    analogWrite(rbmotor, 0);
    Serial.println("right turn");
    delay(DELAYFORTURN);
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
     // left();
      break;

    case 1:
    case 15:
      rightTurnWithBreak();
    // right();
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
  int distance=0;
for (i=0;i<10;i++){
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
  distance+= duration * 0.034 / 2;
}
return distance/10;
}

void grip() {
//  while(distance()<5)
//  backward();
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
  //  while (distance() > 10)
  //    followLine();
  
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


 
    while (value() != 1007 || value() != 1028 || value()!= 1031 || value()!=1003 || value()!=1024 || value!=1001)
      followLine();
      Stop();
      colorSense();
    colorSave();        
    rightTurn();
        while (value() != 1007 || value() != 1028 || value()!= 1031 || value()!=1003 || value()!=1024|| value!=1001)
      followLine();
      Stop();
      colorSense();
    colorSave(); 
    rightTurn();
        while (value() != 1007 || value() != 1028 || value()!= 1031 || value()!=1003 || value()!=1024|| value!=1001)
      followLine();
      Stop();
      colorSense();
    colorSave(); 
    leftTurn();
    
    while (value() != 1031)
      followLine();
  Stop();
}

void Task2() {
  forward();
  delay(400);
  grip();
  while (distance() < 20)
    backward();
  fullTurn();

  if (colorMatch(r[0], b[0], g[0]))
{
  rightTurn();
forwardNode(1);
    unGrip();
    while (distance() < 10)
      backward();
    fullTurn();
    while (value() != 1031)
      followLine();
    leftTurn();
    while (distance() > 9)
      followLine();
    grip();
    while (distance() < 30)
      backward();
      fullTurn();

      while(value()!=1031)
      followLine();
      leftTurn();
      forwardNode(2);
      unGrip();
      backwardNode(2);
      delay(500);
      fullTurn();
      while(value()!=1031);
      followLine();
      rightTurn();
      while(distance()>9)
      followLine();
      grip();
      backwardNode(3);
      delay(400);
      fullTurn();

      while(value()!=1031)
      followLine();
      
      leftTurn();
      while(distance()>10)
      followLine();
      unGrip();
      while(distance()<20)
      backward();
      fullTurn();
      while(value()!=1031)
      followLine();
      forward();
      delay(400);
      while(distance()>10)
      followLine();
      grip();
      backwardNode(1);
      delay(300);
      fullTurn();
      
     while(value()!=1031)
     followLine();
     leftTurn();
     forwardNode(3);
     unGrip();
   
  }
  else {
    leftTurn();
    forwardNode(2);
    unGrip();
    backwardNode(2);
    delay(300);
    fullTurn();
    while(value()!=1031)
    followLine();
    rightTurn();
    while(distance()>10)
    followLine();
    grip();
    backwardNode(2);
    delay(300);
    fullTurn();
    while(value!=1031)
    followLine();
    if(colorMatch(r[0],g[0],b[0]))
    {
      rightTurn();
      forwardNode(1);
      unGrip();
      backwardNode(1);
      delay(300);
      fullTurn();
      while(value()!=1031)
      followLine();
      leftTurn();
      
       while(distance()>9)
      followLine();
      grip();
      backwardNode(3);
      delay(400);
      fullTurn();

      while(value()!=1031)
      followLine();
      leftTurn();
      while(distance()>10)
      followLine();
      unGrip();
      backwardNode(2);
      delay(300);
      fullTurn();

       while(value()!=1031)
      followLine();
      forward();
      delay(400);
      while(distance()>10)
      followLine();
      grip();
      backwardNode(1);
      delay(300);
      fullTurn();
      
     while(value()!=1031)
     followLine();
     leftTurn();
     forwardNode(3);
     unGrip();

    }
    else {
            leftTurn();
      forwardNode(1);
      unGrip();
      backwardNode(1);
      delay(300);
      fullTurn();
      while(value()!=1031)
      followLine();
      leftTurn();
      
       while(distance()>9)
      followLine();
      grip();
      unGrip();
      
     
      
    }
  }

backwardNode(3);
delay(300);
fullTurn();
while(value!=1031)
followLine();
leftTurn();
while(distance()>10)
followLine();
grip();
backwardNode(1);
delay(300);
fullTurn();
while(value()!=1031)
followLine();
if(colorMatch(r[1],g[1],b[1])) 
 { 
  rightTurn();
   while(distance()>10)
   followLine();
   unGrip();
   backwardNode(2);
   delay(300);
   fullTurn();
   while(value()!=1031)
   followLine();
   leftTurn();
   while(distance()>10)
   followLine();
   grip();
   backwardNode(2);
   delay(300);
   fullTurn();
   while(value()!=1031)
   followLine();
   rightTurn();
 forwardNode(2);
 unGrip();
 backwardNode(2);
 delay(300);
 fullTurn();
 while(value()!=1031)
 followLine();
 Stop();
 }
 else {
  forward();
  delay(400);
  forwardNode(1);
  unGrip();
  backwardNode(1);
  delay(400);
  fullTurn();
  while(value()!=1031)
  followLine();
  forward();
  delay(400);
  forwardNode(2);
  grip();
  backwardNode(2);
  delay(300);
  fullTurn();
  while(value()!=1031)
  followLine();
  rightTurn();
  forwardNode(2);
  unGrip();
  backwardNode(2);
  delay(300);
  fullTurn();
  while(value()!=1031)
  followLine();
  rightTurn();
  while(distance()>10)
  grip();
  backwardNode(1);
  delay(300);
  fullTurn();
  while(value()!=1031)
  followLine();
  leftTurn();
  while(distance()>10)
  followLine();
  unGrip();
  while(distance()<15)
  backward();
  fullTurn();
  while(value!=1031)
  followLine();
  Stop();
}
}

void forwardNode(int n){
  if(n==1){
    while(value()!=1031)
    followLine();
    forward();
    delay(DELAY3);
    
  }
  else if(n==2){
    while(value()!=1031)
    followLine();
    forward();
    delay(DELAY3);

    while(value()!=1031)
    followLine();
    forward();
    delay(DELAY3);
  }

  else if(n==3)
  {
       while(value()!=1031)
    followLine();
    forward();
    delay(DELAY3);
    
        while(value()!=1031)
    followLine();
    forward();
    delay(DELAY3);
    
        while(value()!=1031)
    followLine();
    forward();
    delay(DELAY3); 
  }
}

void backwardNode(int n){
  if(n==1){
    while(value()!=1031)
    backward();
    delay(DELAY3BACK);
  }
  else if(n==2){
        while(value()!=1031)
    backward();
    delay(DELAY3BACK);

        while(value()!=1031)
    backward();
    delay(DELAY3BACK);
  }
  else if(n==3){
        while(value()!=1031)
    backward();
    delay(DELAY3BACK); 
    
    while(value()!=1031)
    backward();
    delay(DELAY3BACK); 
    
    while(value()!=1031)
    backward();
    delay(DELAY3BACK);
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
  // blinkLed(4);
  Stop();
}

void colorSense() {
  //also blink same led

  int r, g, b;
  int rsum = 0, gsum = 0, bsum = 0;

  for (i = 0; i < 5; i++) {
   digitalWrite(redLed,HIGH);
delay(50);
//Serial.print("r=");
r=analogRead(input);
//Serial.print(r);
//Serial.print("  ");
digitalWrite(redLed,LOW);
delay(50);
digitalWrite(greenLed,HIGH);
delay(50);
//Serial.print("g=");
g=analogRead(input);
//Serial.print(g);
//Serial.print("  ");
digitalWrite(greenLed,LOW);
delay(50);

digitalWrite(blueLed,HIGH);
delay(50);
//Serial.print("b=");
b=analogRead(input);
//Serial.print(b);

//Serial.print("  ");
digitalWrite(blueLed,LOW);
delay(50);
//Serial.println(" ");
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
    if (red > 0.85 * r[i] && red < 1.15 * r[i] && green > 0.85 * g[i] && green < 1.15 * g[i] && blue > 0.85 * b[i] && blue < 1.15 * b[i])
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
  if (red > 0.85 * r && red < 1.15 * r && green > 0.85 * g && green < 1.15 * g && blue > 0.85 * b && blue < 1.15 * b)
  {
    return 1;
  }
  else return 0;
}

void blinkLed() {
  if (red > 0.85 * r[0] && red < 1.15 * r[0] && green > 0.85 * g[0] && green < 1.15 * g[0] && blue > 0.85 * b[0] && blue < 1.15 * b[0])
  {
    digitalWrite(redLed,HIGH);
    digitalWrite(greenLed,HIGH);
    digitalWrite(blueLed,HIGH);
    delay(400);
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,LOW);
    digitalWrite(blueLed,LOW);
  }
  else if (red > 0.85 * r[1] && red < 1.15 * r[1] && green > 0.85 * g[1] && green < 1.15 * g[1] && blue > 0.85 * b[1] && blue < 1.15 * b[1])
  {
   digitalWrite(redLed,HIGH);
    digitalWrite(greenLed,HIGH);
    digitalWrite(blueLed,HIGH);
    delay(400);
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,LOW);
    digitalWrite(blueLed,LOW);  
    delay(400);
    digitalWrite(redLed,HIGH);
    digitalWrite(greenLed,HIGH);
    digitalWrite(blueLed,HIGH);
    delay(400);
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,LOW);
    digitalWrite(blueLed,LOW);
    }
  else if (red > 0.85 * r[2] && red < 1.15 * r[2] && green > 0.85 * g[2] && green < 1.15 * g[2] && blue > 0.85 * b[2] && blue < 1.15 * b[2])
  {
    digitalWrite(redLed,HIGH);
    digitalWrite(greenLed,HIGH);
    digitalWrite(blueLed,HIGH);
    delay(400);
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,LOW);
    digitalWrite(blueLed,LOW);
    delay(400);
       digitalWrite(redLed,HIGH);
    digitalWrite(greenLed,HIGH);
    digitalWrite(blueLed,HIGH);
    delay(400);
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,LOW);
    digitalWrite(blueLed,LOW);
    delay(400);
  }

}
void loop() {
Task1();
  Task2();
}

