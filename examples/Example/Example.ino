#include <SonoffDual.h>

void setup() {
  SonoffDual.setup();
}

bool state = false;

void loop() {
  SonoffDualButton buttonState = SonoffDual.handleButton();
  if (buttonState == SonoffDualButton::NONE) return;

  state = !state;

  SonoffDual.setLed(state);
  SonoffDual.setRelays(state, state);
}
