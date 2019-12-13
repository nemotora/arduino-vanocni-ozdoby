#define PIN_BZUCAK    3

int tempo = 150;
char noty[] = "eeeeeeegcde fffffeeeeddedg";
int delka[] = {1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};

void prehrajNotu(char nota, int delka) {
  char nazvy_not[] = { 'c', 'd', 'e', 'f', 'g' };
  int tony[] = { 261, 293, 329, 349, 392 };
  for (int i = 0; i < sizeof(tony); i++) {
    if (nota == nazvy_not[i]) {
      tone(PIN_BZUCAK, tony[i], delka);
    }
  }
}

void setup() {
  pinMode(PIN_BZUCAK, OUTPUT);
}

void loop() {
  for (int i = 0; i < sizeof(noty)-1; i++) {
    if (noty[i] == ' ') {
      delay(delka[i] * tempo);
    } else {
      prehrajNotu(noty[i], delka[i] * tempo);
    }
    delay((tempo*2)*delka[i]);
  }
}
