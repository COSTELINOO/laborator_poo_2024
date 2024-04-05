#pragma once
#include "Car.h"

class Fiat :public Car
{
public:
	Fiat();
	double computeRaceTime(unsigned int circuitLength, Weather condition);
	double lengthWithFuel();
};