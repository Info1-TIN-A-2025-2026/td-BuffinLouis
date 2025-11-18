#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

double kmh_to_ms(double v_kmh);
double reaction_distance(double speed, double reaction_time);
double break_distance(double speed, double deceleration);
double total_stop_distance(double speed, double reaction_time, double deceleration);
bool stop_before_obstacle(double stop_distance, double obstacle_distance);

int main(int argc, const char *argv[])
{
	// local variable
	double v_kmh = 0;
	double react_time = 0;
	double deceleration = 0;
	double dist_obstacle = 0;
	double disct_tot = 0;

	// Recuperation variable
	printf("Enter the speed [km/h]: ");
	scanf("%lf", &v_kmh);
	printf("Enter the reaction time [s]: ");
	scanf("%lf", &react_time);
	printf("Enter the deceleration [m/s^2]: ");
	scanf("%lf", &deceleration);
	printf("Enter the distance to the obstacle[m]: ");
	scanf("%lf", &dist_obstacle);

	// Vérification variables.

	disct_tot = total_stop_distance(v_kmh, react_time, deceleration);
	printf(" Total stop distance : 66.67 m => ");
	if (stop_before_obstacle(disct_tot, dist_obstacle))	{

	}
	else	{

	}
}

double kmh_to_ms(double v_kmh)
{
	assert(v_kmh >= 0);
	return v_kmh / 3.6;
}

double reaction_distance(double speed, double reaction_time)
{
	assert(reaction_time >= 0);
	return (speed * reaction_time);
}

double break_distance(double speed, double deceleration)
{
	assert(deceleration >= 0);
	return ((speed * speed) / (2. * deceleration));
}

double total_stop_distance(double speed, double reaction_time, double deceleration)
{
	double V_ms = kmh_to_ms(speed);
	printf("Speed : %.2lf km/h = %.2lf m/s\n", speed, V_ms);
	double dist_react = reaction_distance(V_ms, reaction_time);
	printf("Reaction distance : %.2lf m\n", dist_react);
	double dist_break = break_distance(V_ms, deceleration);
	printf("Break distance : %.2lf m\n", dist_break);
	return dist_react + dist_break;
}

bool stop_before_obstacle(double stop_distance, double obstacle_distance)
{
	if (stop_distance < obstacle_distance)	{
		printf("✅ no collision\n");
		return 1;
	}
	else	{
		printf("❌ collision\n");
		return 0;
	}
}
