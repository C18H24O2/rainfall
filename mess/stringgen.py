#!/usr/bin/env python3

import sys
if len(sys.argv) == 1:
    print("".join(["a" + chr(i) for i in range(65, 91)]))
    print("".join(["b" + chr(i) for i in range(65, 91)]))
else:
    print("A" * int(sys.argv[1]))
    print("B" * int(sys.argv[1]))
