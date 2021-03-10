#include "Arduino.h"
#include "RaceManager.h"
#include <Display.h>

RaceManager::RaceManager(int clk_pin, int data_pin, int cs_pin, int max_devices, int num_zones)
{
    _state = RaceState::STARTUP;
    _display = new Display(clk_pin, data_pin, cs_pin, 4, 4);
}

void RaceManager::update()
{
    Serial.println("Race Manager Update");
    //_parola = MD_Parola(MD_MAX72XX::FC16_HW, clk_pin, cs_pin, max_devices);
}

RaceManager::RaceState RaceManager::getState()
{
    return _state;
}