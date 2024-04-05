#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "Circuit.h"
#include <iostream>
#include <cstring>

void Circuit::SetLength(unsigned int length)
{
	this->length = length;
}


void Circuit::SetWeather(Weather weather)
{
	this->condition = weather;
}

void Circuit::AddCar(Car *car)
{
	cars[nrCars++] = car;
}


void Circuit::Race()
{
	double aux[5][2];
	unsigned int i,j;
	for (i = 0; i < nrCars; i++)
	{
		
		aux[i][0] = cars[i]->computeRaceTime(length, condition);
		
		aux[i][1]=cars[i]->lengthWithFuel();
	}


	for (i = 0; i < nrCars; i++)
	for (j = i+1; j < nrCars; j++)
		if (aux[i][0] >= aux[j][0])
		{
			std::swap(aux[i][0], aux[j][0]);
			std::swap(aux[i][1], aux[j][1]);
			std::swap(cars[i],cars[j]);
			std::swap(carsName[i],carsName[j]);


		}

	for(i=0;i<nrCars;i++)
		if (aux[i][1] >= length)
		{
			strcpy(carsNameF[nrCarsF] , carsName[i]);
			carsTimeF[nrCarsF] = aux[i][0];

			nrCarsF++;
		}
		else
		{
			strcpy(carsNameDf[nrCarsDf], carsName[i]);

			nrCarsDf++;
		}


}

void Circuit::ShowFinalRanks()
{
	std::cout << "CLASAMENT MASINI CARE AU TERMINAT:" << '\n';

	if (nrCarsF == 0)
	{
		std::cout << "Nu avem masini care au terminat cursa" << '\n';
	}
	else
	{
		for (int i = 0; i < nrCarsF; i++)
		{
			
			std::cout << i + 1 << ". " << carsNameF[i] << ": " << carsTimeF[i] << ' ' << "unitati de timp;" << '\n';
		}
	}
}
void Circuit::ShowWhoDidNotFinish()
{
	std::cout << '\n';
	std::cout << "MASINI CARE NU AU TERMINAT:" << '\n';
	if (nrCarsDf == 0)
	{
		std::cout << "Toate masinile au terminat cursa" << '\n';
	}
	else
	{
		for (int i = 0; i < nrCarsDf; i++)
			std::cout << i + 1 << ". " << carsNameDf[i] << ";\n";
	}
}