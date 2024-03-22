#pragma once
#include "Sort.h"
#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include <cstdarg>
#include <cstring> 
#include<iostream>
using namespace std;
Sort::Sort(int count, int minx, int maxx):vector(new int[count]),n(count)
{
	
	srand((unsigned)time(0));
	for (int i = 0; i < count; i++)
		vector[i] = minx + rand() % (maxx - minx + 1);

}

Sort::Sort(short int count):vector(new int[count]),n(count)
{
    for (int i = 0; i < 10; i++)
        vector[i] = 0;
	
}

Sort::Sort(int v[], int n1) : vector(new int[n1]), n(n1)
{
	for (int i = 0; i < n1; i++)
		vector[i] = v[i];
}

Sort::Sort(char* s)
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
        if (s[i] == ',')
            count++;
   
    n = count + 1;
   
    count = strlen(s);
    char* strCopy = new char[count];
    for (int i = 0; i <= count; i++)
        strCopy[i] = s[i];
    char* token= strtok(strCopy,",");
    count = 0;
    while (token != nullptr) {
		int number = 0;
		for (int i = 0; i < strlen(token); i++)
		{
			number = number * 10 + (token[i] - '0');
		}
        vector[count++] = number;
        token = strtok(nullptr, ",");
    }
 
}


Sort::Sort(int count, ...):vector(new int[count]), n(count)
{
	va_list args;
	va_start(args, count);
	int sum = 0;
	for (int i = 0; i < count; ++i) {
		vector[i] = va_arg(args, int);
	}
	va_end(args);
	
}
void Sort::InsertSort(bool ascendent) {
    if (ascendent) {
        for (int i = 1; i < n; ++i) {
            int key = vector[i];
            int j = i - 1;
            while (j >= 0 && vector[j] > key) {
                vector[j + 1] = vector[j];
                j = j - 1;
            }
            vector[j + 1] = key;
        }
    }
    else {
        for (int i = 1; i < n; ++i) {
            int key = vector[i];
            int j = i - 1;
            while (j >= 0 && vector[j] < key) {
                vector[j + 1] = vector[j];
                j = j - 1;
            }
            vector[j + 1] = key;
        }
    }
}
void Sort::QuickSort(bool ascendent) {
    QuickSort(0, n - 1, ascendent);
}

void Sort::QuickSort(int low, int high, bool ascendent) {
    if (low < high) {
        int pi = Partition(low, high, ascendent);
        QuickSort(low, pi - 1, ascendent);
        QuickSort(pi + 1, high, ascendent);
    }
}

int Sort::Partition(int low, int high, bool ascendent) {
    int pivot = vector[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (ascendent ? vector[j] < pivot : vector[j] > pivot) {
            i++;
            int temp = vector[i];
            vector[i] = vector[j];
            vector[j] = temp;
        }
    }
    int temp = vector[i + 1];
    vector[i + 1] = vector[high];
    vector[high] = temp;
    return (i + 1);
}



void Sort::BubbleSort(bool ascendent) {
    if (ascendent) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (vector[j] > vector[j + 1]) {
                    int temp = vector[j];
                    vector[j] = vector[j + 1];
                    vector[j + 1] = temp;
                }
            }
        }
    }
    else {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (vector[j] < vector[j + 1]) {
                    int temp = vector[j];
                    vector[j] = vector[j + 1];
                    vector[j + 1] = temp;
                }
            }
        }
    }
}

void Sort::Print() {
    for (int i = 0; i < n; ++i) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

int Sort::GetElementsCount() {
    return n;
}

int Sort::GetElementFromIndex(int index) {
    if (index >= 0 && index < n) {
        return vector[index];
    }
    else {
        return -1; 
    }
}