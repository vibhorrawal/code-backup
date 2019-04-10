int redLed = 2;
int blueLed = 5;
int greenLed = 3;
int input = A0;
int i, j = 0;
int trigPin = 10;
int echoPin = 9;
int variable3 = 0;
int red, green, blue;
int r[4], g[4], b[4];
long duration;
void setup() {
  Serial.begin(9600);
  pinMode(redLed, OUTPUT);
  digitalWrite(redLed,LOW);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(input, INPUT);
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void colorSense() {

  //blink same color led and some color led in black too
  digitalWrite(redLed, HIGH);
  delay(100);
  //Serial.print("r=");
  red = analogRead(input);
 // Serial.print(red);
  //Serial.print("  ");
  digitalWrite(redLed, LOW);
  delay(100);
  digitalWrite(greenLed, HIGH);
  delay(100);
  //Serial.print("g=");
  green = analogRead(input);
 // Serial.print(green);
  //Serial.print("  ");
  digitalWrite(greenLed, LOW);
  delay(100);

  digitalWrite(blueLed, HIGH);
  delay(100);
//  Serial.print("b=");
  blue = analogRead(input);
//  Serial.print(blue);

  //Serial.print("  ");
  digitalWrite(blueLed, LOW);
  delay(100);
  Serial.println(" ");
}

int colormatch()
{
  for (i = 1; i <= 3; i++) {
    if ((red > 0.85 * r[i-1] && red < 1.15 * r[i-1]) && (green > 0.85 * g[i-1] && green < 1.15 * g[i-1]) && (blue > 0.85 * b[i-1] && blue < 1.15 * b[i-1]))
      return i;
  }
  return 0;
}

void colorSave() {
  int t = 0;
  if (variable3 == 0)
  {
    r[0] = red;
    g[0] = green;
    b[0] = blue;
    variable3++;
    Serial.println("Color Saved");
  }
  else
  {
    for (i = variable3; i >= 0; i--)
    {
      if ((red > 0.85 * r[i] && red < 1.15 * r[i]) && (green > 0.85 * g[i] && green < 1.15 * g[i]) && (blue > 0.85 * b[i] && blue < 1.15 * b[i]))
        t = 1;
        else t=0;
    }
    if (t == 0)
    {
      r[variable3] = red;
      g[variable3] = green;
      b[variable3] = blue;
      variable3++;
      Serial.println("Color Saved");
    }
  }
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
void loop() {
  while (variable3 < 3) {
    if (distance() < 5) {
      colorSense();
      colorSave();
    }
  }
    Serial.println("\nALL COLORS ARE SAVED");
    while (1) {
      colorSense();
      Serial.println(colormatch());
      delay(300);
    }
  }
