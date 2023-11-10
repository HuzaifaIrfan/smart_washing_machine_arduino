#ifndef WASHINGMACHINE_H
#define WASHINGMACHINE_H

#include <Arduino.h>

#include "washing_machine/GPIO_CONFIG.hpp"

#include "washing_machine/valve/inlet_valves.hpp"
#include "washing_machine/valve/drain_valve.hpp"

#include "washing_machine/spinner/spinner.hpp"
#include "washing_machine/dryer/dryer.hpp"

#include "washing_machine/lid/lid.hpp"
#include "washing_machine/water_level_sensor/water_level_sensor.hpp"



class WashingMachine {
  private:

    InletValves inlet_valves;
    DrainValve drain_valve;
    Spinner spinner;
    Dryer dryer;

    Lid lid;
    WaterLevelSensor water_level_sensor;

  public:
    WashingMachine(InletValves inlet_valves, DrainValve drain_valve, Spinner spinner, Dryer dryer, Lid lid, WaterLevelSensor water_level_sensor);
    void setup();
    void loop();
};


extern WashingMachine washing_machine;

#endif