# level5 walkthrough

The funnies...

In this one, we're again seeing a `printf(3)` format string exploit, but this time, it's very annoying.

This time, there's nothing given to us on a silver platter, we have to figure out where to go.

There's a call to `exit(2)`, so we can't just overwrite the return address on the stack. What we can do however, is learn about another code injection technique called...

## GOT Overriding???

First, we need to understand what the GOT is. The GOT, or Global Offset Table, is an in-memory table that points to function addresses. It is used in dynamically linked executables for stub functions that get replaced at runtime, before main, by the dynamic linker.

This means that the GOT needs to be writable for the linker to replace the addresses right? Well, yes, but there is nothing that *guarentees* us that the memory area is not locked again after writing.

Fortunately for us, this restriction does not apply in our case! The executable does not have a read-only (RO) GOT, so we're in the clear, let's overwrite this b- uh, table.

## Overwriting the GOT

This is pretty straightforward, we need to find where in the GOT the address of a function is, and just write another address on it. This is especially easy in this scenario since there is no relocation applied. We'll follow the call to `exit(2)` in our `main` function, which leads us to the stub that loads the address from the GOT. From there, we pickup the address, and use `printf` to replace it using a `%n` formatter.

Now, since we need to write a memory address, that's 32 bits, or 4 bytes, or up to 2147483648 in terms of value. That's way too much, our poor printf function can't handle that (and neither can we, that's a huge number of characters to write). This makes it a bit tedious, since we have to split our writing in two using the `%hn` format specifier (`h` for "half"), where we'll write two `short`s (2 bytes each).

As for the address we're writing, the exercise graciously provides us with an `o` function that just calls `/bin/sh`, neato.
