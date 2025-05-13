def convert(file):
    counter = 0
    while True:
        num = file.read(1)
        if num == b'':
            break
        # print(hex(int.from_bytes(num)))
        out_0x.write(hex(int.from_bytes(num)))
        out_0x.write(' ')
        # print(f'{int.from_bytes(num):x}')
        out.write(f'{int.from_bytes(num):02X}')
        out.write(' ')
        out_addr.write(f'{int(counter):04X} ')
        out_addr.write(f'{int.from_bytes(num):02X}')
        out_addr.write('\n')
        counter += 1



file = "KX-T30810B_FW.BIN"

out_file = "out.txt"
out_file_0x = "out_0x.txt"
out_file_addr = "out_addr.txt"

text = open(file, "rb")

out = open(out_file, "w")
out_0x = open(out_file_0x, "w")
out_addr = open(out_file_addr, "w")


convert(text)


out.close()
out_0x.close()


print("end")