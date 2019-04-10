int s[5] = {A0, A1, A2, A3, A4};
int avg[5];
int val[5];
int white[5];
int black[5];
int i;
int ir[5];
int lfmotor = 5;
int rfmotor = 6;
int lbmotor = 3;
int rbmotor = 9;
void setup() {
  Serial.begin(9600);
  pinMode( lfmotor, OUTPUT );
  pinMode( rfmotor, OUTPUT );  
  pinMode( lbmotor, OUTPUT );
  pinMode( rbmotor, OUTPUT );
  digitalWrite(lbmotor,LOW);
  digitalWrite(rbmotor,LOW);
   digitalWrite(lfmotor,LOW);
  digitalWrite(rfmotor,LOW); 
  Serial.println("Place on White");
  delay(5000);

  for (i = 0; i < 5; i++)
  {
    s[i] = analogRead(s[i]);
    white[i] = s[i];
    Serial.print(white[i]);
    Serial.print("\t");
  } Serial.println(" ");
  delay(1000);

  Serial.println("Place on Black");
  delay(5000);

  for (i = 0; i < 5; i++)
  {
    s[i] = analogRead(s[i]);
    black[i] = s[i];
     Serial.print(black[i]);
    Serial.print("\t");
  } Serial.println(" ");
delay(2000);
  for (i = 0; i < 5; i++)
  {
    avg[i] = (black[i] + white[i]) / 2;
  }
}

int value()
{
  for (i = 0; i < 5; i++)
  {
    s[i] = analogRead(s[i]);
    ir[i] = s[i] > avg[i] ? 1 : 0;

  }
  return 16 * ir[0] + 8 * ir[1] + 4 * ir[2] + 2 * ir[3] + 1 * ir[4] ;  
}
void lrfb(int lf,int lb,int rf,int rb){
  analogWrite(lfmotor, lf);
  analogWrite(lbmotor, lb);
  analogWrite(rfmotor, rf);
  analogWrite(rbmotor, rb);
}
void leftTurn()
{while(analogRead(A2)<avg[2])
{
  lrfb(0,SPEED,SPEED,0); 
  Serial.println("left turn");}
}

void rightTurn()
{while(analogRead(A2)<avg[2])
{
  lrfb(SPEED,0,0,SPEED);
  Serial.println("right turn");}
}

void left()
{
  lrfb(SLOWSPEED,0,SPEED,0); 
  Serial.println("left");
}


void right()
{
  lrfb(SPEED,0,SLOWSPEED,0);
  Serial.println("right");
}

void forward()
{
  analogWrite(lfmotor, 150);
  analogWrite(rfmotor, 1drtidr50);
  Serial.println("fwd");
}
void Stop()
{
  analogWrite(lfmotor, 0);
  analogWrite(rfmotor, 0);
     analogWrite(rbmotor, 0);
  analogWrite(lbmotor, 0);
  Serial.println("Stop");
}

//void reverseLeft()
//{
//  analogWrite(rfmotor, 150);
//  analogWrite(lfmotor, 100);
//}
//
void reverseRight()
{
  analogWrite(rmotor, 0);
  analogWrite(lbmotor, 150);
}

//void reverseLeftTurn()
//{
//  analogWrite(rbmotor, 150);
//  analogWrite(lbmotor, 0);
//  Serial.println("left");
//}
//
//void reverseRightTurn()
//{
//  analogWrite(lbmotor, 150);
//  analogWrite(rbmotor, 0);
//  Serial.println("right");
//}

void backward()
{
  analogWrite(lbmotor, 150);
  analogWrite(rbmotor, 150);
  Serial.println("bwd");
}

void rotate()
{do {
    analogWrite(lfmotor, 0);
    analogWrite(rfmotor, 150);
       analogWrite(rbmotor, 0);
  analogWrite(lbmotor, 0);
    Serial.println("rotate");
  } while (analogRead(A2)<avg[2]);
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

    default:
      rotate();
  }
}
void loop() {
  
  followLine();
Serial.println(value());
}
