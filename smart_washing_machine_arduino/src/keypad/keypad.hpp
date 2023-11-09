#ifndef KEYPAD_H
#define KEYPAD_H

#include <Arduino.h>
#include "display/display.hpp"

class Keypad {
  private:
    Display display;
  public:
    Keypad(Display display);
    void setup();
    void loop();
};

#endif