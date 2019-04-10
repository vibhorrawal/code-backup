int gripperDown = 11;
int gripperUp = 10;
void setup() {
  // put your setup code here, to run once:
  pinMode(gripperDown, OUTPUT);
  pinMode(gripperUp, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
int n=1;
if(n==1)
{
  digitalWrite(gripperUp, HIGH);
  digitalWrite(gripperDown, LOW);
}
 else {
  digitalWrite(gripperDown, HIGH);
  digitalWrite(gripperUp, LOW);
 }
}

