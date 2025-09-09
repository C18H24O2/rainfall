#include <stdio.h>
#include <stdint.h>
#include <limits.h>

// bruteforce lol

int main(int argc, char **argv) {
	int32_t a = INT_MIN;
	while (42) { // référence à l'école la ouais
		if (a * 4 == 44) {
			printf("good ending: %d\n", a);
			return 0;
		}
		a++;
	}
	return 1;
}
