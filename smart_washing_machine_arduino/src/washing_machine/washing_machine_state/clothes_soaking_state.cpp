

#include "clothes_soaking_state.hpp"


void ClothesSoakingState::setup()
{
}

void ClothesSoakingState::running_loop()
{
    washing_machine.stop();
}

void ClothesSoakingState::paused_loop()
{
    running_loop();
}
