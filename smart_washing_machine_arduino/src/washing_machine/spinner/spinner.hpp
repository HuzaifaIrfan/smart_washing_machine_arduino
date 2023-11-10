#ifndef SPINNER_H
#define SPINNER_H

#include <Arduino.h>

#include "washing_machine/spinner/power_relay/power_relay.hpp"

enum SPINNER_STATES
{
  SPINNER_OFF_STATE,
  SPINNER_CW_SPIN_STATE,
  SPINNER_ACW_SPIN_STATE
};

class Spinner
{
private:
  PowerRelay clockwise_spinner_power_relay;
  PowerRelay anticlockwise_spinner_power_relay;
  short spin_state = SPINNER_OFF_STATE;

public:
  Spinner(PowerRelay clockwise_spinner_power_relay, PowerRelay anticlockwise_spinner_power_relay);
  void setup();
  void loop();
  void stop();

  void spin_clockwise();
  void spin_anti_clockwise();
  void spin_dryer();
  short return_spin_state();

  bool is_off();
  bool is_spin_cw();
  bool is_spin_acw();
};

#endif