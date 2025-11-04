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
		int ret = 0;

		printf("Enter a number between [%d..%d]: ", V_MIN, V_MAX);
		ret = scanf("%d", &i);
		// si le scanf ne peut pas mettre a jour variable.
		if (ret != 1)
		{
			// Vider le buffer clavier
			// Méthode 1
			while (getchar() != '\n') {}
			// Méthode 1
			// char c = 0;
			// do
			// {
			// 	c = getchar();
			// } while (c != '\n');
		}

	} while ((i < V_MIN) || (i > V_MAX));

	printf("i=%d\n", i);

	return 0;
}