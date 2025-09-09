#include <stdio.h>
#include <stdlib.h>

// Prouve moi que c'est pas ça le code
int main(int argc, char **argv) {
	if (argc != 2) {
		return -1;
	}

	if (argv[1][0]) {
		puts("");
	} else {
		// shimi shimi ye shimi ya shimi ya
		system("/bin/sh");
	}
}
