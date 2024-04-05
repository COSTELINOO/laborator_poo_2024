#include "Volvo.h"
#include "Weather.h"
#include <iostream>

Volvo::Volvo()
{
	fuelCapacity = 40;				//specificam litri
	fuelConsumption = 8;			//consum la 100km
	avgSpeed[Weather::SUNNY]=120;	//specie: km
	avgSpeed[Weather::RAIN] = 100;
	avgSpeed[Weather::SNOW] = 80;
}
double Volvo::computeRaceTime(unsigned int circuitLength,Weather condition)
{
	return (double)circuitLength/avgSpeed[condition];
}
double Volvo::lengthWithFuel()
{
	return (double)fuelCapacity / fuelConsumption * 100.0;
}

