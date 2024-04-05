#pragma once
#include "Car.h"

class Volvo:public Car
{
public:
	Volvo();
	double computeRaceTime(unsigned int circuitLength, Weather condition);
	double lengthWithFuel();
	
};