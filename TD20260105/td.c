#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

int main(int argc, const char *argv[])
{
	// crée une chaine de caractere.
	char S1[] = "mot";

	// crée un tableau e caractere. 
	// char S2[3] = {'m', 'o', 't'};

//	La diîfférence vient de ce qu'il y a en memoire.
//	Pour S1, il y a en memoire : m, o, t, \0
//	Pour S2, il y a en memoire : m, o, t

//  Mais donc si on fait char S2[4] = {'m', 'o', 't', '\0'};
//	 c'est aussi une chaine de cararctere.
	puts("//---------- S1 -------------//");

	printf("Memory size  : %ld\n", sizeof(S1));
	printf("num_cells    : %ld\n", sizeof(S1) / sizeof(char));

	// obtenir la longeur d'une chaine
	unsigned long count = 0;
	while (S1[count]!=0)
	{
		count++;
	}
	printf("string_lenght: %lu\n", count);

	// sinon si on utilise string.h
	printf("string_lenght: %lu\n", strlen(S1));

	char S3[100] = "mot";
	puts("//---------- S3 -------------//");
	printf("Memory size  : %ld\n", sizeof(S3));
	printf("string_lenght: %lu\n", strlen(S3));

	char *s3 = "c'est juste une illusion, a peine une sensation, qui dirrige tes pas et te montre du doigt.Ou tu vas, Ou tu vas. C'est juste une illusion, comme une bulle de savon";		// s3 contient l'addresse d'un char
	puts("//---------- s3 -------------//");
	printf("Memory size  : %ld\n", sizeof(s3));
	printf("string_lenght: %lu\n", strlen(s3));

	char S4[] = "lorem ipsum dolor sit amet, "
				"consectur adipiscing elit. Sed non risus."
				"Suspendisse lectus tortor, dignissim sit amet,"
				"adipiscing nec, ultricies sed, dolor.";
	puts("//---------- S4 -------------//");
	printf("Memory size  : %ld\n", sizeof(S4));
	printf("string_lenght: %lu\n", strlen(S4));


	// affiche ca
	char S5[] = "ABC";
	puts("//---------- S5 -------------//");
	unsigned long Index = 0;
	// avec for
	for (Index = 0; Index < strlen(S5) + 1; Index++)
	{
		printf("%2c ", S5[Index]);
	}
	puts("");

	// avec do_while
	do
	{
		printf("%3d ", S5[Index]);
	} while (S5[Index++] != 0);
	puts("");

	char S6[][10] = {
		// 3 * 10 char (9 +\0) = 30 bytes.
		"ABC",
		"DEF",
		"HIJ",
		"KLMNOP",
	};

	char *S7[] = {		// 3 * 10 char (9 +\0) = 30 bytes.
		"ABC",
		"DEF",
		"HIJ",
		"KLMNOP",
	};

	char S8[1000];
	scanf("%s", S8);
	int a0sivrai = strcmp(S8, "pipo");

	return 0;
}