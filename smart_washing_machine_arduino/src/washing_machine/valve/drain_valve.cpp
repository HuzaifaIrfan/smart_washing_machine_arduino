
#include "drain_valve.hpp"

DrainValve::DrainValve(Relay water_drain_valve_relay) : water_drain_valve_relay(water_drain_valve_relay)
{
}

void DrainValve::setup()
{
    water_drain_valve_relay.setup();
}

void DrainValve::loop()
{
}

void DrainValve::open()
{
    water_drain_valve_relay.on();
}
void DrainValve::close()
{
    water_drain_valve_relay.off();
}
