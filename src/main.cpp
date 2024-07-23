#include <Arduino.h>

#include "Orient.h"
#include "Connect.h"

Quaternion orientation;
uint8_t peerAddres[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}; 


void setup() {
  Serial.begin(115200);
  orient.begin();
  connect.begin(&orientation);
}

void loop() {
  orient.update(&orientation);
  connect.sendData();
  Serial.print(orientation.w);
  Serial.println();
	
  delay(10);
}