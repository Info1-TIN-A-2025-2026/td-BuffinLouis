#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>


#define SOLVE   "--solve"
#define COMPUTE "--compute"
#define HELP    "-h"
#define HELPP   "--help"

int main(int argc, char* argv[])
{
  // Variable
  char *endptr;           // Pour les conversion de char en double
  double a = 0;
  double b = 0;
  double c = 0;
  double x = 0;
  double y = 0;
  double delta = 0;
  double x1 = 0;
  double x2 = 0;
  double Re = 0;          // Partie reel
  double Im = 0;          // Partie Imaginaire

  // Si on a moins de 2 argument alors erreur
  if (argc < 2) {
    printf("Bad argument(s).\n");
    return 1;
  }

  // Mode calcul de y = ax² + bx + c
  if (strcmp(argv[1], COMPUTE) == 0) {
      // Je vérifie qu'il y a 5 arguments au total
      if (argc != 6) {
        printf("Bad argument(s).\n");
        return 1;
      }
      // récupérer a,b,c,x et verifier qu'il soit correct
      // Conversion des chaînes argv[2..4] en double et erreur 
      a = strtod(argv[2], &endptr);
      if (*endptr != '\0' || isnan(a)) {
        printf("Bad argument(s).\n");
        return 1;
      }
      b = strtod(argv[3], &endptr);
      if (*endptr != '\0' || isnan(b)) {
        printf("Bad argument(s).\n");
        return 1;
      }
      c = strtod(argv[4], &endptr);
      if (*endptr != '\0' || isnan(c)) {
        printf("Bad argument(s).\n");
        return 1;
      }
      x = strtod(argv[5], &endptr);
      if (*endptr != '\0' || isnan(x)) {
      printf("Bad argument(s).\n");
      return 1;
    }
    // faire le calcul
    y = a * x * x + b * x + c;
    printf("y = %+.6lf\n", y);
  }

  else if (strcmp(argv[1], SOLVE) == 0) {
    // Mode résolution d’équation
    // Je vérifie qu'il y a 4 arguments au total
    if (argc != 5) {
        printf("Bad argument(s).\n");
        return 1;
    }
    // Conversion des chaînes argv[2..4] en double et erreur 
    a = strtod(argv[2], &endptr);
    if (*endptr != '\0' || isnan(a)) {
      printf("Bad argument(s).\n");
      return 1;
    }
    b = strtod(argv[3], &endptr);
    if (*endptr != '\0' || isnan(b)) {
      printf("Bad argument(s).\n");
      return 1;
    }
    c = strtod(argv[4], &endptr);
    if (*endptr != '\0' || isnan(c)) {
      printf("Bad argument(s).\n");
      return 1;
    }
    // Si le nombre a est incorect
    if (a == 0) {
      printf("Bad argument(s).\n");
      return 1;
    }
    // résoudre l’équation
    // Etape 1, le discriminant
    delta = b * b - 4 * a * c;

    // si delta SUP ou == 0 alors classique.
    if (delta > 0)  {
      x1 = (-b + sqrt(delta)) / (2 * a);
      x2 = (-b - sqrt(delta)) / (2 * a);
      printf("x1 = %+.5lf\n", x1);
      printf("x2 = %+.5lf\n", x2);
    }
    else if (delta == 0)  {
      x1 = -b / (2 * a);
      printf("x1 = x2 = %+.5lf\n", x1);
    }
    else  {
      // x1 = -b / (2 * a) + j * (sqrt(-delta) / (2 * a));
      // x2 = -b / (2 * a) - j * (sqrt(-delta) / (2 * a));
      Re = -b / (2 * a);
      Im = (sqrt(-delta) / (2 * a));

      // Si Reel == 0
      if (fabs(Re) < 1e-6 )  {      // est - ce que le reel est très proche de 0 ? 

        // cherche la valeur absolu de l'image       
        // est - ce que imag est très proche de 1 ?     
        if (fabs(Im - 1) < 1e-6)  {
          printf("x1 = + j\n");
          printf("x2 = - j\n");
        }   
        // est - ce que imag est très proche de -1 ? 
        else if (fabs(Im + 1) < 1e-6) {
          printf("x1 = - j\n");
          printf("x2 = + j\n");
        }
        // diff +1,-1
        else  {
          printf("x1 = %+0.5fj\n", Im);
          printf("x2 = %+0.5fj\n", -Im);
        }
      }
      else  {

        // cherche la valeur absolu de l'image       
        // est - ce que imag est très proche de 1 ? 0.000000001    
        if (fabs(Im - 1) < 1e-6)  {
          printf("x1 = %+0.5f + j\n", Re);
          printf("x2 = %+0.5f - j\n", Re);
        }   
        // est - ce que imag est très proche de -1 ? 
        else if (fabs(Im + 1) < 1e-6) {
          printf("x1 = %+0.5f - j\n", Re);
          printf("x2 = %+0.5f + j\n", Re);
        }
        // diff +1,-1
        else  {
          printf("x1 = %+0.5f %+0.5fj\n", Re, Im);
          printf("x2 = %+0.5f %+0.5fj\n", Re, -Im);
        }
      }
    }
  }

  else if (strcmp(argv[1], HELP) == 0 || strcmp(argv[1], HELPP) == 0) {
    // Si on a plus de 2 argument alors erreur
    if (argc > 2) {
      printf("Bad argument(s).\n");
      return 1;
    }
    // Affichage de l’aide
    printf("usage: ./app -h \n");
    printf("    or ./app --help \n");
    printf("    or ./app --compute a b c x \n");
    printf("    or ./app --solve a b c\n");
    printf("\nFinancial computation.\n");
    printf("    -h          display this message\n");
    printf("    --help      display this message\n");
    printf("    --compute   non interactive mode, followed by the values of a, b, c and x ; compute the value y=ax^2+bx+c\n");
    printf("    --solve     non interactive mode, followed by the values of a, b, and c ; compute the value(s) of x where ax^2+bx+c=0\n");
    return 0;
  }

  else {
    printf("Bad option.\n");
    return 2;
  }
  printf("\n");
  return 0;
}
