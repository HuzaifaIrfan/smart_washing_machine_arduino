#ifndef SPINNER_H
#define SPINNER_H

#include <Arduino.h>

#include "washing_machine/spinner/power_relay/power_relay.hpp"



class Spinner {
  private:
    PowerRelay clockwise_spinner_power_relay;
    PowerRelay anticlockwise_spinner_power_relay;
  public:
    Spinner(PowerRelay clockwise_spinner_power_relay, PowerRelay anticlockwise_spinner_power_relay);
    void setup();
    void loop();
    void stop();

    void spin_clockwise();
    void spin_anti_clockwise();
    void spin_dryer();
};

#endif