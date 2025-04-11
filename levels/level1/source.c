#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*gets(char *buffer);

void	run(void)
{
	puts("Good... Wait what?");
	(void)!system("/bin/sh");
	return ;
}

int	main(void)
{
	char	buffer[64];

	gets(buffer);
	return (0);
}
