#include "Arduino.h"
#include "Display.h"

Display::Display(int clk_pin, int data_pin, int cs_pin, int max_devices, int num_zones)
{
    _numZones = num_zones;
    _parola = new MD_Parola(MD_MAX72XX::FC16_HW, clk_pin, data_pin, cs_pin, max_devices);
}

Display::~Display() 
{
    delete _parola;
}

void Display::update()
{
    Serial.println("Display Update.");
}

