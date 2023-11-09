#include <Arduino.h>

#include "display/display.hpp"
Display display;

#include "keypad/keypad.hpp"
Keypad keypad(display);

void setup()
{
  Serial.begin(9600);
  display.setup();
  keypad.setup();
}

void loop()
{
  keypad.loop();
}
