

#include "machine_waiting_state.hpp"

void MachineWaitingState::setup()
{
}

void MachineWaitingState::running_loop()
{
    washing_machine.stop();
}

void MachineWaitingState::paused_loop()
{
    running_loop();
}

bool MachineWaitingState::skip()
{
    return false;
}
