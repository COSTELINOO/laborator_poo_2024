#include "Number.h"
#include <cstring>
#include<iostream>
Number::Number(int x)
{
	int aux = x;
	char* aux1 = new char[100] {};
	strNumber = new char[100];
	nrBase = 10;
	int i = 0;
	while (aux>0)
	{
		aux1[i] = aux % 10 + '0';
		aux /= 10;
		i++;

	}
	aux1[i] = '\0';
	i--;
	for (int j = 0; j <= i; j++)
		strNumber[j] = aux1[i - j];
	strNumber[i + 1] = '\0';
	strNumberLen = i+1;
	
}

void Number::operator --(int)
{
	if (strNumberLen > 0)
	{
		strNumberLen--;
		strNumber[strNumberLen] = '\0';
	}

}

void Number :: operator --()
{
	for (int i = 0; i < strNumberLen - 1; i++)
		strNumber[i] = strNumber[i + 1];

	if (strNumberLen > 0)
		strNumberLen--;


	
}

Number::Number(const char * x)
{
	
	
	nrBase = 10;
	
	strcpy(strNumber, x);
	strNumberLen = strlen(strNumber);

}

Number::Number(const char* value, int base)
{
	strNumber = new char[100] {};// '\0' peste tot

	//varianta C
	//strNumber = (char*)malloc(100 * sizeof(char));

	strcpy(strNumber, value);

	nrBase = base;

	strNumberLen = strlen(strNumber);

}

void Number::Print()
{
	std::cout << "Numar: " << strNumber << " cu baza " << nrBase << '\n';
}

Number :: ~Number()
{
	delete[] strNumber; // sterge toate carcaterele
	// delete strNumber sterge doar un caracter

	strNumber = nullptr;
}

int Number::GetDigitsCount()const
{
	return strNumberLen;
}

unsigned int Number::GetBase10Value() const
{
	unsigned int result = 0, power = 1;
	int i;
	for (i = strNumberLen - 1; i >= 0; i--)
	{
		if(strNumber[i]>='0'&&strNumber[i]<='9')
			result = result + (strNumber[i] - '0') * power;
		else
			result = result + (strNumber[i] - 'A'+10) * power;

		power = power * nrBase;
	}

	return result;
}

bool Number::operator <(const Number& otherNumer)
{
	return GetBase10Value() < otherNumer.GetBase10Value();
}

bool Number::operator >(const Number& otherNumer)
{
	return GetBase10Value() > otherNumer.GetBase10Value();
}

char Number::operator [](const int i)
{
	return strNumber[i];
}

char * Number::Get_Number() const
{
	return strNumber;
}

int Number::GetBase() const
{
	return nrBase;
}

void Number::operator = (const Number& otherNumer)
{
	strcpy(strNumber, otherNumer.Get_Number());
	nrBase = otherNumer.GetBase();
	strNumberLen = otherNumer.GetDigitsCount();

}

void Number::operator = (const char* x)
{
	strcpy(strNumber, x);
	strNumberLen = strlen(x);
	nrBase = 10;
}

void Number::operator = (const int x)
{
	int aux = x;
	char* aux1 = new char[100] {};
	strNumber = new char[100];
	nrBase = 10;
	int i = 0;
	while (aux > 0)
	{
		aux1[i] = aux % 10 + '0';
		aux /= 10;
		i++;

	}
	aux1[i] = '\0';
	i--;
	for (int j = 0; j <= i; j++)
		strNumber[j] = aux1[i - j];
	strNumber[i + 1] = '\0';
	strNumberLen = i+1;
}

Number Number::operator +(const Number& otherNumber)
{
	int aux = GetBase10Value() + otherNumber.GetBase10Value();
	
	int base = std::max(nrBase, otherNumber.GetBase());
	char* aux1 = new char[100] {};
	int i = 0;
	while (aux > 0)
	{
		aux1[i] = aux % 10 + '0';
		aux /= 10;
		i++;

	}
	aux1[i] = '\0';
	i--;
	for (int j = 0; j <= i - j; j++)
		std::swap(aux1[j], aux1[i - j]);

	Number aux2(aux1, 10);
	aux2.SwitchBase(base);
	return aux2;
	

	
}

void Number::operator += (const Number& otherNumber)
{
	int aux = GetBase10Value() + otherNumber.GetBase10Value();
	int base = std::max(nrBase, otherNumber.GetBase());
	char* aux1 = new char[100] {};
	int i = 0;
	while (aux > 0)
	{
		aux1[i] = aux % 10 + '0';
		aux /= 10;
		i++;

	}
	aux1[i] = '\0';
	i--;
	for (int j = 0; j <= i; j++)
		strNumber[j] = aux1[i - j];
	
	strNumber[i + 1] = '\0';
	
	strNumberLen = i+1;
	nrBase = base;
	
	//SwitchBase(base);
}

Number Number::operator -(const Number& otherNumber)
{
	int aux = GetBase10Value() - otherNumber.GetBase10Value();
	int base = std::max(nrBase, otherNumber.GetBase());
	char* aux1 = new char[100] {};
	int i = 0;
	while (aux > 0)
	{
		aux1[i] = aux % 10 + '0';
		aux /= 10;
		i++;

	}
	aux1[i] = '\0';
	i--;
	for (int j = 0; j <= i - j; j++)
		std::swap(aux1[j], aux1[i - j]);

	Number aux2(aux1, 10);
	aux2.SwitchBase(base);
	return aux2;



}

void Number::SwitchBase(int newBase)
{
	int aux= GetBase10Value();
	char *aux1= new char[100] {};
	int cnt = 0;
	nrBase = newBase;
	while (aux)
	{
		if (aux % nrBase >= 10)
			aux1[cnt] = aux % nrBase + 'A' - 10;
		else
			aux1[cnt] = aux % nrBase + '0';
		cnt++;
		aux /= nrBase;
	}
	
	cnt--;
	for (int i = cnt ; i >= 0; i--)
		strNumber[cnt - i] = aux1[i];
	strNumber[cnt + 1] = '\0';
	strNumberLen = strlen(strNumber);
}

