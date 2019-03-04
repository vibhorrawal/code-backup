//06 december 2017
//Code BY VIBHOR RAWAL

// ir array pins
int s[6] = {A0, A1, A2, A3, A4, A5};

// motor driver pins
int lfmotor = 6;
int rfmotor = 10;
int bell = 12;

//ultrasonic pins
int trigPin = 9;
int echoPin = 11;

//color sensor
int s0 = 13;
int s1 = 5;
int s2 = 7;
int s3 = 8;
int out = 10;

int j = 0;
int variable = 0;

int red[4];
int green[4];
int blue[4];



//for color sensor
int r, g, b;

//for ultrasonic sensor
long duration;
int distance;

//for ir
int avg[6];
int val[6];
int white[6];
int black[6];
int i;
int ir[6];


void setup() {

  //5V output pin
  // pinMode( 2, OUTPUT );
  //digitalWrite( 2, HIGH );
  pinMode( lfmotor, OUTPUT );
  pinMode( rfmotor, OUTPUT );
  analogWrite(lfmotor, 0);
  analogWrite(rfmotor, 0);

  //calibration
  delay(1000);

  //for ir
  value();
  for (i = 0; i < 6; i++)
  {
    white[i] = s[i];
  }
  digitalWrite(bell, HIGH);
  delay(300);
  digitalWrite(bell, LOW);
  delay(4000);

  value();
  for (i = 0; i < 6; i++)
  {
    black[i] = s[i];
  }

  digitalWrite(bell, HIGH);
  delay(300);
  digitalWrite(bell, LOW);

  for (i = 0; i < 6; i++)
  {
    avg[i] = (black[i] + white[i]) / 2;
  }

  //for color sensor
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  pinMode(2, OUTPUT);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);

  //for ultrasonic
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);



  Serial.begin(9600);
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
    ir[i] = s[i] > avg[i] ? 1 : 0;
  }

  return 2 * ir[0] + 4 * ir[1] + 8 * ir[2] + 16 * ir[3] + 32 * ir[4] + 64 * ir[5];  // 1 ** 2 3 4 5 6 7 ** 8 -- array numbering
}

void left()
{
  analogWrite(rfmotor, 155);
  analogWrite(lfmotor, 0);
  Serial.println("left");
}


void right()
{
  analogWrite(lfmotor, 155);
  analogWrite(rfmotor, 0);
  Serial.println("right");
}


void front()
{
  analogWrite(lfmotor, 155);
  analogWrite(rfmotor, 155);
  Serial.println("front");
}

void rotate()
{ do {
    analogWrite(lfmotor, 0);
    analogWrite(rfmotor, 255);
  } while (value() == 0);

  Serial.println("rotate");
}
unsigned int t = 0;
void Tcase()
{
  do {
    if (t % 3 == 1)
      left();
    if (t % 3 == 0)
      front();
    if (t % 3 == 2)
      right();
    delay(100);
    t += 1;

  } while (value() == 252);
}

void colorSensor()
{
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  r = pulseIn(out, LOW);
  r = map(r, 250, 1000, 255, 0);
  // r = constrain(r,0,255);
  Serial.print("\tR= ");
  Serial.print(r);
  Serial.print("\t");
  delay(100);

  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  g = pulseIn(out, LOW);
  g = map(g, 250, 1000, 255, 0);
  // g = constrain(g,0,255);
  Serial.print("\tG= ");
  Serial.print(g);
  Serial.print("\t");
  delay(100);

  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  b = pulseIn(out, LOW);
  b = map(b, 250, 1000, 255, 0);
  // b = constrain(b,0,255);
  Serial.print("\tB= ");
  Serial.print(b);
  Serial.println("\t");
  delay(100);

  if (j < 4)
  {
    red[j] = r;
    green[j] = g;
    blue[j] = b;
    j++;
  }
  variable++;
}

int distanceSensor()
{
  //ultrasonic
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
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  return distance;
}

void loop() {


  switch (value()) {

    case 48: // 4 5
    case 120: // 3 4 5 6
      front();
      variable = 0;
      break;


    case 28: // 2 3 4
    case 12: // 2 3
    case 60: // 2 3 4 5
    case 24: // 3 4
      left();
      break;


    case 224: // 5 6 7
    case 192: // 6 7
    case 240: // 4 5 6 7
    case 96: // 5 6
      right();
      break;

    case 252: // 2 3 4 5 6 7
      Tcase();
      break;

    default:
      rotate();
  }
  if ((distanceSensor() < 5) && (variable == 0) && (value() != 48) && (value != 120) ) // distance is less than 3 cm and the bot has just started turning and save that value once
  {
    colorSensor();
  }





}
