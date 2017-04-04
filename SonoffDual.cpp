#include "SonoffDual.h"

using namespace SonoffDualInternal;

SonoffDualClass::SonoffDualClass() {
}

void SonoffDualClass::setup() {
  Serial.begin(19200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  setRelays(false, false);
  setLed(false);
}

SonoffDualButton SonoffDualClass::handleButton() {
  if (Serial.available() >= 4) {
    uint8_t values[4] = {0, 0, 0, 0};
    values[0] = Serial.read();
    values[1] = Serial.read();
    values[2] = Serial.read();
    values[3] = Serial.read();
    if (values[0] != 0xA0 || values[3] != 0xA1) return SonoffDualButton::NONE;
    uint16_t buttonCode = (values[1] << 8) | values[2];
    if (buttonCode == 0xF500) {
      return SonoffDualButton::LONG;
    } else {
      return SonoffDualButton::SHORT;
    }
  }

  return SonoffDualButton::NONE;
}

void SonoffDualClass::setLed(bool on) {
  digitalWrite(LED_PIN, on ? LED_ON : LED_OFF);
}

void SonoffDualClass::setRelays(bool first, bool second) {
  uint8_t state = 0;

  state ^= ((first ? 1 : 0) << 0);
  state ^= ((second ? 1 : 0) << 1);

  Serial.write(0xA0);
  Serial.write(0x04);
  Serial.write(state);
  Serial.write(0xA1);
  Serial.flush();
}

SonoffDualClass SonoffDual;
