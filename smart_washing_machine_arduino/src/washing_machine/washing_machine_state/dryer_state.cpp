


#include "dryer_state.hpp"


void DryerState::setup()
{
    setup(DEFAULT_COUNTDOWN);
}

void DryerState::setup(int tmp_count_down)
  {
    count_down = validate(tmp_count_down);
  }

void DryerState::running_loop()
{
}
void DryerState::paused_loop()
{
        washing_machine.stop_dryer();
}
