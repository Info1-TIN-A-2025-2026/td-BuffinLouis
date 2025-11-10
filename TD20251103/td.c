#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, const char *argv[])
{
	/*//variable locale
	unsigned long N = 0;
	uint8_t W = 0;

	N = atoll(argv[1]);
	printf("Le nombre %ld, ", N);

	while (N > 0)
	{
		N = N / 10;
		W++;
	}

	printf("se represente avec %d digits.\n\n", W);*/


	// variable locale
	unsigned int N = atoll(argv[1]);
	unsigned int R = 0;

	printf("Le nombre %d s'inverse : \n", N);

	do
	{
		R *= 10;
		R += (N % 10);
		N = N / 10;
	} while (N>0);

	printf("%d \n", R);

	return 0;
}