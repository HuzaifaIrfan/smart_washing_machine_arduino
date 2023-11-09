#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal.h>


class Display {
  public:
    Display();
    void setup();
    void loop();
    void set_cursor( uint8_t col, uint8_t row);
    void print(String message);
    void set_cursor_and_print(String message, uint8_t col, uint8_t row);
};

#endif