//09 NOVEMBER 2017
//Code BY VIBHOR RAWAL
int s[5] = {A0, A1, A2, A3, A4};

int lfmotor = 6;
int rfmotor = 10;
int bell = 12;

int avg[5];
int val[5];
int white[5];
int black[5];
int i;
int ir[5];
void setup() {

  //5V output pin
  pinMode( 2, OUTPUT );
  digitalWrite( 2, LOW );
  pinMode( lfmotor, OUTPUT );
  pinMode( rfmotor, OUTPUT );
  analogWrite(lfmotor, 0);
  analogWrite(rfmotor, 0);

  //calibration
  delay(1000);
  //digitalWrite(13, HIGH);
  value();
  for (i = 0; i < 5; i++)
  {
    white[i] = s[i];
  }
  digitalWrite(bell, HIGH);
  delay(300);
  digitalWrite(bell, LOW);
  //digitalWrite(13, LOW);
  delay(4000);

  //digitalWrite(13, HIGH);
  value();
  for (i = 0; i < 5; i++)
  {
    black[i] = s[i];
  }

  digitalWrite(bell, HIGH);
  delay(300);
  digitalWrite(bell, LOW);
  //digitalWrite(13, LOW);
  for (i = 0; i < 5; i++)
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

  for (i = 0; i < 5; i++)
  {
    ir[i] = s[i] > avg[i] ? 1 : 0;
  }

  return 1 * ir[0] + 2 * ir[1] + 4 * ir[2] + 8 * ir[3] + 16 * ir[4];
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
void loop() {


  switch (value()) {
    case 1:
      left();
      break;

    case 2:
      left();
      break;


    case 3:
      left();
      break;

    case 4:
      front();
      break;

    case 5:
      left();
      break;

    case 6:
      left();
      break;

    case 7:
      left();
      break;

    case 8:
      right();
      break;

    case 9:
      right();
      break;

    case 10:
      front();
      break;

    case 11:
      left();
      break;

    case 12:
      right();
      break;

    case 13:
      right();
      break;

    case 14:
      front();
      break;

    case 15:
      left();
      break;

    case 16:
      right();
      break;

    case 17:
      front();
      break;

    case 18:
      front();
      break;

    case 19:
      left();
      break;

    case 20:
      right();
      break;

    case 21:
      front();
      break;

    case 22:
      left();
      break;

    case 23:
      left();
      break;

    case 24:
      right();
      break;

    case 25:
      right();
      break;

    case 26:
      right();
      break;

    case 27:
      front();
      break;

    case 28:
      right();
      break;

    case 29:
      right();
      break;

    case 30:
      right();
      break;

    case 31:
      left();
      break;

    default:
      rotate();
  }
}
