//05 december 2017
//Code BY VIBHOR RAWAL
int s[6] = {A0, A1, A2, A3, A4, A5};

int lfmotor = 6;
int rfmotor = 10;
int bell = 12;

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

void loop() {


  switch (value()) {

    case 48: // 4 5
    case 120: // 3 4 5 6
      front();
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

}
