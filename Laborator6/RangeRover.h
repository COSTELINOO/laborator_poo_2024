#pragma once
#include "Car.h"

class RangeRover :public Car
{
public:
	RangeRover();
	double computeRaceTime(unsigned int circuitLength, Weather condition);
	double lengthWithFuel();
};