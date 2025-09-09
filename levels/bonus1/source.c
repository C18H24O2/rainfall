#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	char buffer[40];
	int i;

	i = atoi(argv[1]);
	if (i < 100)
	{
		memcpy(buffer, argv[2], i * 4);
		if (i == 1464814662)
			execl("/bin/sh", "sh", 0);
		return 0;
	}
	return 1;
}
