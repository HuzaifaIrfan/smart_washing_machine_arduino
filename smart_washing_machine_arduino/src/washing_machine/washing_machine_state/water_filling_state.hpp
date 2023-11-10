
#ifndef _WaterFillingState_H_
#define _WaterFillingState_H_

#include "washing_machine_state.hpp"

class WaterFillingState : public WashingMachineState {

private:
  void running_loop();
  void paused_loop();
  
public:
  using WashingMachineState::WashingMachineState;
  void setup();

};

#endif