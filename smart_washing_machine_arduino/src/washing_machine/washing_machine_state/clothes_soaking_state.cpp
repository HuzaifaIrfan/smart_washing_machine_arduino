

#include "clothes_soaking_state.hpp"




void ClothesSoakingState::setup()
{
    setup(DEFAULT_COUNTDOWN);
}

void ClothesSoakingState::setup(int tmp_count_down)
  {
    count_down = validate(tmp_count_down);
  }


void ClothesSoakingState::running_loop()
{
    washing_machine->stop();
}

void ClothesSoakingState::paused_loop()
{
    running_loop();
}
