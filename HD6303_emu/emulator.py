from cpu import CPU

def print_regs():
     print(f" PC=0x{cpu.PC:04X}, A=0x{cpu.A:02X}, B=0x{cpu.B:02X}, X=0x{cpu.X:04X}, SP=0x{cpu.SP:04X}, C={cpu.C}, V={cpu.V}, Z={cpu.Z}, N={cpu.N}, I={cpu.I}, H={cpu.H}, 0x1FFF=0x{cpu.RAM[0x1FFF]:04X}, 0x1FFE=0x{cpu.RAM[0x1FFE]:04X}")

cpu = CPU(True)  #start CPU with debug

_file = "KX-T30810B_FW.BIN"

inputFile = open(_file, "rb")

ROM = []

i = 0
while(1):
    inputFile.seek(i)
    byte = inputFile.read(1)
    if byte == b"":
        break
    else:
        ROM.append(int.from_bytes(byte))
        i += 1

cpu.loadProgram(ROM)  # load program to CPU ROMs

cpu.reset() # set PC according to RESET vector

while(1):
      debug = cpu.cycle()
      print(debug)
    #   print_regs()
      
