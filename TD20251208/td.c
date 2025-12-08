#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <time.h>


int main(int argc, const char *argv[])
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", RAND_MAX);
	}

	return 0;
}