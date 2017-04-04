#ifndef SonoffDual_h
#define SonoffDual_h

#include <Arduino.h>

enum class SonoffDualButton : uint8_t {
  NONE,
  SHORT,
  LONG
};

namespace SonoffDualInternal {
class SonoffDualClass {
 public:
  SonoffDualClass();
  void setup();
  ::SonoffDualButton handleButton();
  void setLed(bool on);
  void setRelays(bool first, bool second);

  const uint8_t LED_PIN = 13;
  const uint8_t LED_ON = LOW;
  const uint8_t LED_OFF = HIGH;
};
}

extern SonoffDualInternal::SonoffDualClass SonoffDual;

#endif
