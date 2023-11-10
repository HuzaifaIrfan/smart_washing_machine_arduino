
#include "washing_machine_controller.hpp"


WashingMachineController::WashingMachineController()
{
}

void WashingMachineController::setup()
{
  washing_machine.setup();
  for (auto &washing_machine_state : washing_machine_states) {
    washing_machine_state->setup();
  }
  washing_machine_states[current_state_index]->run();
}

void WashingMachineController::loop()
{
  if(current_state_index == next_state_index){
    washing_machine_states[current_state_index]->loop();
  }
}


WashingMachineController washing_machine_controller;
