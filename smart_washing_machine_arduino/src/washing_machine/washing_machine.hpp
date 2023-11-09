#ifndef WASHINGMACHINE_H
#define WASHINGMACHINE_H

#include <Arduino.h>

#include "washing_machine/valve/inlet_valve.hpp"
#include "washing_machine/valve/drain_valve.hpp"

#include "washing_machine/spinner/spinner.hpp"
#include "washing_machine/dryer/dryer.hpp"

#include "washing_machine/lid/lid.hpp"
#include "washing_machine/water_level_sensor/water_level_sensor.hpp"


class WashingMachine {
  public:
    WashingMachine();
    void setup();
    void loop();
};

#endif