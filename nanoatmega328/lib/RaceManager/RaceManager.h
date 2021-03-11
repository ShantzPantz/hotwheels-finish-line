#ifndef RaceManager_h
#define RaceManager_h

#include "Arduino.h"
#include <Display.h>
#include <Sensors.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

class RaceManager
{
    public:
      RaceManager(int clk_pin, int data_pin, int cs_pin, int max_devices, int num_zones, int sensor_pins[4]);
      void update();
      

      enum RaceState {
          STARTUP,
          SLEEP,
          WAITING_FOR_WINNER,
          WAITING_FOR_FINISHERS
      };

      RaceState getState(); 
      
    private:
      RaceState _state;
      Display* _display;
      Sensors* _sensors;

      void update_results();

      int _results[4];
      int _result_idx;
      //char places[4][5];
};

#endif