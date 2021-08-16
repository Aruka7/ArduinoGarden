#include <Arduino.h>

#include "Manager.h"
#include <Wire.h> 

#define DEBUG_MODE 1

MainManager* manager;
void setup() {
  #if DEBUG_MODE == 1
  Serial.begin(9600);
  #endif
  manager = new MainManager();

}

void loop() {
  manager->CheckEncoder();
  manager->CheckSensors();
  
}