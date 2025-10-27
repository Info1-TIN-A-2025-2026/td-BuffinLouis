#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, const char *argv[])
{
	// Variable locale
	int16_t a = 0;
	int16_t b = 0;
	int16_t q = 0;
	int16_t r = 0;

	printf("a = ");
	scanf("%hd", &a);
	printf("b = ");
	scanf("%hd", &b);

	q = a / b;
	r = a % b;

	printf("\n\n");
	printf("Quotient= %hd\n", q);
	printf("Reste= %hd\n", r);

	return 0;
}