#pragma once
#include "NumberList.h"
#include <stdio.h>
void NumberList::Init()
{
	count = 0;
}
bool NumberList::Add(int x)
{
	if (count >= 10)
		return false;
	numbers[count] = x;
	count++;

	return true;
}

void NumberList::Sort()
{
	int aux;
	for(int i=0;i<count;i++)
		for(int j=i+1;j<count;j++)
			if (numbers[i] > numbers[j])
			{
				aux = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = aux;
			}
}

void NumberList::Print()
{
	for (int i = 0; i < count; i++)
		printf("%d ",numbers[i]);
}