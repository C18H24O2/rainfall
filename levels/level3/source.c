#include <stdio.h>
#include <stdlib.h>

int m = 0;

void main(void)
{
	char buffer[520];

	fgets(buffer, 512, stdin);
	printf(buffer);

	if (m == 64) {
		fwrite("Wait what?!\n", 1, 0xc, stdout);
		system("/bin/sh");
	}
	return;
}
