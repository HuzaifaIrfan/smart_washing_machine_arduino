

#ifndef _WashingMachineState_H_
#define _WashingMachineState_H_

#include <Arduino.h>

#include "output/LABELS.hpp"
#include "output/display/display.hpp"
#include "washing_machine/washing_machine.hpp"


class WashingMachineState
{
protected:
  WashingMachine *washing_machine = nullptr;
  bool running_state = false;
  int count_down = 0;

  int DEFAULT_COUNTDOWN = 5;
  int MAXIMUM_COUNTDOWN = 5;
  int MINIMUM_COUNTDOWN = 5;

  virtual void running_loop(){};
  virtual void paused_loop(){};

public:
  explicit WashingMachineState(WashingMachine *washing_machine)
      : washing_machine(washing_machine) {}

  void run()
  {
    running_state = true;
  }
  void pause()
  {
    running_state = false;
  }

  int validate(short tmp_count_down, int maximum_count_down, int minimum_count_down)
  {
    if (tmp_count_down > maximum_count_down)
    {
      return maximum_count_down;
    }

    if (tmp_count_down < minimum_count_down)
    {
      return minimum_count_down;
    }

    return tmp_count_down;
  }

  virtual void setup()
  {
  }

  virtual void setup(int tmp_count_down)
  {
    count_down = validate(tmp_count_down, MAXIMUM_COUNTDOWN, MINIMUM_COUNTDOWN);
  }



  bool loop()
  {
    if (running_state)
    {
      running_loop();
      count_down = count_down - 1;
      display.display_count_down(count_down);
      Serial.println(count_down);
    }
    else
    {
      paused_loop();
    }
    return is_done();
  }

  bool is_done()
  {
    if (count_down <= 0)
    {
      pause();
      return true;
    }
    return false;
  }

  void hold()
  {
    running_loop();
  }

  virtual bool skip()
  {
    count_down = 0;
    return true;
  }
};

#endif