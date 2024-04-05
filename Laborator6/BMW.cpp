#include "BMW.h"
#include "Weather.h"
#include <iostream>

BMW::BMW()
{
	fuelCapacity = 35;				//specificam litri
	fuelConsumption = 18;			//consum la 100km
	avgSpeed[Weather::SUNNY] = 170;	//specie: km
	avgSpeed[Weather::RAIN] = 140;
	avgSpeed[Weather::SNOW] = 100;
}
double  BMW::computeRaceTime(unsigned int circuitLength, Weather condition)
{
	return (double)circuitLength / avgSpeed[condition];
}
double BMW::lengthWithFuel()
{
	return (double)fuelCapacity / fuelConsumption * 100.0;
}

