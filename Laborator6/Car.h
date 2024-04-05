#pragma once
#include "Weather.h"

class Car
{

protected:
	unsigned int fuelCapacity;
	unsigned int fuelConsumption;
	unsigned int avgSpeed[3];

public:
	virtual double computeRaceTime(unsigned int circuitLength, Weather condition)=0;
    virtual double lengthWithFuel()=0;

};