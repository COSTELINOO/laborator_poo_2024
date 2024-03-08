#pragma once
#include "students.h"
#include <cstring>
void students::set_name(char c[])
{
	for (int i = 0; i <=strlen(c); i++)
		student_name[i] = c[i];
}
void students::set_mate(int x)
{
	mate = x;
}
void students::set_eng(int x)
{
	eng = x;
}
void students::set_ist(int x)
{
	ist = x;
}
char* students::get_name()
{
	return student_name;
}
int students::get_mate()
{
	return mate;
}
int students::get_eng()
{
	return eng;
}
int students::get_ist()
{
	return ist;
}
double students::media()
{
	return (double)(mate + ist + eng) / 3;
}