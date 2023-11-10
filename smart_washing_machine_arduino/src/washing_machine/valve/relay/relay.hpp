#ifndef RELAY_H
#define RELAY_H

#include <Arduino.h>

class Relay {
  private:
    short pin;
  public:
    Relay(short pin);
    void setup();
    void loop();
    void on();
    void off();
};

#endif