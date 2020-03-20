#include <iostream>
#include "Nod.h"
#include "set.h"
using namespace std;

int main()
{ Set l(9),s(22);
    l.insert(3);
    l.insert(8);
    l.insert(7);
     l.insert(4);
     s.insert(4);
     s.insert(25);
     l.insertAt(55,3);
    l.print();
    l*2;
    l.print();
    s.print();
    (s+l).print();
   cout<<s[]2;
}
