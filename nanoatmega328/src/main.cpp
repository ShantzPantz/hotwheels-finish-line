//By Brian Shantz 2021, based on the work of Mike Freda
//Diecast electronic finish line
//First car to break IR beam is the lane winner
//Uses Gikfun 5mm 940nm IR LED's emitters and receivers: EK8443

#include <Arduino.h>
#include <RaceManager.h>

#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

int finishSensors[4] = {A0, A1, A2, A3}; // Sensor analog inputs, from lane 1 - 4
// int sensorValues[4] = {0, 0, 0, 0}; // Hold sensor values

int sensorThresh = 500; //Sets the trigger sensing threshold of the IR receivers. ~1000 = high


RaceManager race(CLK_PIN, DATA_PIN, CS_PIN, 4, 4, finishSensors);

void setup() 
{
  Serial.begin(9600);
  Serial.println("Setup");
}

void loop() 
{
  race.update();
  delay(1000);
}
