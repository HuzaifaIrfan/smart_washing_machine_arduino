


#include "water_filling_state.hpp"

void WaterFillingState::setup()
{
    setup(DEFAULT_COUNTDOWN);
}


void WaterFillingState::setup(int tmp_count_down)
  {
    count_down = validate(tmp_count_down);
  }

void WaterFillingState::running_loop()
{
    washing_machine.open_inlet_valves();
}
void WaterFillingState::paused_loop()
{
    washing_machine.stop();
}
