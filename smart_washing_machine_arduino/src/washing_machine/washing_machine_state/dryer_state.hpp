
#ifndef _DryerState_H_
#define _DryerState_H_

#include "washing_machine_state.hpp"

class DryerState : public WashingMachineState {


private:
  void running_loop();
  void paused_loop();

public:
  using WashingMachineState::WashingMachineState;
  void setup();

};

#endif