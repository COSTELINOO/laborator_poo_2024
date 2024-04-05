#include "Fiat.h"
#include "Weather.h"
#include <iostream>

Fiat::Fiat()
{
	fuelCapacity = 25;				//specificam litri
	fuelConsumption = 6;			//consum la 100km
	avgSpeed[Weather::SUNNY] = 110;	//specie: km
	avgSpeed[Weather::RAIN] = 80;
	avgSpeed[Weather::SNOW] = 70;
}
double Fiat::computeRaceTime(unsigned int circuitLength, Weather condition)
{
	return (double)circuitLength / avgSpeed[condition];
}
double Fiat::lengthWithFuel()
{
	return (double)fuelCapacity / fuelConsumption * 100.0;
}
