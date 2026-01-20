#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

int F1(uint32_t t, int *a, int *b, int *c);

int main(int argc, const char *argv[])
{
	int s = 0;
	int m = 0;
	int h = 0;
	int t = 1234567;
	// printf("address of argc= %p\n", &argc);
	printf("address of h= %p\n", &h);
	printf("address of m= %p\n", &m);
	printf("address of s= %p\n", &s);

	int r = F1(t, &h, &m, &s);

	return 0;
}

int F1(uint32_t t, int *a, int *b, int *c)
{
	printf("a= %p\n", &a);
	printf("b= %p\n", &b);
	printf("c= %p\n", &c);
	return 0;
}
