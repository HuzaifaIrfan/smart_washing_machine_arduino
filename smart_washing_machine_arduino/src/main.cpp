#include <Arduino.h>

#include "display/display.hpp"
Display display;

#include "keypad/keypad.hpp"
Keypad keypad(display);

#include "washing_machine/washing_machine_controller.hpp"

WashingMachineController washing_machine_controller;

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
