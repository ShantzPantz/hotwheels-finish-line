#include "Arduino.h"
#include "RaceManager.h"
#include <Display.h>

RaceManager::RaceManager(int clk_pin, int data_pin, int cs_pin, int max_devices, int num_zones, int sensor_pins[4])
{
    _state = RaceState::WAITING_FOR_FINISHERS;
    _display = new Display(clk_pin, data_pin, cs_pin, 4, 4);
    _sensors = new Sensors(sensor_pins); 
}

void RaceManager::update()
{
    switch (_state)
    {
    case RaceState::STARTUP:
        // Display Startup Message on Panels
        break;
    case RaceState::WAITING_FOR_FINISHERS:
        // Update sensor values
        _sensors->update();
        update_results();
        break;
    
    default:
        break;
    }
}

void RaceManager::update_results()
{
    int * values = _sensors->get_values();
    
    for(int i=0; i<4; i++) 
    {      
        if(values[i] < Sensors::SENSOR_THRESH)
        {
            // check if this lane is already in the results
            bool exists = false;
            size_t length = sizeof(_results) / sizeof(int);
            for(int j = 0; j < length; j++){
                if(_results[j] == i){
                    exists = true;
                    break;
                }
            }

            if(!exists) 
            {
                Serial.print("Lane ");
                Serial.print(i+1); 
                Serial.print(" finished!");
                Serial.println();
                _results[_result_idx++] = i;
            }
        
        }     
    }
}

RaceManager::RaceState RaceManager::getState()
{
    return _state;
}