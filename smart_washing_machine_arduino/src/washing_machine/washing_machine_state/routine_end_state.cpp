

#include "routine_end_state.hpp"

void RoutineEndState::setup()
{
}

void RoutineEndState::running_loop()
{
    washing_machine.open_drain_valve();
}

void RoutineEndState::paused_loop()
{
    running_loop();
}

bool RoutineEndState::skip()
{
    return false;
}