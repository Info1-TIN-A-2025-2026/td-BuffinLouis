#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, const char *argv[])
{
	// Constante
	const int V_MIN = 10;
	const int V_MAX = 20;

	// Variable locale
	int i = 0;

	do
	{
		printf("Enter a number between [10..20]: ");
		scanf("%d", &i);
	} while ((i < V_MIN) || (i > V_MAX));

	printf("i=%d\n", i);

	return 0;
}