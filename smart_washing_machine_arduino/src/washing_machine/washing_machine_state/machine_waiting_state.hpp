
#ifndef _MachineWaitingState_H_
#define _MachineWaitingState_H_

#include "washing_machine_state.hpp"

class MachineWaitingState : public WashingMachineState {

private:
  void running_loop();
  void paused_loop();
public:
  using WashingMachineState::WashingMachineState;
  void setup();
  bool skip();

};

#endif