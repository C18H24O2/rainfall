#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char c[80];

typedef struct t_list {
    struct t_list *next;
    int value;
} t_list;

int main(int argc,char **argv)

{
  t_list *first;
  t_list *second;
  t_list *third;
  t_list *fourth;
  FILE *__stream;
  
  first = (t_list *)malloc(8);
  first->value = 1;
  second = (t_list *)malloc(8);
  first->next = second;
  third = (t_list *)malloc(8);
  third->value = 2;
  fourth = (t_list *)malloc(8);
  third->next = fourth;
  strcpy((char *)first->next,argv[1]);
  strcpy((char *)third->next,argv[2]);
  __stream = fopen("/home/user/level8/.pass","r");
  fgets(c,0x44,__stream);
  puts("~~");
  return 0;
}
