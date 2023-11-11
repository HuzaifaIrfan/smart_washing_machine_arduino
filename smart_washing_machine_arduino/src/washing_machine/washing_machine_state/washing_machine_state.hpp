

#ifndef _WashingMachineState_H_
#define _WashingMachineState_H_

#include <Arduino.h>

#include "washing_machine/washing_machine.hpp"

enum WASHING_MACHINE_STATES
{
  MACHINE_WAITING_STATE,
  WATER_FILLING_STATE,
  WASHER_SPINNING_STATE,
  CLOTHES_SOAKING_STATE,
  WATER_DRAINING_STATE,
  DRYER_STATE,
  ROUTINE_END_STATE
};

class WashingMachineState
{
protected:
  WashingMachine washing_machine;
  bool running_state = false;
  int count_down = 0;
  virtual void running_loop(){};
  virtual void paused_loop(){};

public:
  explicit WashingMachineState(WashingMachine washing_machine)
      : washing_machine(washing_machine) {}

  void run()
  {
    running_state = true;
  }
  void pause()
  {
    running_state = false;
  }

  virtual void setup(){};

  bool loop()
  {
    if (running_state)
    {
      running_loop();
      count_down = count_down - 1;
    }
    else
    {
      paused_loop();
    }
    return is_done();
  }

  bool is_done()
  {
    if(count_down <=0){
      return true;
    }
    return false;
  }

  virtual bool skip(){
    count_down=0;
    return true;
  }

};

#endif