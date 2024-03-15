#include "Math.h"
#include <iostream>
using namespace std;
int main()
{
   const  char *s = "Ana ",  *s1 = "are mere";
  
    cout << Math::Add(3, 4) << '\n';
    cout << Math::Add(3, 4,5) << '\n';
    cout << Math::Add(3.5,4.5) << '\n';
    cout << Math::Add(3.5, 4.5, 6.0) << '\n';
    cout << Math::Mul(3, 4) << '\n';
    cout << Math::Mul(3, 4,5) << '\n';
    cout << Math::Mul(2.5, 2.0) << '\n';
    cout << Math::Add(2.5, 3.0,2.0) << '\n';
    cout << Math::Add(5, 1,2,3,4,5) << '\n';
    char* s2= Math::Add(s, s1) ;
    cout << s2;

}
