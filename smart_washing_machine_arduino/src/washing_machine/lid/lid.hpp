#ifndef LID_H
#define LID_H

#include <Arduino.h>

class Lid {
  private:
    short pin;
  public:
    Lid(short pin);
    void setup();
    void loop();
};

#endif