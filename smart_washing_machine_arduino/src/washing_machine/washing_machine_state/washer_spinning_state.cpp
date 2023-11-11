

#include "washer_spinning_state.hpp"

void WasherSpinningState::setup()
{
  setup(DEFAULT_COUNTDOWN);
}

void WasherSpinningState::setup(int tmp_count_down)
{
  count_down = validate(tmp_count_down, MAXIMUM_COUNTDOWN, MINIMUM_COUNTDOWN);

  spin_time = validate(DEFAULT_SPIN_TIME, MAXIMUM_SPIN_TIME, MINIMUM_SPIN_TIME);
  wait_time = validate(DEFAULT_WAIT_TIME, MAXIMUM_WAIT_TIME, MINIMUM_WAIT_TIME);

  toggle_spin();

  Serial.println(WASHING_MACHINE_STATES_LABEL[WASHER_SPINNING_STATE] + " countdown Set: " + String(count_down));
}

void WasherSpinningState::running_loop()
{
  washing_machine->close_drain_valve();
  washing_machine->close_inlet_valves();
  spin_loop();
}

void WasherSpinningState::paused_loop()
{
  washing_machine->stop();
}

void WasherSpinningState::spin_loop()
{
  spin_count_down = spin_count_down - 1;
  if (spin_count_down <= wait_time)
  {
    washing_machine->stop();
  }
  else
  {
    if (clockwise_spin_now)
    {
      washing_machine->spin_spinner_clockwise();
    }
    else
    {
      washing_machine->spin_spinner_anti_clockwise();
    }
  }
  if (spin_count_down <= 0)
  {
    toggle_spin();
  }
}

void WasherSpinningState::toggle_spin()
{
  clockwise_spin_now = not clockwise_spin_now;
  spin_count_down = spin_time + wait_time;
}
