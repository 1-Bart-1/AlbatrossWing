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
  if (connect.send_now) {
    orient.update(&orientation);
    connect.sendData();
    connect.send_now = false;
  }
  delay(1);
  // Serial.print(orientation.w);
  // Serial.println();
}