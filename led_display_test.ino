// Program to demonstrate the MD_Parola library
//
// Simplest program that does something useful - Hello!
// Uses the Arduino Print Class extension
//
// MD_MAX72XX library can be found at https://github.com/MajicDesigns/MD_MAX72XX
//

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define NUM_ZONES 4

#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10


char places[4][5] =
  { "4",
    "3",
    "2",
    "1"
  };

// Hardware SPI connection
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
// Arbitrary output pins
// MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);



void setup(void)
{
  Serial.begin(9600);
  Serial.println("Setup");
  
  P.begin(NUM_ZONES);
  for(int i=0; i<NUM_ZONES; i++) {
    P.setZone(i, i, i);
    //P.setZoneEffect(i, true, PA_FLIP_UD);
    //P.setZoneEffect(i, true, PA_FLIP_LR);

    Serial.println("Testing");

    P.displayZoneText(i, places[i], PA_CENTER, 50, 50, PA_SCROLL_DOWN);
  }
  
  
}

void loop(void)
{
  if (P.displayAnimate()) // animates and returns true when an animation is completed
  {
    for (uint8_t i=0; i<4; i++)
    {
//      if (P.getZoneStatus(i))
//      {
//        outFX[i] = (outFX[i] + 1) % ARRAY_SIZE(effect);
//        if (outFX[i] == 0)
//        inFX[i] = (inFX[i] + 1) % ARRAY_SIZE(effect);
//
//        P.setTextEffect(i, effect[inFX[i]], effect[outFX[i]]);
//
//        // tell Parola we have a new animation
//        P.displayReset(i);
//      }
    }
  }
}
