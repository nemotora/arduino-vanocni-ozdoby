#define PIN_MIKROFON  A7

void setup() {
  Serial.begin(9600);
}

void loop() {
  int hlasitost = analogRead(PIN_MIKROFON);
  Serial.println(hlasitost);
}
