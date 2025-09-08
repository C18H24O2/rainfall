#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void m(void *param_1,int param_2,char *param_3,int param_4,int param_5)

{
  puts("Nope");
  return;
}

int main(int argc,char **argv)
{
    char *dst;
    void (**func)(void *, int, char *, int, int);
    
    dst = (char *)malloc(0x40);
    func = (void (**)(void *, int, char *, int, int))malloc(4);
    *func = m;
    strcpy(dst,argv[1]);
    (**func)(NULL, 0, NULL, 0, 0);;
}
