

#include "routine_end_state.hpp"

void RoutineEndState::setup()
{
    setup(DEFAULT_COUNTDOWN, 10);
}

void RoutineEndState::setup(int tmp_count_down)
  {
    setup(tmp_count_down, 10);
  }


void RoutineEndState::setup(int tmp_count_down, short beep_count)
{
    buzzer.set(beep_count);
    count_down=validate(tmp_count_down);
}


void RoutineEndState::running_loop()
{
    washing_machine->open_drain_valve();
}

void RoutineEndState::paused_loop()
{
    running_loop();
}

bool RoutineEndState::skip()
{
    return false;
}