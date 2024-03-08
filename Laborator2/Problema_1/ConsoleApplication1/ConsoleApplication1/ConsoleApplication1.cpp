
#include "NumberList.h"
#include <iostream>

int main()
{
    NumberList v;
    int x;
    v.Init();
    for (int i = 0; i < 5; i++)
    {
        std::cin >> x;
        v.Add(x);
    }
    v.Sort();
    v.Print();

}
