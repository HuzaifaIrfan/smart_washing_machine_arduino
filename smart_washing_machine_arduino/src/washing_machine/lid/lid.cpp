
#include "lid.hpp"

Lid::Lid(short pin):pin(pin)
{
}

void Lid::setup()
{
  pinMode(pin, INPUT_PULLUP);
}

void Lid::loop()
{
}
