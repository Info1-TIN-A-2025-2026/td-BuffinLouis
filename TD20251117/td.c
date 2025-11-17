#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

// Define

// Prototype de fonction
void proc(void);
void F1(const int a);

// Global variable

int main(int argc, const char *argv[])
{
	// constante

	// local variable
	int i = 0;

	proc();
	printf("Enter a integrer value: ");
	scanf("%d", &i);
	F1(i);
	return 0;
}

// proc car fonction qui ne prend pas de parrametre et n'en retourne pas.
// On appelle cela des procédures.
void proc(	void )
{
	puts("salut");
	return;
}

void F1 (const int a)
{
	printf("a*3 = %d \n", 3*a);

}
