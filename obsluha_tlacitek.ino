#include <ButtonDebounce.h>

#define PIN_TLACITKO1 5
#define PIN_TLACITKO2 10

ButtonDebounce tlacitko1(PIN_TLACITKO1, 150);
ButtonDebounce tlacitko2(PIN_TLACITKO2, 150);

int cislo = 0;

void setup() {
  Serial.begin(9600);
  tlacitko1.setCallback(tlacitko1Stisknuto);
  tlacitko2.setCallback(tlacitko2Stisknuto);
}

void loop() {
  tlacitko1.update();
  tlacitko2.update();
}

void tlacitko1Stisknuto(int stav) {
  if (!stav) {
    cislo++;
    Serial.println(cislo);
  }
}

void tlacitko2Stisknuto(int stav) {
  if (!stav) {
    cislo--;
    Serial.println(cislo);
  }
}
