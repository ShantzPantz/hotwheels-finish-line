#include "Arduino.h"
#include "RaceManager.h"
#include <Display.h>

RaceManager::RaceManager(int clk_pin, int data_pin, int cs_pin, int max_devices, int num_zones, int sensor_pins[4])
{
    _state = RaceState::STARTUP;
    _display = new Display(clk_pin, data_pin, cs_pin, 4, 4);
    _sensors = new Sensors(sensor_pins);
    _last_trigger_time = 0L;
}

void RaceManager::update()
{
    switch (_state)
    {
    case RaceState::STARTUP:
        // Display Startup Message on Panels
        Serial.println("Starting!");
        memset(_results, 0, sizeof(_results));
        _result_idx = 0;
        _last_trigger_time = 0L;
        _state = RaceState::WAITING_FOR_WINNER;
        delay(1000);
        break;
    case RaceState::WAITING_FOR_WINNER:
    case RaceState::WAITING_FOR_FINISHERS:
        // Update sensor values
        _sensors->update();
        update_results();        
        break;
    case RaceState::SHOW_RESULTS:
        Serial.println("Show Results!");
        delay(5000);
        _state = RaceState::STARTUP;
        break;
    
    default:
        break;
    }

    _display->update();
}

void RaceManager::update_results()
{
    long now = millis();

    int * values = _sensors->get_values();
    
    for(int i=0; i<4; i++) 
    {      
        delay(500);
        Serial.println(values[i]);
        if(values[i] < Sensors::SENSOR_THRESH)
        {
            // check if this lane is already in the results
            bool exists = false;
            size_t length = sizeof(_results) / sizeof(int);
            for(unsigned int j = 0; j < length; j++){
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
                
                update_display(i, _result_idx);
                
                if( _state != RaceState::WAITING_FOR_FINISHERS ) 
                {
                    _state = RaceState::WAITING_FOR_FINISHERS;
                }
                _last_trigger_time = now;
            }
        }     
    }
    long delta = now - _last_trigger_time;
   
    if(_state == RaceState::WAITING_FOR_FINISHERS && delta >= RaceManager::WAIT_FOR_FINISH_MS)
    {
        // We have reached the threshold
        _state = RaceState::SHOW_RESULTS;
    }
}

void RaceManager::update_display(int lane, int position)
{
    char buffer[2];
    itoa(position, buffer, 10);
    _display->set_lane_display(lane, buffer);
}

RaceManager::RaceState RaceManager::getState()
{
    return _state;
}