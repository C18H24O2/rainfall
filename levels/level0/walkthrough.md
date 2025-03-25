> level0 walkthrough

We are given a suid binary, which seems to segfault when run:

```
level0@rainfall:~$ ./level0
Segmentation fault (core dumped)
```

When trying to give it an argument, it outputs a message:

```
level0@rainfall:~$ ./level0 42
No !
```

When running with gdb, we can see that it calls `atoi` on the first argument and compares it with `0x222` (`423`). If it is equal, it executes `/bin/sh` with the `execl` syscall.

Let's try passing `423` as an argument:

```
level0@rainfall:~$ ./level0 423
# id
uid=2030(level1) gid=2020(level1) groups=2030(level1),100(users),2020(level0)
```

Looks like we got a shell! We can now get the `.pass` file:
```
# cat /home/user/level1/.pass
<flag>
```
..and login as `level1`!
