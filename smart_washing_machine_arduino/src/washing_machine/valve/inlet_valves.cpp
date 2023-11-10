
#include "inlet_valves.hpp"

InletValves::InletValves(Relay hot_water_inlet_valve_relay, Relay cold_water_inlet_valve_relay) : hot_water_inlet_valve_relay(hot_water_inlet_valve_relay), cold_water_inlet_valve_relay(cold_water_inlet_valve_relay)
{
}

void InletValves::setup()
{
    hot_water_inlet_valve_relay.setup();
    cold_water_inlet_valve_relay.setup();
}

void InletValves::loop()
{
}

void InletValves::open()
{
    hot_water_inlet_valve_relay.on();
    hot_water_inlet_valve_relay.on();
}

void InletValves::open_hot()
{
    hot_water_inlet_valve_relay.on();
    cold_water_inlet_valve_relay.off();
}
void InletValves::open_cold()
{
    hot_water_inlet_valve_relay.off();
    cold_water_inlet_valve_relay.on();
}

void InletValves::close()
{
    hot_water_inlet_valve_relay.off();
    cold_water_inlet_valve_relay.off();
}
