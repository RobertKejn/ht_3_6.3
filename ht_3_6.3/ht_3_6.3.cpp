
#include <iostream>
#include "Vector.h"

int main()
{
  
    Vector<int> v;
    Vector<int> v1(3);
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    Vector<int> v2(v1);
    v2.push_back(40);
    std::cout << v2.size() << " " << v2.capacity()<<"\n";
    v = v2;
    v.push_back(50);
    std::cout << v.at(4) << " " << v[5]<<"\n";
}
