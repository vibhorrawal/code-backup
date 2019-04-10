#include <SoftwareSerial.h>
SoftwareSerial mySerial(0,1);
    char data;
    
//motors
#define lmotor 3
#define rmotor 9
#define lbmotor 5
#define rbmotor 6

//speeds
#define HSPEED 255
#define SPEED 200
void setup() {

  Serial.begin(9600);
  pinMode(lmotor, OUTPUT);
  pinMode(rmotor, OUTPUT);
  pinMode(lbmotor, OUTPUT);
  pinMode(rbmotor, OUTPUT);

  analogWrite(lmotor, 0);
  analogWrite(rmotor, 0);
  analogWrite(lbmotor, 0);
  analogWrite(rbmotor, 0);

  while(!Serial);
  mySerial.begin(4800);
  mySerial.println("Connected");

}

void loop() {

  if (mySerial.available())
  {

    data = mySerial.read();
    Serial.write(data);

    switch (data)
    {
      case '1':
        analogWrite(lmotor, HSPEED);
        analogWrite(rmotor, HSPEED);
        analogWrite(lbmotor, 0);
        analogWrite(rbmotor, 0);
        Serial.println("Forward");
        break;

      case '2':
        analogWrite(lmotor, 0);
        analogWrite(rmotor, 0);
        analogWrite(lbmotor, SPEED);
        analogWrite(rbmotor, SPEED);
        break;

      case '3':
        analogWrite(lmotor, 0);
        analogWrite(rmotor, SPEED);
        analogWrite(lbmotor, 0);
        analogWrite(rbmotor, 0);
        break;

      case '4':
        analogWrite(lmotor, SPEED);
        analogWrite(rmotor, 0);
        analogWrite(lbmotor, 0);
        analogWrite(rbmotor, 0);
        break;

      case '6':
        analogWrite(lmotor, 0);
        analogWrite(rmotor, 0);
        analogWrite(lbmotor, 0);
        analogWrite(rbmotor, 0);
        Serial.println("Default");
    }
    delay(100);
  }
}



