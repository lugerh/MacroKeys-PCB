// --- main.ino ---
#include <BleKeyboard.h> // https://github.com/T-vK/ESP32-BLE-Keyboard
#include "pinWatcher.h"
#include "keycodes_letters.h"

#define LED 2

#define ROWS 3
#define COLS 5

uint8_t pin_rows[ROWS] = {13, 18, 19};
uint8_t pin_cols[COLS] = {12, 14, 27, 26, 25};

BleKeyboard bleKeyboard("MacroPad", "ZMS", 69);

TeclaBLE* teclas[ROWS][COLS];

void setup() {
  Serial.begin(115200);
  bleKeyboard.begin();
  IOinit();

  // Fila 0
  // teclas[0][0] = new TeclaBLE(KEY_LEFT_ALT, true);
  // teclas[0][1] = new TeclaBLE(KEY_F1);
  // teclas[0][2] = new TeclaBLE(KEY_F2);
  teclas[0][0] = new TeclaBLE(KEY_V);
  teclas[0][1] = new TeclaBLE(KEY_C);
  teclas[0][2] = new TeclaBLE(KEY_LEFT_CTRL, true);
  teclas[0][3] = new TeclaBLE(KEY_F3);
  teclas[0][4] = new TeclaBLE(KEY_F4);

  // Fila 1
  teclas[1][0] = new TeclaBLE(KEY_LEFT_SHIFT, true);
  teclas[1][1] = new TeclaBLE(KEY_F5);
  teclas[1][2] = new TeclaBLE(KEY_F6);
  teclas[1][3] = new TeclaBLE(KEY_F7);
  teclas[1][4] = new TeclaBLE(KEY_F8);

  // Fila 2
  teclas[2][0] = new TeclaBLE(KEY_LEFT_CTRL, true);
  teclas[2][1] = new TeclaBLE(KEY_F9);
  teclas[2][2] = new TeclaBLE(KEY_F10);
  teclas[2][3] = new TeclaBLE(KEY_F11);
  teclas[2][4] = new TeclaBLE(KEY_F12);
}

void loop() {
  if (bleKeyboard.isConnected()) {
    IOupdate();
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
  delay(1);
}

void IOinit() {
  for (uint8_t r = 0; r < ROWS; r++) {
    pinMode(pin_rows[r], OUTPUT);
    digitalWrite(pin_rows[r], HIGH);
  }

  for (uint8_t c = 0; c < COLS; c++) {
    pinMode(pin_cols[c], INPUT_PULLUP);
  }
}

void IOupdate() {
  for (uint8_t r = 0; r < ROWS; r++) {
    digitalWrite(pin_rows[r], LOW);
    delayMicroseconds(5);

    for (uint8_t c = 0; c < COLS; c++) {
      bool pressed = digitalRead(pin_cols[c]) == LOW;
      teclas[r][c]->update(pressed);
    }

    digitalWrite(pin_rows[r], HIGH);
  }
}
