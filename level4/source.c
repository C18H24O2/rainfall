#include <stdio.h>
#include <stdlib.h>
int m = 0;

void p(char *str)

{
  printf(str);
  return;
}
void main(void)

{
    char buffer [520];
  
    fgets(buffer,0x200,stdin);
    p(buffer);
    if (m == 0x1025544) {
      system("/bin/cat /home/user/level5/.pass");
    }
    return;
}