from cpu import CPU

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


cpu = CPU(True)  #start CPU with debug

cpu.loadProgram(ROM)  # load program to CPU ROMs

cpu.reset() # set PC according to RESET vector

while(1):
      cpu.cycle()
