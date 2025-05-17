/**
 * @file TagHeuer_HW.h
 * @author Pavlo
 * @brief 
 * @version 0.1
 * @date 2025-05-02
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef HW_h
#define HW_h

// **** piny ******
#define A0  45
#define A1  44
#define A2  43
#define A3  42
#define A4  41
#define A5  40
#define A6  39
#define A7  38
#define A8  37
#define A9  36
#define A10  35
#define A11  34
#define A12  33
#define A13  32
#define A14  31
#define A15  30


// ak je datovka na jednom porte
#define DATA_PORT_DIRECT_ACCESS

#ifdef  DATA_PORT_DIRECT_ACCESS

#define DATA_OUT_PORT   PORTA
#define DATA_DIRECTION  DDRA
#define DATA_IN_PORT    PINA

#else
#define D0  22
#define D1  23
#define D2  24
#define D3  25
#define D4  26
#define D5  27
#define D6  28
#define D7  29
#endif

#define RD  47
#define WR  46


//smer datovej zbernice funkcie "data_bus_direction"
#define IN    1
#define OUT   2




/**
 * @brief HW API
 * 
 */
class HW
{
  public:
    HW();
    void init();
    void write_byte(unsigned char byte_out, unsigned int address);
    void write_data_bus(unsigned char byte_out);
    void write_address_bus(unsigned int address);
    int data_bus_direction(unsigned char direction);

    unsigned char read_byte(unsigned int address);

  private:
  };



#endif