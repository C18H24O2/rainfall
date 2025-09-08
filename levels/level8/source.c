#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>

char *auth;
char *service;

int main(int argc, char **argv) 
{
	char 		line[128];

	do {
		printf("%p, %p \n", auth, service);

		if(fgets(line, sizeof(line), stdin) == NULL) break;

		if(strncmp(line, "auth ", 5) == 0) 
		{
			auth = malloc(4);
			memset(auth, 0, 4);
			if(strlen(line + 5) < 31) 
			{
				strcpy(auth, line + 5);
			}
		}
		if(strncmp(line, "reset", 5) == 0) 
		{
			free(auth);
		}
		if(strncmp(line, "service", 6) == 0) 
		{
			service = strdup(line + 7);
		}
		if(strncmp(line, "login", 5) == 0) 
		{
			if(*auth) 
			{
				system("/bin/sh");
			} else 
			{
				fprintf(stdout, "Password:\n");
			}
		}
	} while (1);
	return 0;
}
