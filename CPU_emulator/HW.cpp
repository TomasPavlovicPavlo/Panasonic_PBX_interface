/**
 * @file TagHeuer_HW.cpp
 * @author Pavlo
 * @brief 
 * @version 0.1
 * @date 2025-05-02
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "Arduino.h"
#include "HW.h"

/**
 * @brief Construct a new Tag Heuer:: Tag Heuer object
 * 
 */
HW::HW()  {
  init();
}

/**
 * @brief Inicializacia HW
 * 
 */
void HW::init ()  {
  // define pins
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A6, OUTPUT);
  pinMode(A7, OUTPUT);
  pinMode(A8, OUTPUT);
  pinMode(A9, OUTPUT);
  pinMode(A10, OUTPUT);
  pinMode(A11, OUTPUT);
  pinMode(A12, OUTPUT);
  pinMode(A13, OUTPUT);
  pinMode(A14, OUTPUT);
  pinMode(A15, OUTPUT);

  #ifndef DATA_PORT_DIRECT_ACCESS
  pinMode(D0, INPUT);
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(D4, INPUT);
  pinMode(D5, INPUT);
  pinMode(D6, INPUT);
  pinMode(D7, INPUT);
  #endif

  pinMode(RD, OUTPUT);
  pinMode(WR, OUTPUT);

  // pins initial state
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A5, LOW);
  digitalWrite(A6, LOW);
  digitalWrite(A7, LOW);
  digitalWrite(A8, LOW);
  digitalWrite(A9, LOW);
  digitalWrite(A10, LOW);
  digitalWrite(A11, LOW);
  digitalWrite(A12, LOW);
  digitalWrite(A13, LOW);
  digitalWrite(A14, LOW);
  digitalWrite(A15, LOW);

  #ifndef DATA_PORT_DIRECT_ACCESS
  digitalWrite(D0, LOW);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  digitalWrite(D5, LOW);
  digitalWrite(D6, LOW);
  digitalWrite(D7, LOW);
  #endif

  digitalWrite(RD, HIGH);
  digitalWrite(WR, HIGH);

}




/**
 * @brief zapise byte do niektoreho vystupneho latchu
 * -prehodi data bus na vystupny
 * -zapise data a adresu
 * -zacvici vystupom "BUS_EN"
 * @param byte_out Byte na zapis do latchu
 * @param address Adresa vystupneho latchu
 */
void HW::write_byte(unsigned char byte_out, unsigned int address)  {
  data_bus_direction(OUT);

  write_data_bus(byte_out);
  write_address_bus(address);

  digitalWrite(WR, LOW);   // 0 = active
  digitalWrite(WR, HIGH);   // 0 = active
}



/**
 * @brief Vycita byte z daneho vstupneho latchu
 * 
 * @param address Adresa vstupneho latchu
 * @return unsigned char Vycitany byte
 */
unsigned char HW::read_byte(unsigned int address)  {
  unsigned char data_in;

  if((address >= 0) && (address <= 0xffff)) {
    data_bus_direction(IN);
    write_address_bus(address);

    digitalWrite(RD, LOW);   // 0 = active

    #ifdef DATA_PORT_DIRECT_ACCESS
    data_in = DATA_IN_PORT;

    #else
    if(digitalRead(D0)==LOW)  data_in = 0;
    else  data_in = 1;
    if(digitalRead(D1)==LOW)  data_in &= ~0x02;
    else  data_in |= 0x02;
    if(digitalRead(D2)==LOW)  data_in &= ~0x04;
    else  data_in |= 0x04;
    if(digitalRead(D3)==LOW)  data_in &= ~0x08;
    else  data_in |= 0x08;
    if(digitalRead(D4)==LOW)  data_in &= ~0x10;
    else  data_in |= 0x10;
    if(digitalRead(D5)==LOW)  data_in &= ~0x20;
    else  data_in |= 0x20;
    if(digitalRead(D6)==LOW)  data_in &= ~0x40;
    else  data_in |= 0x40;
    if(digitalRead(D7)==LOW)  data_in &= ~0x80;
    else  data_in |= 0x80;
    #endif

    digitalWrite(RD, HIGH);   // 0 = active

    return data_in;
  }
  else return 0xFF;
}


/**
 * @brief zapise byte na D0-D7
 * 
 * @param byte_out Byte na zapis na zbernicu
 * @return * void 
 */
void HW::write_data_bus(unsigned char byte_out) {
  #ifdef DATA_PORT_DIRECT_ACCESS
  DATA_OUT_PORT = byte_out;

  #else
  if(byte_out & 0x01) digitalWrite(D0, HIGH);
  else  digitalWrite(D0, LOW);
  if(byte_out & 0x02) digitalWrite(D1, HIGH);
  else  digitalWrite(D1, LOW);
  if(byte_out & 0x04) digitalWrite(D2, HIGH);
  else  digitalWrite(D2, LOW);
  if(byte_out & 0x08) digitalWrite(D3, HIGH);
  else  digitalWrite(D3, LOW);
  if(byte_out & 0x10) digitalWrite(D4, HIGH);
  else  digitalWrite(D4, LOW);
  if(byte_out & 0x20) digitalWrite(D5, HIGH);
  else  digitalWrite(D5, LOW);
  if(byte_out & 0x40) digitalWrite(D6, HIGH);
  else  digitalWrite(D6, LOW);
  if(byte_out & 0x80) digitalWrite(D7, HIGH);
  else  digitalWrite(D7, LOW);
  #endif
}

/**
 * @brief zapise 16 bitovu adresu na A0-A15
 * 
 * @param address int na zapis na zbernicu
 * @return * void 
 */
void  HW::write_address_bus(unsigned int address)  {
  if(address & 0x0001) digitalWrite(A0, HIGH);
  else  digitalWrite(A0, LOW);
  if(address & 0x0002) digitalWrite(A1, HIGH);
  else  digitalWrite(A1, LOW);
  if(address & 0x0004) digitalWrite(A2, HIGH);
  else  digitalWrite(A2, LOW);
  if(address & 0x0008) digitalWrite(A3, HIGH);
  else  digitalWrite(A3, LOW);
  if(address & 0x0010) digitalWrite(A4, HIGH);
  else  digitalWrite(A4, LOW);
  if(address & 0x0020) digitalWrite(A5, HIGH);
  else  digitalWrite(A5, LOW);
  if(address & 0x0040) digitalWrite(A6, HIGH);
  else  digitalWrite(A6, LOW);
  if(address & 0x0080) digitalWrite(A7, HIGH);
  else  digitalWrite(A7, LOW);
  if(address & 0x0100) digitalWrite(A8, HIGH);
  else  digitalWrite(A8, LOW);
  if(address & 0x0200) digitalWrite(A9, HIGH);
  else  digitalWrite(A9, LOW);
  if(address & 0x0400) digitalWrite(A10, HIGH);
  else  digitalWrite(A10, LOW);
  if(address & 0x0800) digitalWrite(A11, HIGH);
  else  digitalWrite(A11, LOW);
  if(address & 0x1000) digitalWrite(A12, HIGH);
  else  digitalWrite(A12, LOW);
  if(address & 0x2000) digitalWrite(A13, HIGH);
  else  digitalWrite(A13, LOW);
  if(address & 0x4000) digitalWrite(A14, HIGH);
  else  digitalWrite(A14, LOW);
  if(address & 0x8000) digitalWrite(A15, HIGH);
  else  digitalWrite(A15, LOW);
}

/**
 * @brief Ovladanie smeru datovej zbernice
 * ak direction = "IN" tak prehodi smer na vstupny
 * ak direction = "OUT" tak prehodi smer na vystupny
 * @param direction "IN", "OUT"
 * @return int Vrati -1 pri neznamom parametre, inac vrati 1
 */
int HW::data_bus_direction(unsigned char direction) {
  #ifdef DATA_PORT_DIRECT_ACCESS

  if(direction==IN) {
    DATA_OUT_PORT = 0xFF;
    DATA_DIRECTION = 0x00;
  }
  else if(direction==OUT) {
    DATA_OUT_PORT = 0x00;
    DATA_DIRECTION = 0xFF;
  }
  else return -1;

  #else
  
  if(direction==IN) {
    pinMode(D0, INPUT);
    pinMode(D1, INPUT);
    pinMode(D2, INPUT);
    pinMode(D3, INPUT);
    pinMode(D4, INPUT);
    pinMode(D5, INPUT);
    pinMode(D6, INPUT);
    pinMode(D7, INPUT);
  }
  else if(direction==OUT) {
    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);
    pinMode(D5, OUTPUT);
    pinMode(D6, OUTPUT);
    pinMode(D7, OUTPUT);
  }
  else return -1;

  #endif

  return 1;
}
