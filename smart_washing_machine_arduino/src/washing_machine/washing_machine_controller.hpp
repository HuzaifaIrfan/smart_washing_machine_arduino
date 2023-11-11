#ifndef WASHINGMACHINECONTROLLER_H
#define WASHINGMACHINECONTROLLER_H

#include <Arduino.h>

#include "output/display/display.hpp"

#include "washing_machine/washing_machine.hpp"

#include "washing_machine_state/washing_machine_state.hpp"

#include "washing_machine_state/machine_waiting_state.hpp"
#include "washing_machine_state/water_filling_state.hpp"
#include "washing_machine_state/washer_spinning_state.hpp"
#include "washing_machine_state/clothes_soaking_state.hpp"
#include "washing_machine_state/water_draining_state.hpp"
#include "washing_machine_state/dryer_state.hpp"
#include "washing_machine_state/routine_end_state.hpp"

enum WASHING_MACHINE_STATES
{
  MACHINE_WAITING_STATE,
  WATER_FILLING_STATE,
  WASHER_SPINNING_STATE,
  CLOTHES_SOAKING_STATE,
  WATER_DRAINING_STATE,
  DRYER_STATE,
  ROUTINE_END_STATE
};

class WashingMachineController
{

private:
  MachineWaitingState machine_waiting_state = MachineWaitingState(&washing_machine);
  WaterFillingState water_filling_state = WaterFillingState(&washing_machine);
  WasherSpinningState washer_spinning_state = WasherSpinningState(&washing_machine);
  ClothesSoakingState clothes_soaking_state = ClothesSoakingState(&washing_machine);
  WaterDrainingState water_draining_state = WaterDrainingState(&washing_machine);
  DryerState dryer_state = DryerState(&washing_machine);
  RoutineEndState routine_end_state = RoutineEndState(&washing_machine);

  WashingMachineState *washing_machine_states[7] = {
      &machine_waiting_state,
      &water_filling_state,
      &washer_spinning_state,
      &clothes_soaking_state,
      &water_draining_state,
      &dryer_state,
      &routine_end_state};

  short current_state_index = MACHINE_WAITING_STATE;

  short machine_routine[10] = {
      MACHINE_WAITING_STATE,
      WATER_FILLING_STATE,
      WASHER_SPINNING_STATE,
      CLOTHES_SOAKING_STATE,
      WATER_DRAINING_STATE,
      DRYER_STATE,
      ROUTINE_END_STATE,
      MACHINE_WAITING_STATE,
      MACHINE_WAITING_STATE,
      MACHINE_WAITING_STATE};

  short machine_routine_size = sizeof(machine_routine) / sizeof(machine_routine[0]);

  short current_routine_state_pointer = 0;

  void next_routine_state();

public:
  WashingMachineController();
  void setup();
  void loop();
};

extern WashingMachineController washing_machine_controller;

#endif