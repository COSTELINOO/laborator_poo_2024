#include "RangeRover.h"
#include "Weather.h"
#include <iostream>

RangeRover::RangeRover()
{
	fuelCapacity = 60;				//specificam litri
	fuelConsumption = 13;			//consum la 100km
	avgSpeed[Weather::SUNNY] = 150;	//specie: km
	avgSpeed[Weather::RAIN] = 110;
	avgSpeed[Weather::SNOW] = 70;
}
double  RangeRover::computeRaceTime(unsigned int circuitLength, Weather condition)
{
	return (double)circuitLength / avgSpeed[condition];
}
double RangeRover::lengthWithFuel()
{
	return (double)fuelCapacity / fuelConsumption * 100.0;
}
