#include <Arduino.h>

#include "Manager.h"
#include <Wire.h> 

uint32_t a = 12;

MainManager* manager;
void setup() {
  manager = new MainManager();

}

void loop() {
  manager->CheckEncoder();
  manager->CheckSensors();
}