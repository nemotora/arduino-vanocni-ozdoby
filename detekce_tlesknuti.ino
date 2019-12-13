#define PIN_TLESKNUTI  2

void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  byte tlesknuti = digitalRead(PIN_TLESKNUTI);
  Serial.println(tlesknuti);
}
