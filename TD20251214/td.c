#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define NB_CELLULES			1000
#define MIN_VALUE			-100
#define MAX_VALUE			100

double generate_random_real_value(const double min_value, const double max_value);

int main(int argc, const char *argv[])
{
	int vroum[NB_CELLULES];
	long Index = 0;
	int v_vroum = 0;

	printf("Cherche la valeur: ");
	scanf("%d", &v_vroum);

	if ((v_vroum > MAX_VALUE) || (v_vroum < MIN_VALUE)) {
		printf("Bad arguments.\n");
		return 1;
	}

	srand(0);

	for (long N = 0; N <= NB_CELLULES;N++)
	{
		vroum[N] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
		// printf("%4lu, %4d\n", N, vroum[N]);
	}

	while (vroum[Index] != v_vroum)
	{
		Index++;
	}

	printf("touver a la case: %ld\n", Index);

	return 0;
}


// -------------------------------------------------------
// Génére un nombre aléatoire réel
// -------------------------------------------------------
double generate_random_real_value(const double min_value, const double max_value)
{
  return min_value + ((double)rand() / (double)RAND_MAX) * (max_value - min_value);
}

