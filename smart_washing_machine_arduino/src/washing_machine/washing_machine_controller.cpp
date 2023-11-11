
#include "washing_machine_controller.hpp"

WashingMachineController::WashingMachineController()
{
}

void WashingMachineController::setup()
{
  washing_machine.setup();
  // for (auto &washing_machine_state : washing_machine_states) {
  //   washing_machine_state->setup();
  // }
  setup_next_state();
}

void WashingMachineController::loop()
{

  if (washing_machine_states[current_state_index]->loop())
  {
    next_routine_state();
  }
  display.display_current_routine(machine_routine, machine_routine_size, current_routine_state_pointer);
}

void WashingMachineController::next_routine_state()
{
  if (current_routine_state_pointer < 10)
  {
    current_routine_state_pointer = current_routine_state_pointer + 1;
    current_state_index = machine_routine[current_routine_state_pointer];
    setup_next_state();
  }
}

void WashingMachineController::setup_next_state()
{
  washing_machine_states[current_state_index]->setup();
  washing_machine_states[current_state_index]->run();
  // Serial.println("Next State: " + String(WASHING_MACHINE_STATES_LABEL[current_state_index]));
}

WashingMachineController washing_machine_controller;
