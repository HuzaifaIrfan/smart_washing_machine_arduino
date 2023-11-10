
#include "dryer.hpp"

Dryer::Dryer(DrainValve drain_valve, Spinner spinner) : drain_valve(drain_valve), spinner(spinner)
{
}

void Dryer::setup()
{
    // drain_valve  and spinner will already be setup by washing machine
}

void Dryer::loop()
{
}
