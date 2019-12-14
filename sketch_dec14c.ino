#include <Adafruit_NeoPixel.h>

#define PIN_LED       6
#define POCET_LED     8

Adafruit_NeoPixel svetylka(POCET_LED, PIN_LED, NEO_RGB + NEO_KHZ800);

byte cervena = 0;
byte rezim = 0;

void setup() {
  svetylka.begin();
  svetylka.setBrightness(63);
  svetylka.fill(svetylka.Color(0, 0, 255));
  svetylka.show();
}

void loop() {
  if (rezim == 1) {
    svetylka.fill(svetylka.Color(cervena, 52, 189));
    svetylka.show();
    cervena = cervena + 1;
    delay(20);
  }
  if (rezim == 2) {
    svetylka.fill(svetylka.Color(random(255), random(255), random(255)));
    svetylka.show();
    delay(100);
  }
}
