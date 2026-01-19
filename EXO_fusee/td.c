// Revu code TEST 2 INFO

#include <stdio.h>
#include <math.h>
 
#define VE 				4000	// 4 000 m/s
#define Total_MASS		750000	// 750 000 kg
#define empty_MASS		90000	// 90 000 kg
 
int main(int argc, const char *argv[])
{
	long time = 0;
	long current_weight = Total_MASS;
	long next_weight = 0;
	long MASS_consom = 0;
	double altitude = 0;
	double current_speed = 0.;
	double next_speed = 0;

	printf("  time |  weight  |  speed  | mass_conso | altitude\n");
	printf("  %ld |  %ld  |  %ld  | %ld | %ld\n", time, current_weight, current_speed, Total_MASS-current_weight, altitude);

	do
	{
		/* code */
	} while ();
	
}
