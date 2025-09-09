#include <stdio.h>
#include <string.h>
#include <unistd.h>

void p(char *str, char *msg)
{
  char buf[4096];
 
  puts(msg);
  read(0, buf, 0x1000);
  char *end = strchr(buf, '\n');
  end = 0;
  strncpy(str, buf, 20);
}
 
void pp(char *str) 
{
  char last[20];
  char first[20];
 
  p(first, " - ");
  p(last, " - ");
 
  strcpy(str, first);
  strcat(str, " ");
  strcat(str, last);
}
 
int main(int argc, char **argv)
{
  char str[54];
 
  pp(str);
  puts( str);
  return 0;
}
