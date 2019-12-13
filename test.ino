#include <Adafruit_NeoPixel.h>
#include <ButtonDebounce.h>

#define PIN_BUZZER    3
#define PIN_BTN1      5
#define PIN_BTN2      10
#define PIN_TRESHOLD  2
#define PIN_MIC       A7
#define PIN_LED       6
#define NUM_LED       5

Adafruit_NeoPixel pixels(NUM_LED, PIN_LED, NEO_GRB + NEO_KHZ800);
ButtonDebounce tlacitko1(PIN_BTN1, 150);
ButtonDebounce tlacitko2(PIN_BTN2, 150);

unsigned int sound_offset = 0;
int sound = 0;
bool state = LOW;
unsigned long last = 0;
bool tick = LOW;
byte red = 0;
byte green = 0;
byte blue = 0;
byte r[NUM_LED];
byte add = -1;

void setup() {
  // nastaveni funkci jednotlivych pinu
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_BTN1, INPUT_PULLUP);
  pinMode(PIN_BTN2, INPUT_PULLUP);
  pinMode(PIN_TRESHOLD, INPUT);
  pinMode(13, OUTPUT);
  // zapnuti seriove linky (komunikace s PC)
  Serial.begin(9600);
  // zmereni urovne hluku v okoli
  sound_offset = analogRead(PIN_MIC);
  for (byte i = 0; i < 20; i++) {
    sound_offset = 0.9*sound_offset + 0.1*analogRead(PIN_MIC);
    delay(100);
  }
  Serial.print("Uroven hluku v okoli: ");
  Serial.println(sound_offset);
  // priprava LED svetel
  pixels.begin();
  // nastaveni tlacitek
  tlacitko1.setCallback(tlacitko1Stisknuto);
  tlacitko2.setCallback(tlacitko2Stisknuto);
  // potvrzeni konce nastavovani Arduina
  Serial.println("Spusteno!");
  tone(PIN_BUZZER, 440, 20);
  delay(200);
  tone(PIN_BUZZER, 440, 20);
}

void loop() {
  // ==========================
  // aktualizace stavu tlacitek
  // ==========================
  tlacitko1.update();
  tlacitko2.update();
  // ======================================
  // generator tiknuti kazdych 5 milisekund
  // ======================================
  unsigned long now = millis();
  if (now - last >= 5) {
    tick = HIGH;
    last = now;
  } else {
    tick = LOW;
  }
  // ===========================
  // provedeni prislusne operace
  // ===========================
  if (state) {
    if (tick) {
      if (red == 255 || red == 0) {
        add = -add;
      }
      red = red + add;
    }
    for (byte i = 0; i < NUM_LED; i++) {
      pixels.setPixelColor(i, pixels.Color(0, red, 0));
      pixels.show();
    }
  } else {
    red = 0;
    add = -1;
    pixels.clear();
    pixels.show();
  }
}

void tlacitko1Stisknuto(int stav) {
  if (!stav) {
    state = !state;
  }
}

void tlacitko2Stisknuto(int stav) {
  if (!stav) {
    state = !state;
  }
}
