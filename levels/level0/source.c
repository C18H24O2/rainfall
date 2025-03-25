// vim: set ft=c:

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	const int i = atoi(argv[1]);

	if (i == 423) {
		execl("/bin/sh", "sh", NULL);
	} else {
		printf("No !\n");
	}
	return (0);
}
