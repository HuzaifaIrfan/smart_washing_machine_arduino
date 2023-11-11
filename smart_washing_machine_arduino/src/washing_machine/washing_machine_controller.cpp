
#include "washing_machine_controller.hpp"

WashingMachineController::WashingMachineController()
{
}

void WashingMachineController::setup()
{
  washing_machine.setup();
  reset();
}

void WashingMachineController::loop()
{
  if (current_routine_state_pointer < 15)
  {
    if (washing_machine_states[current_state_index]->loop())
    {
      next_routine_state();
    }
  }
  display.display_current_routine(machine_routine, current_routine_state_pointer);
}

void WashingMachineController::next_routine_state()
{
  current_routine_state_pointer = current_routine_state_pointer + 1;
  current_state_index = machine_routine[current_routine_state_pointer];
  setup_next_state();
}

void WashingMachineController::reset()
{
  current_routine_state_pointer = 0;
  current_state_index = machine_routine[current_routine_state_pointer];
  setup_next_state();
  pause();
}

void WashingMachineController::setup_next_state()
{
  washing_machine_states[current_state_index]->setup();
  run();
  // Serial.println("Next State: " + String(WASHING_MACHINE_STATES_LABEL[current_state_index]));
}

void WashingMachineController::run()
{
  washing_machine_states[current_state_index]->run();
}

void WashingMachineController::pause()
{
  washing_machine_states[current_state_index]->pause();
}

void WashingMachineController::hold()
{
  washing_machine_states[current_state_index]->hold();
}

void WashingMachineController::skip()
{
  washing_machine_states[current_state_index]->skip();
}

WashingMachineController washing_machine_controller;
