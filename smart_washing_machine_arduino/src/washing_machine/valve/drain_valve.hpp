#ifndef DRAINVALVE_H
#define DRAINVALVE_H

#include <Arduino.h>

#include "washing_machine/valve/relay/relay.hpp"

class DrainValve {
  public:
    DrainValve();
    void setup();
    void loop();
};

#endif