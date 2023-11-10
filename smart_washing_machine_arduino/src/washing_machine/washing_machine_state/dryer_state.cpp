


#include "dryer_state.hpp"


void DryerState::setup()
{
}

void DryerState::running_loop()
{
}
void DryerState::paused_loop()
{
        washing_machine.stop();
}
