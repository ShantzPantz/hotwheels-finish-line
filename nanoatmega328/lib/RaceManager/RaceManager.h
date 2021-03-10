#ifndef RaceManager_h
#define RaceManager_h

#include "Arduino.h"
#include <Display.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

class RaceManager
{
    public:
      RaceManager(int clk_pin, int data_pin, int cs_pin, int max_devices=4, int num_zones=4);
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
      //char places[4][5];
};

#endif