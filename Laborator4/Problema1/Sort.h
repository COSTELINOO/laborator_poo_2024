#pragma once
class Sort
{
    int n;
    int *vector;
    
public:
    Sort(short int count);
    Sort(int count, int min, int max);
    
    Sort(int v[], int n1);
    Sort(char * s);  
    Sort(int nr, ...);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);

private:
    void QuickSort(int low, int high, bool ascendent);
    int Partition(int low, int high, bool ascendent);
};
