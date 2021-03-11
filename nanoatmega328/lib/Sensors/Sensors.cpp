#include "Arduino.h"
#include "Sensors.h"

Sensors::Sensors(int pins[4])
{
    _pins = pins;
}

Sensors::~Sensors()
{
    delete _pins;
}

void Sensors::update() 
{
    for(int i=0; i<4; i++) 
    {
        _values[i] = analogRead(_pins[i]);         
    };
}

int * Sensors::get_values() 
{
    return _values;
}