int r[4],g[4],b[4];
int i,k;
int cc=0;
int redc,greenc,bluec;
int ledR= 2,ledG= 4,ledB= 7,ldr=A5 ;
void readcolor()                                               // function to store colour order while linefollowing
{
  int cont;
  digitalWrite(ledR,HIGH);
  delay(20);
  r[cc]=(analogRead(ldr)+analogRead(ldr)+analogRead(ldr))/3;
  delay(100);
  Serial.print("  R=  ");
  Serial.print(r[cc]);
  digitalWrite(ledR,LOW);
  delay(100);
  digitalWrite(ledG,HIGH);
  delay(100);
  g[cc]=(analogRead(ldr)+analogRead(ldr)+analogRead(ldr))/3;
  delay(100);
  Serial.print("  G=  ");
  Serial.print(g[cc]);
  digitalWrite(ledG,LOW);
  delay(100);
  digitalWrite(ledB,HIGH);
  delay(100);
  b[cc]=(analogRead(ldr)+analogRead(ldr)+analogRead(ldr))/3;
  delay(100);
  Serial.print("  B=  ");
  Serial.print(b[cc]);
  digitalWrite(ledB,LOW);
  delay(100);
  /*for(cont=0;cont<cc;cont++)
  {
    if((r[cc]>=0.85*r[cont]&&r[cc]<=1.15*r[cont])&&(b[cc]>=0.85*b[cont] && b[cc]<=1.15*b[cont]) &&(g[cc]>=0.85*g[cont] && g[cc]<=1.15*g[cont]))
    {
      cc--;
      break;
    }
  }*/
  cc++;
}






void comparecolor()                                   // function to store color order of the stack
{
 digitalWrite(ledR,HIGH);
 delay(100);
  redc=(analogRead(ldr)+analogRead(ldr)+analogRead(ldr))/3;
  delay(100);
  digitalWrite(ledR,LOW);
  delay(100);
  digitalWrite(ledG,HIGH);
  delay(100);
  greenc=(analogRead(ldr)+analogRead(ldr)+analogRead(ldr))/3;
  delay(100);
  digitalWrite(ledG,LOW);
  delay(100);
  digitalWrite(ledB,HIGH);
  delay(100);
  bluec=(analogRead(ldr)+analogRead(ldr)+analogRead(ldr))/3;
  delay(100);
  digitalWrite(ledB,LOW);
  delay(100);
  for(i=0;i<3;i++)
    {
      if((redc<=1.15*r[i] && redc>=0.85*r[i]) && (bluec<=1.15*b[i] && bluec>=0.85*b[i]) && (greenc<=1.15*g[i] && greenc>=0.85*g[i]))
      {
        //rank[ctr]=i+1;
        //ctr++;
        Serial.println(i);
        break;
      }
    }
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(ledR,OUTPUT);
pinMode(ledB,OUTPUT);
pinMode(ledG,OUTPUT);
pinMode(ldr,INPUT);
for(k=0;k<3;k++)
{
  Serial.print("input colour ");
  Serial.print(k);
  delay(2000);
  readcolor();
  Serial.println("   done ");
  delay(2000);
}
}

void loop() {
  // put your main code here, to run repeatedly:
comparecolor();
delay(100);
Serial.println("*************");
}
