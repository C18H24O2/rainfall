#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Compile: gcc -o level5 source.c -Wno-format-security

void o(void)
{
	system("/bin/sh");
	_exit(1);
}

int main(void)
{
    char buffer [520];
    
    fgets(buffer,512,stdin);
    printf(buffer);
    exit(1);
}
