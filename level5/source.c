#include <stdio.h>

void main(void)
{
    char buffer [520];
    
    fgets(buffer,512,stdin);
    printf(buffer);
    exit(1);
  }