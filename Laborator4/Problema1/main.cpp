#include <iostream>
#include "Sort.h"
#include <string>

int main() {
      Sort randomSort(10, 5, 15);
    randomSort.Print();
    short int x = 10;
    Sort initi(x);
    initi.Print();

    int array[] = { 9, 5, 7, 2, 6 };
    Sort arraySort(array, 5);
    arraySort.Print();

    char s[] = "10,40,100,5,70";
    Sort stringSort(s);
    stringSort.Print();

    Sort variadicSort(7, 4, 2, 8, 1, 9, 5, 3);
    variadicSort.Print();

    stringSort.InsertSort();
    stringSort.Print();

    variadicSort.QuickSort();
    variadicSort.Print();

    arraySort.BubbleSort();
    arraySort.Print();

    std::cout << arraySort.GetElementFromIndex(4) << ' ' << arraySort.GetElementsCount();

    return 0;
}
