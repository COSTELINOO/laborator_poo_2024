#pragma once
class Number
{
	// add data members
	char* strNumber;

	int nrBase;

	unsigned int strNumberLen;

public:
	Number(const char* value, int base); // where base is between 2 and 16

	Number(int x);

	Number(const char *x);

	~Number();

	int  GetDigitsCount() const;

	bool operator <(const Number &otherNumer);

	bool operator >(const Number& otherNumer);

	char operator [](const int);

	void operator = (const Number& otherNumer);

	void operator = (const int x);

	void operator = (const char *x);

	void operator += (const Number& otherNumer);

	unsigned int GetBase10Value() const;

	Number operator +(const Number& otherNumer);

	Number operator -(const Number& otherNumer); 

		void operator --(int);

		void operator --();
	
	void SwitchBase(int newBase);

	void Print();

	int  GetBase() const;

	char* Get_Number() const;
};
