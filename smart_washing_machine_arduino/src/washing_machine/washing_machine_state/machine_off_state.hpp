
#ifndef _MachineOffState_H_
#define _MachineOffState_H_

#include "washing_machine_state.hpp"

class MachineOffState : public WashingMachineState {

private:
  void running_loop();
  void paused_loop();
public:
  using WashingMachineState::WashingMachineState;
  void setup();

};

#endif