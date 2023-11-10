

#ifndef _WashingMachineState_H_
#define _WashingMachineState_H_


#include <Arduino.h>

#include "washing_machine/washing_machine.hpp"

enum WASHING_MACHINE_STATES
{
  MACHINE_OFF_STATE,
  WATER_FILLING_STATE,
  WASHER_SPINNING_STATE,
  WATER_DRAINING_STATE,
  DRYER_STATE
};


class WashingMachineState {
protected:
  WashingMachine washing_machine;
public:
  explicit WashingMachineState(WashingMachine washing_machine)
    : washing_machine(washing_machine) {}

};

#endif