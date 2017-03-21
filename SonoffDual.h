#ifndef SonoffDual_h
#define SonoffDual_h

#include <Arduino.h>

enum class SonoffDualButton : uint8_t {
  NONE,
  SHORT,
  LONG
};

namespace SonoffDualInternal {
const uint8_t LED_PIN = 13;

class SonoffDualClass {
 public:
  SonoffDualClass();
  void setup();
  ::SonoffDualButton handleButton();
  void setLed(bool on);
  void setRelays(bool first, bool second);
};
}

extern SonoffDualInternal::SonoffDualClass SonoffDual;

#endif
