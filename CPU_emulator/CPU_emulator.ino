#include "HW.h"

HW hw;

  unsigned long timer;

void setup() {
  Serial.begin(115200);

  delay(2000);
  Serial.println("KX-T30810B - test, v0.0.0");
  Serial.println(" ");

  Serial.println("Clock:");
  for(int i=0x2100; i<=0x210F; i++)  {
    Serial.println("0x" + String(i,HEX) + ": " + String(hw.read_byte(i), HEX));
  }
  Serial.println(" ");

  Serial.println("IC136:");
  for(int i=0x2000; i<=0x200F; i++)  {
    Serial.println("0x" + String(i,HEX) + ": " + String(hw.read_byte(i), HEX));
  }
  Serial.println(" ");

  Serial.println("IC113:");
  for(int i=0x2300; i<=0x230F; i++)  {
    Serial.println("0x" + String(i,HEX) + ": " + String(hw.read_byte(i), HEX));
  }
  Serial.println(" ");

  Serial.println("DTMF:");
  Serial.println("0x2200: " + String(hw.read_byte(0x2200), HEX));
  Serial.println(" ");

  Serial.println("RAM:");
  for(int i=0x0020; i<=0x003F; i++)  {
    Serial.println("0x" + String(i,HEX) + ": " + String(hw.read_byte(i), HEX));
  }
  Serial.println(" ");

  Serial.println("RAM2:");
  for(int i=0x0100; i<=0x1FFF; i++)  {
    Serial.println("0x" + String(i,HEX) + ": " + String(hw.read_byte(i), HEX));
  }
  Serial.println(" ");




  timer = millis();

  hw.write_byte(0x00, 0x2300);  // P0 = 0x00
  hw.write_byte(0x80, 0x2301);  // P1 = 0x80
  hw.write_byte(0x00, 0x2302);  // P2 = 0x00
  hw.write_byte(0x3C, 0x2303);  // P3 = 0x3C
  hw.write_byte(0x3C, 0x2304);  // P4 = 0x3C  
  hw.write_byte(0x3C, 0x2305);  // P5 = 0x3C
  hw.write_byte(0xFF, 0x2308);  // P0DD = OOOOOOOO, P1DD = OOOOOOOO
  hw.write_byte(0x7F, 0x2309);  // P2DD = OOOOOOOO, P3DD = IOOOOOOO
  hw.write_byte(0x77, 0x230A);  // P4DD = IOOOOOOO, P5DD = IOOOOOOO
  hw.write_byte(0x38, 0x230B);  // P6DD = OIIIIIII, P7DD = IIOOOOOO

  hw.write_byte(0x00, 0x2000);
  hw.write_byte(0x00, 0x2006);

}


int data=0;

void loop() {

// #define address 0x2300
//     hw.write_byte(0b01110110, address);
//     Serial.println("IC113: 0x2305=11000010");
//     Serial.println("0x2305: " + String(hw.read_byte(address), HEX));
//     delay(1000);

//     hw.write_byte(0b01111111, address);
//     Serial.println("IC113: 0x2305=11000000");
//     Serial.println("0x2305: " + String(hw.read_byte(address), HEX));
//     delay(1000);


  // if((millis() - timer) > 1000) {
    timer = millis();

    // Serial.println("Clock:");
    // for(int i=0x2100; i<=0x210F; i++)  {
    //   Serial.println("0x" + String(i,HEX) + ": " + String(hw.read_byte(i), HEX));
    // }

    Serial.println("IC113:");
    for(int i=0x2300; i<=0x2307; i++)  {
      Serial.println("0x" + String(i,HEX) + ": " + String(hw.read_byte(i), HEX));
    }

    Serial.println("IC136:");
    for(int i=0x2000; i<=0x200F; i++)  {
      Serial.println("0x" + String(i,HEX) + ": " + String(hw.read_byte(i), HEX));
    }

    hw.write_byte(0x3D, 0x2303);  // P3 = 0x3C
    hw.write_byte(0x3D, 0x2304);  // P4 = 0x3C  
    hw.write_byte(0x3C, 0x2305);  // P5 = 0x3C
    delay(1000);
    hw.write_byte(0x3D, 0x2303);  // P3 = 0x3C
    hw.write_byte(0x3C, 0x2304);  // P4 = 0x3C  
    hw.write_byte(0x3D, 0x2305);  // P5 = 0x3C
    delay(1000);

  // }


}
