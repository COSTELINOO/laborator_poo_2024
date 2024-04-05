#pragma once
#include "Car.h"

class Seat :public Car
{
public:
	Seat();
	double computeRaceTime(unsigned int circuitLength, Weather condition);
	double lengthWithFuel();
	
};