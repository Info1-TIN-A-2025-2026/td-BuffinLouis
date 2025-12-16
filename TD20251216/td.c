// ------------------------------------------------------------
// Histogramme comme ca, tres utile pour le traitement d'image 
// ------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define W 4
#define H 4
#define L_HISTO 256
#define MAX_VALUE 255
#define MIN_VALUE 0
#define SEED 0

// function declaration
void Fill_matrix(unsigned char matrix[W][H], unsigned char min, unsigned char max);
void Display_matrix(unsigned char matrix[W][H]);
void Compute_Histo(unsigned char matrix[W][H], unsigned long histo[L_HISTO]);
void Display_Histo(unsigned long histo[L_HISTO]);

int main(int argc, const char *argv[])
{
	unsigned char f[W][H] = {0};
	unsigned long h[L_HISTO] = {0};

	srand(SEED);

	Fill_matrix(f, MIN_VALUE, MAX_VALUE);
	Display_matrix(f);
	Compute_Histo(f, h);
	Display_Histo(h);
	return 0;
}

// -------------------------------------------------------
// Rempli le tableau de donné
// -------------------------------------------------------
void Fill_matrix(unsigned char matrix[W][H], unsigned char min, unsigned char max)
{
	for (long row = 0; row < H; row++) {
		for (long col = 0; col < W; col++) {
			matrix[col][row] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
		}
	}
}

// -------------------------------------------------------
// Affiche le tableau donné
// -------------------------------------------------------
void Display_matrix(unsigned char matrix[W][H])
{
	for (long row = 0; row < H; row++) {
		for (long col = 0; col < W; col++) {
			printf("%4d", matrix[col][row]);
		}
		printf("\n");
	}
}

// -------------------------------------------------------
// Compte le nombre de donné X presente dans 
// -------------------------------------------------------
void Compute_Histo(unsigned char matrix[W][H], unsigned long histo[L_HISTO])
{
// --- Méthode 1: Gros Bourrin --- // (Plus lent, TROP lent)
// 	for (long row = 0; row < H; row++) {
// 		for (long col = 0; col < W; col++) {
// 			for (long i = 0; i < L_HISTO; i++) {
// 				if (matrix[row][col] == i) {
// 					histo[i] += 1;
// 				}
// 			}
// 		}
// 	}

// --- Méthode 2: Plus Inteligent --- //
	for (long row = 0; row < H; row++) {
		for (long col = 0; col < W; col++) {
			histo[matrix[row][col]] += 1;
		}
	}
}

// -------------------------------------------------------
// Affiche l'Histogramme de matrix
// -------------------------------------------------------
void Display_Histo(unsigned long histo[L_HISTO])
{
	for (long i = 0; i < L_HISTO; i++) {
		printf("%4ld:%2ld", i, histo[i]);
		printf("\n");
	}
}