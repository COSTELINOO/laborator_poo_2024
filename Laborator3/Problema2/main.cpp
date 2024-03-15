#include "Canvas.h"
#include<iostream>
using namespace std;
int main() {
    Canvas canvas(20, 10);

    canvas.DrawCircle(10, 5, 3, '0'); 
    canvas.FillCircle(10, 5, 3, '.');
    canvas.Print();
    canvas.Clear();
   
    

    canvas.DrawRect(5, 2, 12, 8, '0');
    canvas.FillRect(5, 2, 12, 8, '.');
    canvas.Print();
    canvas.Clear();
   

    canvas.DrawLine(2, 2, 18, 8, '0');
    canvas.Print();

 
  

    return 0;
}
