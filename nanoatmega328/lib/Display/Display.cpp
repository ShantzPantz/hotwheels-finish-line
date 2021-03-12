#include "Arduino.h"
#include "Display.h"

Display::Display(int clk_pin, int data_pin, int cs_pin, int max_devices, int num_zones)
{
    _numZones = num_zones;
    // _parola = new MD_Parola(MD_MAX72XX::FC16_HW, clk_pin, data_pin, cs_pin, max_devices);
    _parola = new MD_Parola(MD_MAX72XX::FC16_HW, cs_pin, max_devices);
    _parola->begin(num_zones);
    for(int i=0; i<num_zones; i++) {
        _parola->setZone(i, i, i);
        // char * text = new char[1];
        // Serial.println("Test Zone Display");
        // itoa(i, text, 10);
        // _parola->displayZoneText(i, "1", PA_CENTER, 50, 50, PA_SCROLL_DOWN);
    }
}

Display::~Display() 
{
    
}


void Display::update()
{   
    if(_parola->displayAnimate()) 
    {
       
    }
}

void Display::set_lane_display(int lane, char * text)
{
    _parola->displayZoneText(lane, text, PA_CENTER, 100*_parola->getSpeed(), 0, PA_SCROLL_DOWN);
}

