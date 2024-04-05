#include "Seat.h"
#include "Weather.h"
#include <iostream>

Seat::Seat()
{
	fuelCapacity = 30;				//specificam litri
	fuelConsumption = 10;			//consum la 100km
	avgSpeed[Weather::SUNNY] = 110;	//specie: km
	avgSpeed[Weather::RAIN] = 75;
	avgSpeed[Weather::SNOW] = 60;
}
double Seat::computeRaceTime(unsigned int circuitLength, Weather condition)
{
	return circuitLength / avgSpeed[condition];
}

double Seat::lengthWithFuel()
{
	return (double)fuelCapacity / fuelConsumption * 100.0;
}

