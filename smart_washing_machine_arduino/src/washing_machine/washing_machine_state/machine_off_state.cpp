

#include "machine_off_state.hpp"


void MachineOffState::setup()
{
}

void MachineOffState::running_loop()
{
    washing_machine.stop();
}

void MachineOffState::paused_loop()
{
    running_loop();
}
