

#ifndef _WashingMachineState_H_
#define _WashingMachineState_H_


#include <Arduino.h>

#include "washing_machine/washing_machine.hpp"

enum WASHING_MACHINE_STATES
{
  MACHINE_OFF_STATE,
  WATER_FILLING_STATE,
  WASHER_SPINNING_STATE,
  WATER_DRAINING_STATE,
  DRYER_STATE
};


class WashingMachineState {
protected:
  WashingMachine washing_machine;
  bool running_state = false;
  virtual void running_loop(){};
  virtual void paused_loop(){};
public:
  explicit WashingMachineState(WashingMachine washing_machine)
    : washing_machine(washing_machine) {}

  void run(){
    running_state=true;
  }
  void pause(){
    running_state=false;
  }
  
  virtual void setup(){};

  void loop(){
    if(running_state){
      running_loop();
    }else{
      paused_loop();
    }
  }



};

#endif