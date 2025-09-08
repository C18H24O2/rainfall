#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *gets(char *s);

int main(void)
{
    char buffer [76];
    unsigned int value;
    
    fflush(stdout);
    gets(buffer);
    if ((value & 0xb0000000) == 0xb0000000) {
        printf("(%p)\n", value);
        exit(1);
    }
    puts(buffer);
    strdup(buffer);
}
