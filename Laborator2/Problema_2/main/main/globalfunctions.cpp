#pragma once
#include "globalfunctions.h"
int cmp_name(students a, students b)
{

	if (strcmp(a.get_name(), b.get_name()) == 0)
		return 0;
	if (strcmp(a.get_name(), b.get_name()) > 0)
		return 1;
	return -1;
}
int cmp_mate(students a, students b)
{
	int n = a.get_mate() - b.get_mate();
	if (n == 0)
		return 0;
	if (n > 0)
		return 1;
	return -1;
}
int cmp_eng(students a, students b)
{
	int n = a.get_eng() - b.get_eng();
	if (n == 0)
		return 0;
	if (n > 0)
		return 1;
	return -1;
}
int cmp_ist(students a, students b)
{
	int n = a.get_ist() - b.get_ist();
	if (n == 0)
		return 0;
	if (n > 0)
		return 1;
	return -1;
}
int cmp_media(students a, students b)
{
	double n = a.media() - b.media();
	if (n == 0)
		return 0;
	if (n > 0)
		return 1;
	return -1;
}