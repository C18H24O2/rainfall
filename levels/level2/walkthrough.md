# level2 walkthrough

New level, new suid binary. Woohoo!

This time, we're given a harder problem: looking at the disassembled code, there seems to be a check of the return value checking if it's in a certain range, and calling `_exit` right after.

We can also see that there is a `strdup` call, which hints that there is heap memory shenanigans.
