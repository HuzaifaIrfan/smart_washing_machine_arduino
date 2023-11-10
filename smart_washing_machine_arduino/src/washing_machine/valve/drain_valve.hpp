#ifndef DRAINVALVE_H
#define DRAINVALVE_H

#include <Arduino.h>

#include "washing_machine/valve/relay/relay.hpp"



class DrainValve {
  private:
    Relay water_drain_valve_relay;
  public:
    DrainValve(Relay water_drain_valve_relay);
    void setup();
    void loop();
    void open();
    void close();
    bool return_state();
    bool is_open();
};

#endif