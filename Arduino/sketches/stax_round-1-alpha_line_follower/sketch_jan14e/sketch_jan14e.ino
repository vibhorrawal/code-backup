#define SPEED 150
#define SLOWSPEED 100
#define VSLOWSPEED 150
int s[6] = {A4, A3, A2, A1, A0, A5};
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
void reverseLeftTurn()
{ while ((analogRead(s[2]) > avg[2])) {
    analogWrite(lfmotor, 0);
    analogWrite(lbmotor, 0);
    analogWrite(rfmotor, 0);
    analogWrite(rbmotor, SPEED);
    Serial.println("reverse left turn");
  }

}

void reverseRightTurn()
{
  while ((analogRead(s[2]) < avg[2])) {
    analogWrite(lfmotor, 0);
    analogWrite(lbmotor, SPEED);
    analogWrite(rfmotor, 0);
    analogWrite(rbmotor, 0);
    Serial.println("reverse right");
  }
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

void reverserotate()
{
  //while (analogRead(A2) < avg[2])
  {
    analogWrite(lfmotor, 0);
    analogWrite(lbmotor, SPEED);
    analogWrite(rfmotor, 0);
    analogWrite(rbmotor, 0);
    Serial.println("reverse rotate");
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
      forward();
      break;

    case 12:
    case 8:
    case 24:
    case 28:

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
      right();
      break;

    default:
      rotate();
  }
}
void reverseLine()
{ int value2;
  value2 = value();
  if (value2 > 1000)
    value2 -= 1000;
  switch (value2) {
    case 0:
      Stop();
      break;

    case 14:
    case 4:
      backward();
      break;

    case 12:
    case 8:
    case 5:
    case 24:
    
    case 28:
      reverseRight();
      break;
case 16:
reverseLeftTurn();
break;
    case 1:
    reverseRightTurn();
    break;
    
    case 2:
    case 3:
    case 6:
    case 7:
      reverseLeft();
      break;

    case 15:
      rightTurn();
      break;


    case 30:
      leftTurn();
      break;

    default:
      reverserotate();
  }
}
int distance()
{
  int distance;
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
  distance = (float)duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  return distance;
}
void distance2()
{
  int distance;
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
  distance = (float)duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
//  return distance;
}
void grip() {
  Stop();
  digitalWrite(gripperDown, HIGH);
  digitalWrite(gripperUp, LOW);
  delay(1500);
  digitalWrite(gripperDown, LOW);
 while(distance()>5)
 followLine();
  digitalWrite(gripperDown, LOW);
  digitalWrite(gripperUp, HIGH);
  delay(1500);
  digitalWrite(gripperUp, LOW);
  backward();
  delay(3000);

}

void loop() {
distance2();//while(distance()> 9)
//followLine();
//grip();
//Stop();
//delay(10000);
}

