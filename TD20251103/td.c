#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, const char *argv[])
{
	//variable locale
	unsigned long N = 0;
	uint8_t W = 0;

	N = atoll(argv[1]);
	printf("Le nombre %ld, ", N);

	while (N > 0)
	{
		N = N / 10;
		W++;
	}

	printf("se represente avec %d digits.\n\n", W);

	return 0;
}