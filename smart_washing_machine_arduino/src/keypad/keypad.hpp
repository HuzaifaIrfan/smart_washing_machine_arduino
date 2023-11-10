#ifndef KEYPAD_H
#define KEYPAD_H

#include <Arduino.h>

#include "display/display.hpp"
#include "washing_machine/washing_machine_controller.hpp"

class Keypad {
  private:
    Display display;
    WashingMachineController washing_machine_controller;
  public:
    Keypad(Display display, WashingMachineController washing_machine_controller);
    void setup();
    void loop();
};

extern Keypad keypad;
#endif