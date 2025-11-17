#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>


// Prototype de fonction
void Delta(const double a,const double b,const double c);


int main(int argc, const char *argv[])
{
	// local variable
	double a = 0;
	double b = 0;
	double c = 0;

	printf("Enter 3 real value: ");
	scanf("%lf%lf%lf", &a, &b, &c);

	Delta(a,b,c);
	return 0;
}


void Delta(const double a,const double b,const double c)
{
	double Delta = b * b - 4 * a * c;
	printf("Delta = %.2lf\n", Delta);
}


