#ifndef DRYER_H
#define DRYER_H

#include <Arduino.h>

#include "washing_machine/valve/drain_valve.hpp"
#include "washing_machine/spinner/spinner.hpp"


class Dryer {
  private:
    DrainValve drain_valve;
    Spinner spinner;
  public:
    Dryer(DrainValve drain_valve, Spinner spinner);
    void setup();
    void loop();

    void open_drain();
    void close_drain_and_brake();
};

#endif