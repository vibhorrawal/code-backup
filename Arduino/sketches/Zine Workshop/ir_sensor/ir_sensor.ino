#define threshold 500

// defines pin numbers
#define ir_re A0
#define ledPin 3

// Defining functions
void ledOn() {
  digitalWrite(ledPin, HIGH); // Turning LED ON
}

void ledOff() {
  digitalWrite(ledPin, LOW); // Turning LED OFF
}

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  int value;

  // Reading the analog input
  value = analogRead(ir_re);
  Serial.println(value);

  // Comparing with a Threshold
  if (value > threshold)
    ledOn();
  else
    ledOff();

   delay(100); 
}
