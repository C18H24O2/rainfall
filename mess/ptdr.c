#include <stdio.h>

int main(void) {
	short int a;
	short int b;

	a = 0;
	b = 0;

	char buf[1000];

	fgets(buf, 1000, stdin);
	printf(buf, 0, 0, 0, &a, 0, &b);
	printf("\na: %hd\nb: %hd\n", a, b);
	return 0;
}
