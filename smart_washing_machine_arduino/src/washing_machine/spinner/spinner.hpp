#ifndef SPINNER_H
#define SPINNER_H

#include <Arduino.h>

#include "washing_machine/spinner/power_relay/power_relay.hpp"

class Spinner {
  public:
    Spinner();
    void setup();
    void loop();
};

#endif