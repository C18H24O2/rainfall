#include <stdio.h>
#include <stdlib.h>

// Compile with -Wno-format-security

int main(void)
{
    char buffer [520];
    
    fgets(buffer,512,stdin);
    printf(buffer);
    exit(1);
}
