#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, const char *argv[])
{
	// local variable
	// constante
	const uint16_t SEC_TO_MIN = 60;			// 60
	const uint16_t SEC_TO_HOUR = 3600;		// 60*60
	const uint32_t SEC_TO_DAY = 86400;	 	// 3600*24 heures, jours = 86400;
	const uint32_t SEC_TO_WEEK = 640800;	// 3600*24*7 heures, jours, semaines
	const uint8_t SECONDES = 60;
	const uint8_t MINUTES = 60;
	const uint8_t HOURS = 24;
	const uint8_t DAYS = 7;
	const uint64_t OVERFLOW = 31449600; 	// 60*60*24*7*52 

	int64_t Input_second = 0;				// number of second enter by user
	uint32_t rst = 0;						// variable for intermediaire calcul
	uint8_t nb_second = 0;					// result seconds
	uint8_t nb_minute = 0;					// result minutes
	uint8_t nb_hour = 0;					// result hours
	uint8_t nb_days = 0;					// result days
	uint8_t nb_week = 0;					// result week

	// ask number of second for conversion
	printf("Number of seconds:");
	scanf("%ld", &Input_second);

	// gestion des erreurs
	if (Input_second < 0){
		printf("Error: negative number \n");
	} else if (Input_second >= OVERFLOW){
		printf("Error: Number too big. Overflow \n");
	} else {
		// no input error, begin convert
		// find seconds
		nb_second = Input_second % SECONDES;

		// find minutes
		rst = Input_second / SEC_TO_MIN;
		nb_minute = rst % MINUTES;

		// find hour
		rst = Input_second / SEC_TO_HOUR;
		nb_hour = rst % HOURS;

		// find days
		rst = Input_second / SEC_TO_DAY;
		nb_days = rst % DAYS;

		//find week
		nb_week = Input_second / SEC_TO_WEEK;

		// Disp result
		printf("%ld Number of seconds: %d semaines, %d jours, %d heures, %d minutes, %d secondes\n",
        Input_second,nb_week, nb_days, nb_hour, nb_minute, nb_second);
	}

	return 0;
}