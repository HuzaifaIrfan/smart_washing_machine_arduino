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

class WashingMachine
{
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
  void stop();

  // Inlet Valve Methods
  void open_inlet_valves();
  void open_hot_inlet_valve();
  void open_close_inlet_valve();
  void close_inlet_valves();

  // Drain Valve Methods
  void open_drain_valve();
  void close_drain_valve();

  // Spinner Methods
  void stop_spinner();
  void spin_spinner_clockwise();
  void spin_spinner_nti_clockwise();

  // Dryer Methods
  bool WashingMachine::open_dryer_drain();
  bool WashingMachine::spin_dryer();
  void WashingMachine::stop_dryer();
  bool WashingMachine::close_drain_and_brake_dryer();
  
};

extern WashingMachine washing_machine;

#endif