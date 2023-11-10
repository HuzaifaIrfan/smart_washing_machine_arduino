
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

void Dryer::open_drain()
{
    if (spinner.is_off())
    {
        drain_valve.open();
    }
}

void Dryer::spin()
{
    if (drain_valve.is_open())
    {
        spinner.spin_dryer();
    }
}

void Dryer::stop()
{
    spinner.stop();
}

void Dryer::close_drain_and_brake()
{
    if (spinner.is_off())
    {
        drain_valve.close();
    }
}
