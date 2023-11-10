#ifndef POWERRELAY_H
#define POWERRELAY_H

#include <Arduino.h>

class PowerRelay {
  private:
    short pin;
  public:
    PowerRelay(short pin);
    void setup();
    void loop();
    void on();
    void off();
};

#endif