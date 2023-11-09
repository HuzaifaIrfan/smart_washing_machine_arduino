#ifndef INLETVALVE_H
#define INLETVALVE_H

#include <Arduino.h>

#include "washing_machine/valve/relay/relay.hpp"

class InletValve {
  public:
    InletValve();
    void setup();
    void loop();
};

#endif