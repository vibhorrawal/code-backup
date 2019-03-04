//gripper
int gripPin = ;
int ungripPin = ;
//#define TWL 300  //time taken with load
//#define TWOL 200 //time taken without load
#define MINDISTANCE 15
//ir
int s[6] = {A0, A1, A2, A3, A4, A5};
int avg[6];
int val[6];
int white[6];
int black[6];
int i;
int ir[6];

//motor
int lfmotor = 5;
int lbmotor = 3;
int rfmotor = 6;
int rbmotor = 9;

//ultrasonic
int trigPin = 9;
int echoPin = 10;
long duration;

void setup() {
  Serial.begin(9600);
  //gripper
  pinMode(gripPin, OUTPUT);
  pinMode(ungripPin, OUTPUT);
  digitalWrite(gripPin, LOW);
  digitalWrite(ungripPin, LOW);

  //motor
  pinMode( lfmotor, OUTPUT );
  pinMode( rfmotor, OUTPUT );
  pinMode( lbmotor, OUTPUT );
  pinMode( rbmotor, OUTPUT );

  //ultrasonic
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //calibration
  Serial.println("Place on White");
  delay(5000);
  Serial.println("Read White");
  s[0] = analogRead(A0);
  s[1] = analogRead(A1);
  s[2] = analogRead(A2);
  s[3] = analogRead(A3);
  s[4] = analogRead(A4);
  s[5] = analogRead(A5);
  for (i = 0; i < 6; i++)
  {
    white[i] = s[i];
  }
  delay(1000);

  Serial.println("Place on Black");
  delay(5000);
  Serial.println("Read Black ");
  s[0] = analogRead(A0);
  s[1] = analogRead(A1);
  s[2] = analogRead(A2);
  s[3] = analogRead(A3);
  s[4] = analogRead(A4);
  s[5] = analogRead(A5);
  for (i = 0; i < 6; i++)
  {
    black[i] = s[i];
  }

  for (i = 0; i < 6; i++)
  {
    avg[i] = (black[i] + white[i]) / 2;
  }

}
int value()
{
  s[0] = analogRead(A0);
  s[1] = analogRead(A1);
  s[2] = analogRead(A2);
  s[3] = analogRead(A3);
  s[4] = analogRead(A4);
  s[5] = analogRead(A5);

  for (i = 0; i < 6; i++)
  {
    ir[i] = s[i] < avg[i] ? 1 : 0;

  }
  return 32 * ir[0] + 16 * ir[1] + 8 * ir[2] + 4 * ir[3] + 2 * ir[4] + 1 * ir[5];  // 1 ** 2 3 4 5 6 7 ** 8 -- array numbering
}


//motor
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
  analogWrite(rbmotor, 155);
  analogWrite(lbmotor, 0);
  Serial.println("left");
}

void reverseRightTurn()
{
  analogWrite(lbmotor, 155);
  analogWrite(rbmotor, 0);
  Serial.println("right");
}

void backward()
{
  analogWrite(lbmotor, 155);
  analogWrite(rbmotor, 155);
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
  analogWrite(lfmotor,0);
  analogWrite(rfmotor,0);
}
//ultrasonic
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

void followReverseLine()
{
  switch (value()) {

    case 12:
    case 30:
      backward();
      break;

    case 24:
      reverseLeft();
      break;

    case 6:
      reverseRight();
      break;

    case 28:
    case 60:
      reverseleftTurn();
      break;

    case 14:
    case 15:
      reverseRightTurn();
      break;

    default:
      rotate();
  }
}

void followLine()
{
  switch (value()) {

    case 12:
    case 30:
      forward();
      break;

    case 24:
      left();
      break;

    case 6:
      right();
      break;

    case 28:
    case 60:
      leftTurn();
      break;

    case 14:
    case 15:
      rightTurn();
      break;

    default:
      rotate();
  }
}

void grip()
{
  
  
}

void ungrip()
{
  
}

void loop() {
  
 while(distance()> MINDISTANCE)
 followLine();
 Stop();
 grip();
 
 while(value()!=0)
 followReverseLine();
 ungrip();
}
