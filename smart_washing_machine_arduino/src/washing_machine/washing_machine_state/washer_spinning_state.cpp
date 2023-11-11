

#include "washer_spinning_state.hpp"

void WasherSpinningState::setup()
{
    setup(DEFAULT_COUNTDOWN);
}

void WasherSpinningState::setup(int tmp_count_down)
  {
    count_down = validate(tmp_count_down, MAXIMUM_COUNTDOWN, MINIMUM_COUNTDOWN);
Serial.println(WASHING_MACHINE_STATES_LABEL[WASHER_SPINNING_STATE]+" countdown Set: "+ String(count_down));
  }

void WasherSpinningState::running_loop()
{

}

void WasherSpinningState::paused_loop()
{
    washing_machine->stop();
}
