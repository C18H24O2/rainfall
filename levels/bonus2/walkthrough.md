# bonus2 walkthrough

This one is a bit weird.

After some static code analysis, we find that we can pass the program 2 arguments, and the program also looks-up the `LANG` environment variable.

First, it copies `argv[1]` and `argv[2]` to what are probably two stack arrays, using `strncpy` with a length of 40 and 32.

There is a check against the contents of the `LANG` variable, and if it matches either `fi` or `nl`, it sets an `int language` variable to 1 or 2 respectively. Emphasis on the fact that this comparaison just checks for the 2 first chars, meaning we can put whatever else we want in that. We'll come back to it later.

Next, the program calls its `greetuser` function, passing the address of the first stack array. It then copies a language-specific string to a stack array of length 64, and then calls `strcat` to this array with our `main` stack buffer.

## The maybe exploit

We could pass a small enough payload to the program so that it would overflow `greetuser`'s buffer and rewrite its return value, jumping to our buffer, and executing a shellcode.

However, we were too lazy.

## The actual exploit

Shellcode in environment variable.

Have you tried Shellcode in environment variable? Just 67 amps.

We'll just put the shellcode in `LANG` after the `fi`, with a huge ass nop-slide just in case, and rewrite `greetuser`'s return address.
