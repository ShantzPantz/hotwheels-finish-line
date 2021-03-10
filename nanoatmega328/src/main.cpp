//By Brian Shantz 2021, based on the work of Mike Freda
//Diecast electronic finish line
//First car to break IR beam is the lane winner
//Uses Gikfun 5mm 940nm IR LED's emitters and receivers: EK8443

#include <Arduino.h>

int finishSensors[4] = {A0, A1, A2, A3}; // Sensor analog inputs, from lane 1 - 4
int sensorValues[4] = {0, 0, 0, 0}; // Hold sensor values

int sensorThresh = 500; //Sets the trigger sensing threshold of the IR receivers. ~1000 = high

void setup() 
{
  Serial.begin(9600);
  Serial.println("Setup");
}

void loop() 
{

  // read all sensor values
  Serial.println("sensor values");
  for(int i=0; i<4; i++) 
  {
    sensorValues[i] = analogRead(finishSensors[i]);
    Serial.println(sensorValues[i]);
  }
  
  delay(50);

  for(int i=0; i<4; i++) 
  {
    if(sensorValues[i] < sensorThresh)
    {
      Serial.println(sensorValues[i]);
      Serial.print("Lane ");
      Serial.print(i+1); 
      Serial.print(" wins!");
      Serial.println();
      delay(5000);
    }
  }
}
