
#ifndef _WasherSpinningState_H_
#define _WasherSpinningState_H_

#include "washing_machine_state.hpp"

class WasherSpinningState : public WashingMachineState
{

private:
  void running_loop();
  void paused_loop();

  int MAXIMUM_COUNTDOWN = 600;
  int DEFAULT_COUNTDOWN = 300;
  int MINIMUM_COUNTDOWN = 30;

public:
  using WashingMachineState::WashingMachineState;
  void setup();
  void setup(int tmp_count_down);
};

#endif