import json
from cpu import CPU

def print_regs():
     print(f" PC=0x{cpu.PC:04X}, A=0x{cpu.A:02X}, B=0x{cpu.B:02X}, X=0x{cpu.X:04X}, SP=0x{cpu.SP:04X}, C={cpu.C}, V={cpu.V}, Z={cpu.Z}, N={cpu.N}, I={cpu.I}, H={cpu.H}, 0x1FFF=0x{cpu.RAM[0x1FFF]:04X}, 0x1FFE=0x{cpu.RAM[0x1FFE]:04X}")

cpu = CPU(True)  #start CPU with debug

opcode = 0
A = 2
B = 3

_file = "test.json"

inputFile = open(_file, "r")

lines  = inputFile.readlines()

for line in lines:
    elements = json.loads(line)

    if "A" in elements:
         cpu.A = int(elements["A"], 16)
    if "B" in elements:
         cpu.B = int(elements["B"], 16)
    if "opcode" in elements:
         cpu.code = [int(item, 16) for item in elements["opcode"]]
    if "PC" in elements:
         cpu.PC = int(elements["PC"], 16)
    debug = cpu.cycle()
    print(debug)
    print_regs()

    


cpu.SP = 0x1FFF

# TEST instrukcii 
cpu.PC = 0
cpu.A = 0x4F
cpu.B = 0xFF
cpu.C = 1
cpu.X = 0x54FF
cpu.RAM[0x20] = 0xBC
cpu.RAM[0x40] = 0xDE
cpu.RAM[0x20BD] = 0xa5
cpu.code = [0x1B]
debug = cpu.cycle()
print(debug)

# ABX    Add B to X
# cpu.PC = 0
cpu.A = 0x4F
cpu.B = 0xFF
cpu.C = 1
cpu.X = 0x54FF
cpu.code.append(0x3A)
debug = cpu.cycle()
print(debug)

# ADCA #
# cpu.PC = 0
cpu.A = 0xFF
cpu.B = 0xFF
cpu.C = 1
cpu.X = 0x54FF
cpu.code.extend((0x89, 0xa5))
debug = cpu.cycle()
print(debug)

# ANDA # 
# cpu.PC = 0
cpu.A = 0xFF
cpu.B = 0xFF
cpu.C = 1
cpu.X = 0x54FF
cpu.code.extend((0x84, 0xa5))
debug = cpu.cycle()
print(debug)

# ANDA 0m 
# cpu.PC = 0
cpu.A = 0xFF
cpu.B = 0xFF
cpu.C = 1
cpu.RAM[0x20] = 0xBC
cpu.RAM[0x40] = 0xDE
cpu.RAM[0x20BD] = 0xa5
cpu.X = 0x54FF
cpu.code.extend((0x94, 0x20))
debug = cpu.cycle()
print(debug)

# ANDA d,X 
# cpu.PC = 0
cpu.A = 0xFF
cpu.B = 0xFF
cpu.C = 1
cpu.RAM[0x20] = 0xBC
cpu.RAM[0x40] = 0xDE
cpu.RAM[0x20BD] = 0x23
cpu.X = 0x2000
cpu.code.extend((0xA4, 0xBD))
debug = cpu.cycle()
print(debug)

# ANDA mm 
# cpu.PC = 0
cpu.A = 0xFF
cpu.B = 0xFF
cpu.C = 1
cpu.RAM[0x20] = 0xBC
cpu.RAM[0x40] = 0xDE
cpu.RAM[0x20BD] = 0x5c
cpu.X = 0x2000
cpu.code.extend((0xB4, 0x20, 0xbd))
debug = cpu.cycle()
print(debug)

# ANDB # 
# cpu.PC = 0
cpu.A = 0xFF
cpu.B = 0xFF
cpu.C = 1
cpu.X = 0x54FF
cpu.code.extend((0xC4, 0xa5))
debug = cpu.cycle()
print(debug)
print_regs()

# ANDB 0m 
# cpu.PC = 0
cpu.A = 0xFF
cpu.B = 0xFF
cpu.C = 1
cpu.RAM[0x20] = 0xBC
cpu.RAM[0x40] = 0xDE
cpu.RAM[0x20BD] = 0xa5
cpu.X = 0x54FF
cpu.code.extend((0xD4, 0x20))
debug = cpu.cycle()
print(debug)
print_regs()

# ANDB d,X 
# cpu.PC = 0
cpu.A = 0xFF
cpu.B = 0xFF
cpu.C = 1
cpu.RAM[0x20] = 0xEC
cpu.RAM[0x40] = 0xDE
cpu.RAM[0x20BD] = 0x23
cpu.X = 0x2000
cpu.code.extend((0xE4, 0xBD))
debug = cpu.cycle()
print(debug)
print_regs()

# ANDB mm 
# cpu.PC = 0
cpu.A = 0xFF
cpu.B = 0xFF
cpu.C = 1
cpu.RAM[0x20] = 0xBC
cpu.RAM[0x40] = 0xDE
cpu.RAM[0x20BD] = 0x5c
cpu.X = 0x2000
cpu.code.extend((0xF4, 0x20, 0xbd))
debug = cpu.cycle()
print(debug)
print_regs()

# CLRA 
# cpu.PC = 0
cpu.A = 0xFF
cpu.code.append(0x4F)
debug = cpu.cycle()
print(debug)
print_regs()

# CLRB 
# cpu.PC = 0
cpu.B = 0xFF
cpu.code.append(0x5F)
debug = cpu.cycle()
print(debug)
print_regs()

# JSR mm 
# cpu.PC = 0
cpu.code.extend((0xBD, 0x30, 0x20))
debug = cpu.cycle()
print(debug)
print_regs()

# CLRB 
cpu.PC = 0x001B
cpu.B = 0xFF
cpu.code.append(0x5F)
debug = cpu.cycle()
print(debug)
print_regs()



while 1:
      pass
# TEST instrukcii 
