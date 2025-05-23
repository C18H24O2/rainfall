#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char c[80];

typedef struct astruct {
    struct astruct *next;
    int value;
} astruct;

int main(int argc,char **argv)

{
  astruct *first;
  astruct *second;
  astruct *third;
  astruct *fourth;
  FILE *__stream;
  
  first = (astruct *)malloc(8);
  first->value = 1;
  second = (astruct *)malloc(8);
  first->next = second;
  third = (astruct *)malloc(8);
  third->value = 2;
  fourth = (astruct *)malloc(8);
  third->next = fourth;
  strcpy((char *)first->next,argv[1]);
  strcpy((char *)third->next,argv[2]);
  __stream = fopen("/home/user/level8/.pass","r");
  fgets(c,0x44,__stream);
  puts("~~");
  return 0;
}