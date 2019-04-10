int s[5] = {A0, A1, A2, A3, A4};
int avg[5];
int val[5];

int gripperDown = 8;
int gripperUp = 10;
int black[5];
int i;
int ir[5];
int lfmotor = 5;
int rfmotor = 6;
//ultrasonic
int trigPin = 9;
int echoPin = 10;
long duration;

void setup() {
  Serial.begin(9600);
  pinMode( lfmotor, OUTPUT );
  pinMode( rfmotor, OUTPUT );
  Serial.println("Place on White");
  delay(5000);
  s[0] = analogRead(A0);
  s[1] = analogRead(A1);
  s[2] = analogRead(A2);
  s[3] = analogRead(A3);
  s[4] = analogRead(A4);
  for (i = 0; i < 5; i++)
  {
    white[i] = s[i];
  }
  delay(1000);

  Serial.println("Place on Black");
  delay(5000);
  s[0] = analogRead(A0);
  s[1] = analogRead(A1);
  s[2] = analogRead(A2);
  s[3] = analogRead(A3);
  s[4] = analogRead(A4);
  for (i = 0; i < 5; i++)
  {
    black[i] = s[i];
  }

  for (i = 0; i < 5; i++)
  {
    avg[i] = (black[i] + white[i]) / 2;
  }
  pinMode(gripperDown, OUTPUT);
  pinMode(gripperUp, OUTPUT);
  digitalWrite(gripperDown, LOW);
  digitalWrite(gripperUp, LOW);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

int value()
{
  s[0] = analogRead(A0);
  s[1] = analogRead(A1);
  s[2] = analogRead(A2);
  s[3] = analogRead(A3);
  s[4] = analogRead(A4);

  for (i = 0; i < 5; i++)
  {
    ir[i] = s[i] > avg[i] ? 1 : 0;

  }
  return 16 * ir[0] + 8 * ir[1] + 4 * ir[2] + 2 * ir[3] + 1 * ir[4] ;
}
void left()
{
  analogWrite(rfmotor, 155);
  analogWrite(lfmotor, 100);
}

void right()
{
  analogWrite(rfmotor, 100);
  analogWrite(lfmotor, 155);
}

void leftTurn()
{
  analogWrite(rfmotor, 155);
  analogWrite(lfmotor, 0);
  Serial.println("left");
}

void rightTurn()
{
  analogWrite(lfmotor, 155);
  analogWrite(rfmotor, 0);
  Serial.println("right");
}

void forward()
{
  analogWrite(lfmotor, 155);
  analogWrite(rfmotor, 155);
  Serial.println("fwd");
}

void reverseLeft()
{
  analogWrite(rfmotor, 155);
  analogWrite(lfmotor, 100);
}

void reverseRight()
{
  analogWrite(rfmotor, 100);
  analogWrite(lfmotor, 155);
}

void reverseLeftTurn()
{
  // analogWrite(rbmotor, 155);
  //analogWrite(lbmotor, 0);
  Serial.println("left");
}

void reverseRightTurn()
{
  //  analogWrite(lbmotor, 155);
  //  analogWrite(rbmotor, 0);
  Serial.println("right");
}

void backward()
{
  //analogWrite(lbmotor, 155);
  //analogWrite(rbmotor, 155);
  Serial.println("bwd");
}

void rotate()
{ do {
    analogWrite(lfmotor, 0);
    analogWrite(rfmotor, 255);
    Serial.println("rotate");
  } while (value() == 0);
}
void Stop()
{
  analogWrite(lfmotor, 0);
  analogWrite(rfmotor, 0);
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


void followLine()
{
  switch (value()) {

    case 14:
    case 4:
      forward();
      break;

    case 12:
    case 8:
      left();
      break;

    case 6:
    case 2:
      right();
      break;

    case 28:
    case 24:
      leftTurn();
      break;

    case 3:
    case 7:
      rightTurn();
      break;

    default:
      rotate();
  }
}
void grip() {
  //gripper down
  digitalWrite(gripperDown, HIGH);
  digitalWrite(gripperUp, LOW);
  delay(2000);
  digitalWrite(gripperDown, LOW);
  //fwd
  digitalWrite(lmotor, HIGH);
  digitalWrite(rmotor, HIGH);
  delay(200);
  digitalWrite(lmotor, LOW);
  digitalWrite(rmotor, LOW);
  //gripper up
  digitalWrite(gripperUp,HIGH);
  delay(2000);
}
void loop() {
  while (distance() > 15)
    followLine();
  Stop();
  grip();

}
