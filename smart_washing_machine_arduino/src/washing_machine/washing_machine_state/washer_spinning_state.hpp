
#ifndef _WasherSpinningState_H_
#define _WasherSpinningState_H_

#include "washing_machine_state.hpp"

class WasherSpinningState : public WashingMachineState {


private:
  void running_loop();
  void paused_loop();

public:
  using WashingMachineState::WashingMachineState;
  void setup();

};

#endif