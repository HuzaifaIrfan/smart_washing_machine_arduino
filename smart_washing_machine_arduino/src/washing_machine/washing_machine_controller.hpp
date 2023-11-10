#ifndef WASHINGMACHINECONTROLLER_H
#define WASHINGMACHINECONTROLLER_H

#include <Arduino.h>
#include "washing_machine/washing_machine.hpp"

#include "washing_machine_state/washing_machine_state.hpp"
#include "washing_machine_state/machine_off_state.hpp"
#include "washing_machine_state/water_filling_state.hpp"
#include "washing_machine_state/washer_spinning_state.hpp"
#include "washing_machine_state/water_draining_state.hpp"
#include "washing_machine_state/dryer_state.hpp"

class WashingMachineController
{

private:
  MachineOffState machine_off_state = MachineOffState(washing_machine);
  WaterFillingState water_filling_state = WaterFillingState(washing_machine);
  WasherSpinningState washer_spinning_state = WasherSpinningState(washing_machine);
  WaterDrainingState water_draining_state = WaterDrainingState(washing_machine);
  DryerState dryer_state = DryerState(washing_machine);

  WashingMachineState *washing_machine_states[5] = {
      &machine_off_state,
      &water_filling_state,
      &washer_spinning_state,
      &water_draining_state,
      &dryer_state};

  short current_state_index=MACHINE_OFF_STATE;
  short next_state_index=MACHINE_OFF_STATE;

public:
  WashingMachineController();
  void setup();
  void loop();
};

#endif