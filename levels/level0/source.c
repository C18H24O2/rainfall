#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	// The real program does not check if argc is 1, so this does segfault
	// if no argument is provided.
	const int i = atoi(argv[1]);

	if (i == 423) {
		execl("/bin/sh", "sh", NULL);
	} else {
		printf("No !\n");
	}
	return (0);
}
