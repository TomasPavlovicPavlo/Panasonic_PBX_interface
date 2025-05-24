# Panasonic_PBX_interface

 ![Timing](/img/timing.png)

DIN packets

|           |start|  ID  |byte_0  |byte_1 |byte_2 |byte_3 |byte_4|parity| stop|     |
|:----------|:---:|:----:|:------:|:-----:|:-----:|:-----:|:----:|:----:|:---:|:---:|
| bites     | 1   |  4   |   8    |   8   |   8   |   8   |   8  |   1  |  1  | = 47|
|LCD <0-3>  | 1   | 0001 | LCD_0  | LCD_1 | LCD_2 | LCD_3 | 0x00 |   P  |  1  | |
|LCD <4-7>  | 1   | 0010 | LCD_4  | LCD_5 | LCD_6 | LCD_7 | 0x00 |   P  |  1  | |
|LCD <8-11> | 1   | 0011 | LCD_8  | LCD_9 | LCD_10| LCD_11| 0x00 |   P  |  1  | |
|LCD <12-15>| 1   | 0100 | LCD_12 | LCD_13| LCD_14| LCD_15| 0x00 |   P  |  1  | |
| | 1   | 0101 |  | | | |  |   P  |  1  | |
| | 1   | 0110 |  | | | |  |   P  |  1  | |

## disassemble FW dump
```
./f9dasm -begin 0x3000 -6303 -noflex -addr -out out.asm KX-T30810B_FW.BIN -info info.info
```

## assemble source code

```
./dasm pokus/pokus.asm -oout.bin -llist -v1 -f3
```
 - -o*filename* &emsp; output filemane
 - -l*list* &emsp; listing filename
 - -v*value* &emsp; verbosity level
 - -f*value*
   - 1 &emsp; default
   - 2 &emsp; RAS
   - 3 &emsp; RAW - data only