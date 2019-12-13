#include <Adafruit_NeoPixel.h>

#define PIN_LED       6
#define POCET_LED     8

Adafruit_NeoPixel svetylka(POCET_LED, PIN_LED, NEO_GRB + NEO_KHZ800);

void setup() {
  svetylka.begin();
  svetylka.fill(svetylka.Color(255, 0, 255));
  svetylka.setBrightness(15);
  svetylka.show();
  delay(2000);
}

void loop() {
  svetylka.fill(svetylka.Color(255, 0, 0), 0, 2);
  svetylka.fill(svetylka.Color(0, 255, 0), 2, 2);
  svetylka.fill(svetylka.Color(0, 0, 255), 4, 2);
  svetylka.fill(svetylka.Color(255, 0, 255), 6, 2);
  svetylka.show();
  delay(2000);
  svetylka.fill(svetylka.Color(0, 255, 0));
  svetylka.show();
  delay(2000);
  for (int i = 0; i < svetylka.numPixels(); i++) {
    svetylka.clear();
    svetylka.setPixelColor(i, svetylka.Color(0, 0, 255));
    svetylka.show();
    delay(100);
  }
  for (int i = svetylka.numPixels() - 2; i >= 0; i--) {
    svetylka.clear();
    svetylka.setPixelColor(i, svetylka.Color(0, 0, 255));
    svetylka.show();
    delay(100);
  }
  delay(2000);
}
