// ------------------------------------------------------------
// Histogramme comme ca, tres utile pour le traitement d'image 
// ------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define W 		16
#define H 		16
#define SEED	0


// function declaration
void Fill_matrix(unsigned char matrix[W][H]);
void Display_matrix(unsigned char matrix[W][H]);
void Dilation(unsigned char f[W][H], unsigned char g[W][H]);
void Soustraction(unsigned char f[W][H], unsigned char g[W][H], unsigned char result[W][H]);

int main(int argc, const char *argv[])
{
	unsigned char f[W][H] = {0};
	unsigned char g[W][H] = {0};
	unsigned char r[W][H] = {0};

	srand(SEED);

	Fill_matrix(f);
	Display_matrix(f);

	printf("\n\n");

	Dilation(f, g);
	Display_matrix(g);

	printf("\n\n");

	Soustraction(f, g, r);
	Display_matrix(r);

	return 0;
}

// -------------------------------------------------------
// Rempli le tableau de donné
// -------------------------------------------------------
void Fill_matrix(unsigned char matrix[W][H])
{
	for (long row = 4; row < 12; row++) {
		for (long col = 4; col < 12; col++) {
			matrix[row][col] = 255;
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
// Dilate l'image transmit (agrandi de 1)
// -------------------------------------------------------
void Dilation(unsigned char f[W][H], unsigned char g[W][H])
{
	for (long row = 1; row < H-1; row++) {
		for (long col = 1; col < W-1; col++) {
			if (f[row][col] > 0) {
				for (long delta_row = -1; delta_row <= 1; delta_row++) {
					for (long delta_col = -1; delta_col <= 1; delta_col++) {
						g[row + delta_row][col + delta_col] = 255;
					}
				}
			}
		}
	}
}

// -------------------------------------------------------
// Affiche le tableau donné
// -------------------------------------------------------
void Soustraction(unsigned char f[W][H], unsigned char g[W][H], unsigned char result[W][H])
{
	for (long row = 0; row < H; row++) {
		for (long col = 0; col < W; col++) {
			result[row][col] = g[row][col] - f[row][col];
		}
	}
}
