
#include "lid.hpp"


volatile bool Lid::lid_open_or_vibration_interrupted=false;

Lid::Lid(short pin):pin(pin)
{
}

void Lid::setup()
{
  pinMode(pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pin), lid_open_or_dryer_vibration_switch_interrupt_service_routine, FALLING);
}

void Lid::lid_open_or_dryer_vibration_switch_interrupt_service_routine()
{
  lid_open_or_vibration_interrupted = true;
}


void Lid::loop()
{
}
