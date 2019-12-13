#define PIN_TLACITKO1 5
#define PIN_TLACITKO2 10
#define PIN_BZUCAK    3

void setup() {
  Serial.begin(9600);
  pinMode(PIN_TLACITKO1, INPUT_PULLUP);
  pinMode(PIN_TLACITKO2, INPUT_PULLUP);
  pinMode(PIN_BZUCAK, OUTPUT);
}

void loop() {
  bool stav1 = digitalRead(PIN_TLACITKO1);
  bool stav2 = digitalRead(PIN_TLACITKO2);
  if (stav1 == LOW && stav2 == HIGH) {
    tone(PIN_BZUCAK, 440, 50);
  }
  if (stav1 == HIGH && stav2 == LOW) {
    tone(PIN_BZUCAK, 587, 50);
  }
}
