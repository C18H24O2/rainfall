# level2 walkthrough

New level, new suid binary. Woohoo!

This time, we're given a harder problem: looking at the disassembled code, there seems to be a check of the return value checking if it's in a certain range (most likely a stack address, seeing as it checks for a `0xb0000000` start), and calling `_exit` right after. We can also see that there is a `strdup` call, which further hints at heap memory shenanigans.

Let's learn a new technique here: Return Oriented Programming (ROP). This basically means we're using return calls and specific instruction layouts to "write our program", by using already existing instructions in the binary (called "ROP gadgets").

## Return Oriented Programming

By using the `ROPgadget` tool, we can find a lot of addresses to instructions that lead to a `ret`, allowing us to manipulate the program registries as we need. In our case though, we only need another `ret`, that is preferably in a close area to the program stack so that it passes the check.

After finding the right one, we can push to the stack more values to override the *previous* stack value (from before main, `__libc_start_main`), and then set the `main` function's return value to a `ret` in the right memory range, which will pop the stack into our shellcode, and get us a shell. 
