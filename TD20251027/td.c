#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, const char *argv[])
{
	/*// Variable locale
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
	printf("Reste= %hd\n", r);*/

	// NOMBRE PREMIER
	printf("Liste des 100 premiers nombre premier.\n");
	printf("1, ");
	// Variable
	uint8_t i = 0;
	uint8_t j = 0;
	const uint8_t I_Min = 2;
	const uint8_t I_Max = 100;
	bool est_premier = true;

	for (i = I_Min; i <= I_Max; i++)
	{
		est_premier = true;
		for (j = I_Min; j <= i-1;j++)
		{
			if ((i % j) == 0)
			{
				est_premier = false;
			}
		}
		if (est_premier)
		{
			printf("%u, ", i);
		}
	}
	printf("\n");

	return 0;
}