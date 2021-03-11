#ifndef Display_h
#define Display_h

#include "Arduino.h"
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

class Display
{
    public:
      Display(int clk_pin, int data_pin, int cs_pin, int max_devices=4, int num_zones=4);
      ~Display();
      void update();
      
    private:
      int _numZones;
      char places[4][5];
      MD_Parola* _parola;
};

#endif