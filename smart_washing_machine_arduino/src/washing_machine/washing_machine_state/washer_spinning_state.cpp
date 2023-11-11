

#include "washer_spinning_state.hpp"

void WasherSpinningState::setup()
{
    setup(DEFAULT_COUNTDOWN);
}

void WasherSpinningState::setup(int tmp_count_down)
  {
    count_down = validate(tmp_count_down);
  }

void WasherSpinningState::running_loop()
{

}

void WasherSpinningState::paused_loop()
{
    washing_machine->stop();
}
