#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *gets(char *s);

int main(void)
{
    char buffer [76];
    
    fflush(stdout);
    gets(buffer);
    if (((unsigned int)__builtin_return_address(0) & 0xb0000000) == 0xb0000000) {
        printf("(%p)\n", __builtin_return_address(0));
        exit(1);
    }
    puts(buffer);
    strdup(buffer);
}
