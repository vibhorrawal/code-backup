int s[5]={A0,A1,A2,A3,A4};
int i,ir[5],black=0,white=0,mid=500;
int motorl=6;
int motorr=10;
void setup() {
  // put your setup code here, to run once:
for(i=0;i<5;i++)  
{
  pinMode(s[i],INPUT);
}
pinMode(motorl,OUTPUT);
pinMode(motorr,OUTPUT);
//analogWrite(motorl,0);
//analogWrite(motorr,0);
Serial.begin(9600);
for(i=0;i<5;i++)
{
  ir[i]=analogRead(s[i]); 
 black+=ir[i]/5;
}
analogWrite(motorl,255);
analogWrite(motorr,255);
delay(1000);
analogWrite(motorl,0);
analogWrite(motorr,0);
delay(5000);
for(i=0;i<5;i++)
{
  ir[i]=analogRead(s[i]); 
 white+=ir[i]/5;
}
mid=(black+white)/2;
analogWrite(motorl,255);
analogWrite(motorr,255);
delay(1000);
analogWrite(motorl,0);
analogWrite(motorr,0);
delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
delay(100);
//label:

for(i=0;i<5;i++)
{
  ir[i]=analogRead(s[i]); 
 Serial.print(" ");
 Serial.println(ir[i]);
}
Serial.println(" ");
for(i=0;i<5;i++)
{
  if(ir[i]>mid)
  {
    ir[i]=1;
  }
  else
  {
    ir[i]=0;
  }
}
if(ir[2]==1 && ir[1]==1 && ir[0]==0 && ir[3]==0 && ir[4]==0)

{
  analogWrite(motorr,150);
  analogWrite(motorl,150);                                //STRAIGHT
}
else if(ir[2]==1 && ir[3]==1&& ir[4]==0 && ir[1]==0 && ir[0]==0)
{
  analogWrite(motorr,150);                               //STRAIGHT
  analogWrite(motorl,150);
}
else if(ir[2]==1 && ir[1]==0 && ir[0]==0 && ir[4]==0 && ir[3]==0)
{
  analogWrite(motorr,150);
  analogWrite(motorl,150);                               //STRAIGHT
}
//else if(ir[2]==1 && ir[3]==0)
//{
  //analogWrite(motorr,100);
  //analogWrite(motorl,100);                               //STRAIGHT
//}
else if(ir[4]==0 && ir[3]==0 && ir[2]==1 && ir[1]==1 && ir[0]==1)
{
  //do{
  analogWrite(motorl,0);
  analogWrite(motorr,100);
  delay(100);
  ir[0]=analogRead(s[0]);                               //LEFT
  ir[1]=analogRead(s[1]);
  ir[2]=analogRead(s[2]);
//}while(ir[2]==0);
}
else if(ir[4]==0 && ir[3]==1 && ir[2]==1 && ir[1]==1 && ir[0]==1)
{
  //do{
  analogWrite(motorl,0);
  analogWrite(motorr,100);
  delay(100);
  ir[0]=analogRead(s[0]);                               //LEFT
  ir[1]=analogRead(s[1]);
  ir[2]=analogRead(s[2]);
//}while(ir[2]==0);
}
else if(ir[3]==1 && ir[4]==1 &&ir[2]==1 && ir[1]==0 && ir[0]==0)
{
  //do{
    analogWrite(motorl,100);
  analogWrite(motorr,0);    //RIGHT
  delay(100);
  ir[4]=analogRead(s[4]);
  ir[3]=analogRead(s[3]);
  ir[2]=analogRead(s[2]);
//}while(ir[2]==0);
}
else if(ir[3]==1 && ir[4]==1 &&ir[2]==1 && ir[1]==1 && ir[0]==0)
{
  //do{
    analogWrite(motorl,100);
  analogWrite(motorr,0);    //RIGHT
  delay(100);
  ir[4]=analogRead(s[4]);
  ir[3]=analogRead(s[3]);
  ir[2]=analogRead(s[2]);
//}while(ir[2]==0);
}
else if(ir[2]==0 && ir[3]==0 && ir[4]==0 && ir[1]==0 && ir[0]==0)
{
  analogWrite(motorr,0);                               //STOP
  analogWrite(motorl,0);
}

}
