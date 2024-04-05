#pragma once
#include "Weather.h"
#include "Car.h"

class Circuit
{
private:
	unsigned int length;
	Weather condition;
	Car *cars[5];
	char carsName[5][11] = {"Volvo","BMW","Seat","Fiat","RangeRover"};
	char carsNameF[5][11];
	double carsTimeF[5];
	char carsNameDf[5][11];

	unsigned int nrCars=0;
	unsigned int nrCarsF = 0;
	unsigned int nrCarsDf = 0;

public:
	
	void SetLength(unsigned int length);
	void SetWeather(Weather weather);

	void AddCar(Car * car);
	void Race();
	void ShowFinalRanks();
void ShowWhoDidNotFinish();
};
