

#include "machine_waiting_state.hpp"

void MachineWaitingState::setup()
{
    setup(DEFAULT_COUNTDOWN);
}


void MachineWaitingState::setup(int tmp_count_down)
  {
    count_down = validate(tmp_count_down);
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
