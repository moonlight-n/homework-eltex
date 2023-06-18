#include <stdio.h>

int main() {
	int a = 270533154;
	char *p;

	p = &a;

	printf("first byte of a = %d\n", *p);
	p++;
	printf("second byte of a = %d\n", *p);
	p++;
	printf("third byte of a = %d\n", *p);
	p++;
	printf("fourth byte of a = %d\n", *p);

	p = &a;
	*(p+2) = 25;
	printf("number with 3 bytes changed = %d\n", *p);

	return 0;
}