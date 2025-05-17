#include "HW.h"

HW hw;

  unsigned long timer;

void setup() {
  Serial.begin(115200);

  delay(2000);
  Serial.println("KX-T30810B - test, v0.0.0");

  Serial.println("Code:");
  for(int i=0x3000; i<0x3010; i++)  {
    Serial.println("0x" + String(i,HEX) + ": " + String(hw.read_byte(i), HEX));
  }

  Serial.println("Clock:");
  for(int i=0x2100; i<=0x210F; i++)  {
    Serial.println("0x" + String(i,HEX) + ": " + String(hw.read_byte(i), HEX));
  }

  Serial.println("IC136:");
  for(int i=0x2000; i<=0x200F; i++)  {
    Serial.println("0x" + String(i,HEX) + ": " + String(hw.read_byte(i), HEX));
  }

  Serial.println("IC113:");
  for(int i=0x2300; i<=0x230F; i++)  {
    Serial.println("0x" + String(i,HEX) + ": " + String(hw.read_byte(i), HEX));
  }

  timer = millis();


}

void loop() {

  if((millis() - timer) > 1000) {
    timer = millis();
    Serial.println("Clock:");
    for(int i=0x2100; i<=0x210F; i++)  {
      Serial.println("0x" + String(i,HEX) + ": " + String(hw.read_byte(i), HEX));
    }
  }


}
