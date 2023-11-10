

#include "washer_spinning_state.hpp"

void WasherSpinningState::setup()
{
}

void WasherSpinningState::running_loop()
{
}
void WasherSpinningState::paused_loop()
{
    washing_machine.stop();
}
