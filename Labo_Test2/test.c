/*
Feedback – Labo test 2 (analyse signal binaire)

Points positifs :
- count_rising_edge() : logique correcte pour compter les transitions
  0→1 et prise en compte du cas "signal commence par 1" via
  `count = signal[0]`. Complexité O(n).
- rle() : bonne idée globale (compter les runs consécutifs et afficher
  au fil de l’eau). Le calcul du taux num_samples/index est correct.

Points à corriger / améliorer (important) :
- max_length_high() :
  - Initialisation incorrecte : `current_lenhgt = signal[0]` vaut 0 ou 1
    alors qu’on veut une longueur (0 si on est sur 0, sinon 1 puis on
    incrémente). Ici ça donne des cas faux.
  - Bug logique : quand un run se termine, vous mettez à jour le max
    mais vous ne réinitialisez pas forcément current_lenhgt au bon
    endroit. Avec ce `else if (...)` vous laissez parfois la longueur
    de run inchangée alors qu’on devrait repartir sur la nouvelle
    valeur. Exemple : signal = 010111... peut produire un max erroné.
- max_length_low() :
  - L’initialisation est meilleure (`current_lenhgt = (signal[0] == 0)`),
    mais la même structure `else if (...) else ...` pose un souci :
    lorsque current_lenhgt > max_length_low, vous mettez à jour le max
    sans réinitialiser la longueur sur la nouvelle valeur. Cela peut
    générer des erreurs selon les transitions.
- Robustesse :
  - Vos boucles font `i < num_samples - 1`. Si num_samples == 1, cela
    devient `i < 0` (sous-flux en unsigned long) et la boucle devient
    incorrecte. Les tests incluent un signal de taille 1.
  - Il faut gérer explicitement num_samples == 0 et num_samples == 1
    dans ces fonctions.

- rle() (format) :
  - Le format attendu dans les tests est sans virgule finale :
    `rle: 0,2,3,2` (pas `rle: 0,2,3,2,`). Ici vous imprimez une virgule
    après la valeur initiale systématiquement. Ensuite vous imprimez
    aussi des valeurs suivies de virgule dans la boucle, puis la
    dernière sans virgule : sur certains cas, ça peut laisser une
    virgule en trop selon le chemin.
  - Types : vous stockez les compteurs dans `char rle[num_samples]`,
    ce n’est pas idéal (risque si un run > 127 et char signé). Mieux :
    unsigned long, ou ne pas stocker du tout.

Bilan :
- Les fronts montants et l’idée du RLE sont corrects.
- Les fonctions max_length_* sont fragiles et peuvent produire des
  résultats faux, et il manque la gestion correcte de num_samples==1.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long max_length_state(const char *signal, const unsigned long num_samples, const char state);


unsigned long max_length_high(const char *signal, const unsigned long num_samples) {

    // int max_length_high = 0;
    // int current_lenhgt = signal[0];

    // for (unsigned long i = 0; i < num_samples - 1; i++) {
    //     if ((signal[i] == 1) && (signal[i+1] == 1)) {
    //         current_lenhgt++;
    //     }
    //     else if ( current_lenhgt > max_length_high) {
    //         max_length_high = current_lenhgt;
    //     }
    //     else {
    //         current_lenhgt = signal[i+1];
    //     }
    // }
    // if ( current_lenhgt > max_length_high) {
    //     max_length_high = current_lenhgt;
    // }

    // return max_length_high;

	return max_length_state(signal, num_samples, 1);
}

unsigned long max_length_low(const char *signal, const unsigned long num_samples) {

    // int max_length_low = 0;
    // int current_lenhgt = (signal[0] == 0);

    // for (unsigned long i = 0; i < num_samples - 1; i++) {
    //     if ((signal[i] == 0) && (signal[i+1] == 0)) {
    //         current_lenhgt++;
    //     }
    //     else if ( current_lenhgt > max_length_low) {
    //         max_length_low = current_lenhgt;
    //     }
    //     else {
    //         current_lenhgt = (signal[i+1] == 0);
    //     }
    // }
    // if ( current_lenhgt > max_length_low) {
    //     max_length_low = current_lenhgt;
    // }
    // return max_length_low;

	return max_length_state(signal, num_samples, 0);
}

unsigned long count_rising_edge(const char *signal, const unsigned long num_samples) {

    // unsigned char count = signal [0];

    // for (unsigned long i = 0; i < num_samples - 1; i++) {
    //     if ((signal[i] == 0) && (signal[i+1] == 1)) {
    //         count++;
    //     }
    // }
    //return count;

	unsigned long count = signal[0];
	for (unsigned long i = 1; i < num_samples;i++) {
		count += !signal[i - 1] && signal[i];
	}
	return count;
}

void rle(const char *signal, const unsigned long num_samples) {

    // int current_lenhgt = 1;
    // char rle[num_samples];
    // double compression = 0;
    // for (unsigned long a = 0; a < num_samples ; a++) {
    //     rle [a] = 0;
    // }
    // rle [0] = signal[0];
    // printf("rle: %d,",rle [0]);
    // int index = 1;

    // for (unsigned long i = 0; i < num_samples - 1; i++) {
    //     if (signal[i] == signal[i+1]) {
    //         current_lenhgt++;
    //     }
    //     else {
    //         rle[index] = current_lenhgt;
    //         printf("%d,",rle [index]);
    //         index++;
    //         current_lenhgt = 1; 
    //     }
    // }
    // rle[index] = current_lenhgt;
    // printf("%d\n", rle [index]);
    // index++;
    // printf("num symbols in rle: %d\n",index);

    // compression = (double)num_samples / index;
    // printf("compression rate: x%.1lf",compression);
	unsigned long count = 1;
  unsigned long symbols = 0;
  char states = signal[0];
  printf("%d", states);
	for (unsigned long i = 1; i < num_samples;i++) {
		if(signal[i-1] == signal[i]) {
			count++;
		}
		else {
			printf("%lu", count);
      count = 1;
      states = 1 - states;
    }
  }
  printf("%lu\n", count);
  symbols++;
  printf("num symbols in rle: %lu\n",symbols);
  printf("compression rate: x%.1lf",(double)num_samples / symbols);
}

// en plus, ajouter.
unsigned long max_length_state(const char *signal, const unsigned long num_samples, const char state) {

	unsigned long max_count = state;
	unsigned long count = 0;
	for (unsigned long i = 0; i < num_samples;i++) {

		count += signal[i] == state;
		max_count = count > max_count ? count : max_count;
		count = signal[i] == 0 ? 0 : count;
	}
	return max_count;
}