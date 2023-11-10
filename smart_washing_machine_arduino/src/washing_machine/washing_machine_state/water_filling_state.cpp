


#include "water_filling_state.hpp"

void WaterFillingState::setup()
{
}

void WaterFillingState::running_loop()
{
    washing_machine.open_inlet_valves();
}
void WaterFillingState::paused_loop()
{
    washing_machine.stop();
}
