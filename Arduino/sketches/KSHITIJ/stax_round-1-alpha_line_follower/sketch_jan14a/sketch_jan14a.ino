int sum = 0;
//arr s[6];
int irpos[5] = {A0, A1, A2, A3, A4} ;
int stack = 1;
int points[5] = {1, 2, 4, 8, 16};
int trigPin = 3;
int echoPin = 2;
int flag = 1, situation = 1;
long duration;
int distance, dis;
int MR = 5;
int ML = 10;
int MRB = 6;
int MLB = 9;
int gripperup = 8;
int gripperdown = 7;
int ct=0;
int i;
int avg[5];
int ir[5], black[5], white[5];



int readdistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  return distance;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (i = 0; i < 5; i++)
  {
    pinMode(irpos[i], INPUT);
  }
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  pinMode(MR, OUTPUT);
  pinMode(ML, OUTPUT);
  pinMode(MRB, OUTPUT);
  pinMode(MLB, OUTPUT);
  digitalWrite(MRB, LOW);
  digitalWrite(MLB, LOW);
  digitalWrite(MR, HIGH);
  digitalWrite(ML, HIGH);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(gripperup, OUTPUT);
  pinMode(gripperdown, OUTPUT);
  delay(1000);
  digitalWrite(ML, LOW);
  digitalWrite(MR, LOW);
  delay(4000);
  for (i = 0; i < 5; i++)
  {
    black[i] = (analogRead(irpos[i]) + analogRead(irpos[i]) + analogRead(irpos[i])) / 3;
  }
  Serial.print("BLACK = ");
  for (i = 0; i < 5; i++)
  {
    Serial.print(black[i]);
    Serial.print(" ");
  }
  Serial.println(" ");
  digitalWrite(MR, HIGH);
  digitalWrite(ML, HIGH);
  delay(4000);
  digitalWrite(ML, LOW);
  digitalWrite(MR, LOW);
  delay(3000);
  //white=(analogRead(L2)+analogRead(L1)+analogRead(C)+analogRead(T)+analogRead(R1)+analogRead(R2))/6;
  Serial.print("WHITE = ");
  for (i = 0; i < 5; i++)
  {
    white[i] = (analogRead(irpos[i]) + analogRead(irpos[i]) + analogRead(irpos[i])) / 3;
  }
  for (i = 0; i < 5; i++)
  {
    Serial.print(white[i]);
    Serial.print(" ");
  }
  for (i = 0; i < 5; i++)
  {
    avg[i] = (black[i] + white[i]) / 2;
  }

  Serial.println(" ");
  digitalWrite(MR, HIGH);
  digitalWrite(ML, HIGH);
  delay(2000);
  digitalWrite(ML, LOW);
  digitalWrite(MR, LOW);
  delay(3000);

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void moverightfrommain()
{
  setval();
  
 rotate();
  situation = 0;
  while (!(ir[0] == 1 && ir[1] == 1 && ir[2] == 1 && ir[3] == 1 && ir[4] == 1))
  {
    setline();
  }
  
  while(!(ir[0] == 0 && ir[1] == 0 && ir[2] == 0 && ir[3] == 0 && ir[4] == 0))
  {
   setline(); 
  }
  stack = 2;
}
void movenodefromright()
{
  setval();
  situation = 3;
  rotate();
  while (!(ir[0] == 1 && ir[1] == 1 && ir[2] == 1 && ir[3] == 1 && ir[4] == 1))
  {
    setline();
  }
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int setval()
{ sum = 0;
  for (i = 0; i < 5; i++)
  {
    ir[i] = analogRead(irpos[i]);
  }
  for (i = 0; i < 5; i++)
  {
    ir[i] = ir[i] < avg[i] ? 0 : 1; //CHECK
  }
  for (i = 0; i < 5; i++)
  {
    if (ir[i] == 1)
    {
      //ir[i]=1;
      sum += points[i];
    }
    else
    {
      ir[i] = 0;
    }
    Serial.print(ir[i]);
    Serial.print(" ");
  }
  Serial.println(" ");
  return sum;
}
void straight()
{
  analogWrite(MR, 150);
  analogWrite(ML, 150);
  Serial.println("STRAIGHT");
  //goto labelx;
}
void rotate()
{
  analogWrite(MR,150);
  analogWrite(ML,150);
  delay(1000);
  analogWrite(MR,0);
  analogWrite(ML,0);
  setval();
  while(!(ir[2]==1))
  {
    setval();
    analogWrite(MR,150);
    analogWrite(MLB,150);
  }
    analogWrite(MR,0);
    analogWrite(MLB,0);
}
void right()
{
  //analogWrite(MR,0);
  //analogWrite(ML,0);
  Serial.println("RIGHT");
  //do{
  analogWrite(ML, 250);
  analogWrite(MR, 0);
  //setval();
  //}while(sum!=12);
  //goto labelx;
}
void left()
{
  Serial.println("LEFT");
  analogWrite(ML, 0);
  analogWrite(MR, 250);
}
void leftturn()
{
  Serial.println("LT");
  while(!( ir[2]==0))
  {
    setval();
      analogWrite(MLB, 150);
  analogWrite(MR, 150);
  }
  setval();
    while(!( ir[2]==1))
  {
    setval();
      analogWrite(MLB, 150);
  analogWrite(MR, 150);
  }
}
void rightturn()
{
  while(!(ir[1]==1 || ir[2]==1 || ir[3]==1))
  {
      analogWrite(ML, 200);
  analogWrite(MRB, 200);
  }
}
void stopmotor()
{
  Serial.println("STOP");
  analogWrite(ML, 0);
  analogWrite(MR, 0);
  analogWrite(MLB, 0);
  analogWrite(MRB, 0);
  if (flag == 1)
  {
    pickup();
    if (stack == 1)
    {
      moverightfrommain();
    }
    else if (stack == 2)
    {
      movenodefromright();
    }
  }
  else
  {
    putdown();
    if (stack == 2)
    {
      movenodefromright();
    }
    else if (stack == 1)
    {
      moverightfrommain();
    }
  }
}
void pickup()                                     // pickup block
{
  Serial.println("Pick");
  dis = readdistance();
  if (dis > 10)
  {
    analogWrite(MR, 190);
    analogWrite(ML, 190);
    delay(10);
    analogWrite(MR, 0);
    analogWrite(ML, 0);
    pickup();
  }
  else if (dis < 10)
  {
    analogWrite(MRB, 190);
    analogWrite(MLB, 190);
    delay(10);
    analogWrite(MRB, 0);
    analogWrite(MLB, 0);
    pickup();
  }
  else
  {
    digitalWrite(gripperup, HIGH);
    digitalWrite(gripperdown, LOW);
    delay(1500);
    digitalWrite(gripperup, LOW);
    digitalWrite(gripperdown, LOW);
    flag = 0;
  }
}
void putdown()                                // putdown block
{

  /*while(dis>10)
    {
    analogWrite(MR,80);
    analogWrite(ML,80);
    dis=readdistance();
    setval();
    }*/
  digitalWrite(gripperdown, HIGH);
  digitalWrite(gripperup, LOW);
  Serial.println("HIGH");
  delay(3000);
  digitalWrite(gripperdown, LOW);
  digitalWrite(gripperup, LOW);
  flag = 1;
  Serial.println("LOW");
  
}

void setline()
{
  int p;
  p = setval();
  switch (p) //16 8 $ 4 $ 2 1
  {
    case 0: stopmotor();
    ct++;
      break;
    case 4: 
      straight();//$ $ 4 $ $
      break;
    case 31:
      if (situation == 0)
      {
        leftturn();
      }
      else if (situation == 1)
      {
        straight();
        delay(100);
      }
      else if (situation == 2)
      {
        rightturn();
      }
      else if (situation == 3)
      {
        while ((ir[0] == 1 && ir[1] == 1 && ir[2] == 1 && ir[3] == 1 && ir[4] == 1))
        {
          analogWrite(MLB, LOW);
          analogWrite(ML, LOW);
          analogWrite(MRB, LOW);
          analogWrite(MR, LOW);
        }
      }

      //straight();//16 8 4 2 1
      break;
    case 7: right();// $ $ 4 2 1
      break;
    case 3: right();//$ $ $ 2 1
      break;
    case 1: right();//$ $ $ $ 1
      break;
    case 2: right();//$ $ $ 2 $
      break;
    case 6: straight();//$ $ 4 2 $
      break;
    case 5: right();//$ $ 4 $ 1
      break;
    case 15: right();//$ 8 4 2 1
      break;
    case 28: left();//16 8 4 $ $
      break;

    case 8: left();//$ 8 $ $ $
      break;
    case 12: straight();//$ 8 4 $ $
      break;
    case 16: left(); //  16 $ $ $ $
      break;
    case 20: left(); //16 $ 4 $ $
      break;
    case 30: left(); // 16 8 4 2 $
      break;
    case 24: left(); // 16 8 $ $ $
      break;
    default : straight();
  }
  delay(10);
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void loop() {
  // put your main code here, to run repeatedly:
  //labelx:
  if(ct<=2)
  {
  setline();
  }
}


