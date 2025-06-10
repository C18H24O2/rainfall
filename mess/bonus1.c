#include <stdint.h>
int main(int argc, char **argv) {
	int32_t a = atoi(argv[1]);
	a *= 4;
	printf("%d\n", a);
}
