//ir
int s[5] = {A0, A1, A2, A3, A4};
int avg[5];
int val[5];
int black[5];
int white[5];
int i;
int ir[5];
int lfmotor = 5;
int rfmotor = 6;
int lbmotor = 5;
int rbmotor = 6;
//gripper
int gripperDown = 8;
int gripperUp = 10;
//ultrasonic
int trigPin = 9;
int echoPin = 10;
long duration;
//colorsensor
int r[4];
int g[4];
int b[4];
int r1, g1, b1;
int j = 0;
int redLed = 3;
int blueLed = 5;
int greenLed = 4;
int input = A5;
int vcc1V = 11;
int vcc5 = 0;

#define GRIPBLOCK  100//time to move fwd/bwd to let gripper meet block
#define MINDISTANCE 100// for gripping
#define BREADTH 100// FOR GRIPPING breadth of block
#define GRIPPING 100//moving time of arms up and down

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
  //color
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(input, INPUT);
  pinMode(vcc1V, OUTPUT);
  pinMode(vcc5, OUTPUT);
  digitalWrite(vcc5, HIGH);
  analogWrite(vcc1V, 255);
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
{
  //  do {
  analogWrite(lbmotor, 155);
  analogWrite(rfmotor, 155);
  Serial.println("rotate");
  // } while (value() == 0);
}

void Stop()
{
  analogWrite(lfmotor, 0);
  analogWrite(rfmotor, 0);
   analogWrite(lbmotor, 0);
  analogWrite(rbmotor, 0);
  
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
    case 31:
      Tcase();
      //
      //    default:
      //      rotate();
  }
}

void grip() {
  digitalWrite(redLed, LOW);
  delay(10);
  Serial.print("r=");
  r1 = analogRead(input);
  Serial.print(r1);
  Serial.print("  ");
  digitalWrite(redLed, HIGH);
  delay(10);
  digitalWrite(greenLed, LOW);
  delay(10);
  Serial.print("g=");
  g1 = analogRead(input);
  Serial.print(g1);
  Serial.print("  ");
  digitalWrite(greenLed, HIGH);
  delay(10);

  digitalWrite(blueLed, LOW);
  delay(10);
  Serial.print("b=");
  b1 = analogRead(input);
  Serial.print(b1);

  Serial.print("  ");
  digitalWrite(blueLed, HIGH);
  delay(10);
  Serial.println(" ");

  //gripper down
  digitalWrite(gripperDown, HIGH);
  digitalWrite(gripperUp, LOW);
  delay(GRIPPING);
  digitalWrite(gripperDown, LOW);
  delay(200);
  forward();
  delay(GRIPPING);
  Stop();
  //gripper up
  digitalWrite(gripperUp, HIGH);
  digitalWrite(gripperDown, LOW);
  delay(GRIPPING);
  digitalWrite(gripperUp, LOW);
  while (value() == 0)
    backward();

}

void ungrip() {
digitalWrite(redLed, LOW);
  delay(10);
  Serial.print("r=");
  r1 = analogRead(input);
  Serial.print(r1);
  Serial.print("  ");
  digitalWrite(redLed, HIGH);
  delay(10);
  digitalWrite(greenLed, LOW);
  delay(10);
  Serial.print("g=");
  g1 = analogRead(input);
  Serial.print(g1);
  Serial.print("  ");
  digitalWrite(greenLed, HIGH);
  delay(10);

  digitalWrite(blueLed, LOW);
  delay(10);
  Serial.print("b=");
  b1 = analogRead(input);
  Serial.print(b1);

  Serial.print("  ");
  digitalWrite(blueLed, HIGH);
  delay(10);
  Serial.println(" ");

  
  //gripper down
  digitalWrite(gripperDown, HIGH);
  digitalWrite(gripperUp, LOW);
  delay(GRIPPING);
  digitalWrite(gripperDown, LOW);
  backward();
  digitalWrite(gripperUp, HIGH);
  delay(GRIPPING);
  while (value() == 0)
    backward();

}

void Tcase(){
  //1st block
        do{
           forward();
          }while(value()==4 || value()==14);

  for (i = 0; i < 3; i++)
  {
    while (distance() > MINDISTANCE)
      followLine();
    grip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 4 || value() != 14);

    while (value() != 252)        //  untill T is encountered
      followLine();

    if (colormatch(r[0], g[0], b[0]))
    {
      do{
        left();
      }while(value()==4 || value()==14);
      // turn left
      }
      while (distance() > BREADTH)
        followLine();
      ungrip();

      do {                            //180 degree turn
        rotate();
      } while (value() != 4 || value() != 14);

      while (value() != 252)        //  untill T is encountered
        followLine();
      right();                  //turn right
    }
    else
    {
            do{
        right();
      }while(value()==4 || value()==14);                  //turn right

      while (distance() > BREADTH)
        followLine();
      ungrip();

      do {                            //180 degree turn
        rotate();
      } while (value() != 4 || value() != 14);

      while (value() != 252)        //  untill T is encountered
        followLine();
            do{
        left();
      }while(value()==4 || value()==14);                       //turn left
    


  }

  //last block
  while (distance() > MINDISTANCE)
    followLine();
  if (!(colormatch(r[3], g[3], b[3])))
  {
    grip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 4 || value() != 14);

    while (value() != 252)        //  untill T is encountered
      followLine();



          do{
        right();
      }while(value()==4 || value()==14);                       // turn right
    while (distance() > BREADTH)
      followLine();
    ungrip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 4 || value() != 14);

    while (value() != 252)        //  untill T is encountered
      followLine();
    forward();                  //go straight

    while (distance() > BREADTH)
      followLine();

         grip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 4 || value() != 14);

    while (value() != 252)        //  untill T is encountered
      followLine();
          do{
        right();
      }while(value()==4 || value()==14);

    while (distance() > BREADTH)
      followLine();
    ungrip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 4 || value() != 14);

    while (value() != 252)        //  untill T is encountered
      followLine();

  }
  else
  {
    do {                            //180 degree turn
      rotate();
    } while (value() != 4 || value() != 14);

    while (value() != 252)        //  untill T is encountered
      followLine();
  }




  //2nd block

  for (i = 0; i < 3; i++)
  {
          do{
        right();
      }while(value()==4 || value()==14);

    while (distance() > BREADTH)
      followLine();
    grip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 4 || value() != 14);

    while (value() != 252)        //  untill T is encountered
      followLine();

    if (colormatch(r[1], g[1], b[1]))
    {
            do{
        left();
      }while(value()==4 || value()==14);
      while (distance() > BREADTH)
        followLine();
      ungrip();

      do {                            //180 degree turn
        rotate();
      } while (value() != 4 || value() != 14);

      while (value() != 252)        //  untill T is encountered
        followLine();

    }

    else
    {
      forward();
      while (distance() > BREADTH)
        followLine();
      ungrip();

      do {                            //180 degree turn
        rotate();
      } while (value() != 4 || value() != 14);

      while (value() != 252)        //  untill T is encountered
        followLine();
            do{
        right();
      }while(value()==4 || value()==14);

      while (distance() > 5 * BREADTH)
        followLine();

      do {                            //180 degree turn
        rotate();
      } while (value() != 4 || value() != 14);

      while (value() != 252)        //  untill T is encountered
        followLine();

    }

  }



  //3rd Block


        do{
        left();
      }while(value()==4 || value()==14);
  while (distance() > BREADTH)
    followLine();
  grip();

  do {                            //180 degree turn
    rotate();
  } while (value() != 4 || value() != 14);

  while (value() != 252)        //  untill T is encountered
    followLine();

  if (colormatch(r[2], g[2], b[2]))
  {
          do{
        right();
      }while(value()==4 || value()==14);
    while (distance() > BREADTH)
      followLine();
    ungrip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 4 || value() != 14);

    while (value() != 252)        //  untill T is encountered
      followLine();

    //4th block
          do{
        left();
      }while(value()==4 || value()==14);
    while (distance() > BREADTH)
      followLine();
    grip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 4 || value() != 14);

    while (value() != 252)        //  untill T is encountered
      followLine();

          do{
        right();
      }while(value()==4 || value()==14);

    while (distance() > BREADTH)
      followLine();
    ungrip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 4 || value() != 14);

    while (value() != 252)        //  untill T is encountered
      followLine();


  }

  else
  {
    forward();

    while (distance() > BREADTH)
      followLine();
    ungrip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 4 || value() != 14);

    while (value() != 252)        //  untill T is encountered
      followLine();

    forward();
    while (distance() > BREADTH)
      followLine();
    grip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 4 || value() != 14);

    while (value() != 252)        //  untill T is encountered
      followLine();

          do{
        right();
      }while(value()==4 || value()==14);

    while (distance() > BREADTH)
      followLine();
    ungrip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 4 || value() != 14);

    while (value() != 252)        //  untill T is encountered
      followLine();

          do{
        right();
      }while(value()==4 || value()==14);

    while (distance() > BREADTH)
      followLine();
    grip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 4 || value() != 14);

    while (value() != 252)        //  untill T is encountered
      followLine();

         do{
        left();
      }while(value()==4 || value()==14);

    while (distance() > BREADTH)
      followLine();
    ungrip();

    do {                            //180 degree turn
      rotate();
    } while (value() != 4 || value() != 14);

    while (value() != 252)        //  untill T is encountered
      followLine();


  }
}

void colorSensor() {
  digitalWrite(redLed, LOW);
  delay(10);
  Serial.print("r=");
  r1 = analogRead(input);
  Serial.print(r1);
  Serial.print("  ");
  digitalWrite(redLed, HIGH);
  delay(10);
  digitalWrite(greenLed, LOW);
  delay(10);
  Serial.print("g=");
  g1 = analogRead(input);
  Serial.print(g1);
  Serial.print("  ");
  digitalWrite(greenLed, HIGH);
  delay(10);

  digitalWrite(blueLed, LOW);
  delay(10);
  Serial.print("b=");
  b1 = analogRead(input);
  Serial.print(b1);

  Serial.print("  ");
  digitalWrite(blueLed, HIGH);
  delay(10);
  Serial.println(" ");

  if (j < 4)
  {
    r[j] = r1;
    g[j] = g1;
    b[j] = b1;
    j++;
  }
}

int colormatch(int red, int green, int blue) {
  //red, green, blue are stored values check them with scanning new color values r1,g1,b1
  
  if ( (abs(r1 - red) < 10) && (abs(g1 - green) < 10) && (abs(b1 - blue) < 10))
    return 1;
  else
    return 0;

}

void loop() {
  followLine();
  if ((distance() < 5) && (value() != 4) && (value() != 14) ) // distance is less than 3 cm and the bot has just started turning and save that value once
  {
    colorSensor();
  }

}


