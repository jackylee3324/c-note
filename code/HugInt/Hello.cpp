#include <iostream>
#include "../HugInt/huge_int.h"

using namespace std;

int main()
{
    std::cout << "Hello World Jackyg" << std::endl;

    HugeInt t1("115");
    std::cout << "output=" << t1.stringForm() << std::endl;

    //HugeInt t2("6");
    //std::cout << "output=" << t2.stringForm() << std::endl;

    //HugeInt t3=t1+t2;
    //std::cout  << "output="  << t3.stringForm() << std::endl;

   // return 0;
}

