

#include "water_draining_state.hpp"

void WaterDrainingState::setup()
{
}

void WaterDrainingState::running_loop()
{
        washing_machine.open_drain_valve();
}
void WaterDrainingState::paused_loop()
{
        washing_machine.stop();
}
