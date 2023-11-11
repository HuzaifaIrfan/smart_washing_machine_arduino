
#ifndef _RoutineEndState_H_
#define _RoutineEndState_H_

#include "washing_machine_state.hpp"

class RoutineEndState : public WashingMachineState
{

private:
  void running_loop();
  void paused_loop();

public:
  using WashingMachineState::WashingMachineState;
  void setup();
  bool skip();
};

#endif