#pragma once
#pragma once
#include "Car.h"

class BMW :public Car
{
public:
	BMW();
	double computeRaceTime(unsigned int circuitLength, Weather condition);
	double lengthWithFuel();
	
};