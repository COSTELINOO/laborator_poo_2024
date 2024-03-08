
#include <iostream>
#include "globalfunctions.h"
int main()
{
    students a, b;
    int x;
    char s[100];
    std::cin >> s;
    a.set_name(s);
        std::cin >> x;
        a.set_mate(x);
        std::cin >> x;
        a.set_eng(x);
        std::cin >> x;
        a.set_ist(x);

        std::cin >> s;
        b.set_name(s);
        std::cin >> x;
        b.set_mate(x);
        std::cin >> x;
        b.set_eng(x);
        std::cin >> x;
        b.set_ist(x);


  

    std::cout << a.get_name()<<": mate - "<<a.get_mate()<<": eng - " << a.get_eng() << ": ist - " << a.get_ist() << ": media - " << a.media()<<'\n';
    std::cout << b.get_name() << ": mate - " << b.get_mate() << ": eng - " << b.get_eng() << ": ist - " << b.get_ist() << ": media - " << b.media() << '\n';
    std::cout << "Comparare (Student a,student b): " << cmp_name(a, b) << ' '<< cmp_mate(a, b) <<' '<< cmp_eng(a, b) <<' '<< cmp_ist(a, b) <<' ' << cmp_media(a, b);
}
