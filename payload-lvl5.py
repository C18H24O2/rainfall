#!/usr/bin/env python3

from struct import pack

def p(x): return pack('<I', x)
def isprint(c): return c >= 0x20 and c <= 0x7e

exit_addr = 0x0804a014
o_addr    = 0x080484a4

offset_exit_to_o = o_addr - exit_addr
print("offset_exit_to_o = %d" % offset_exit_to_o)


# Idea: write a `jmp -7024` to exit@got

