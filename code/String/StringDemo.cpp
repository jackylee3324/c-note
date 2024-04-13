#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
int main ()
{
    // int a;
    // char memory[256];
    // printf ("Enter a number: ");
    // fgets (memory, 256, stdin);
    // a = atoi (memory);
    // printf ("The value entered is %d. Its double is %d.\n", a, a*2);

    // string s="12";
    // int i=atoi(s.c_str());

    // cout << "number is " << i << endl;

   //單一字元
    char c1 = 'A';
    std::stringstream ss1;
    std::string s1;
    ss1 << c1;
    ss1 >> s1;                // or, use `s = ss.str()`
    std::cout << s1 << std::endl;

    //字元陣列
    char c2[]="ABC";
    std::stringstream ss2;
    std::string s2;
    ss2 << c2;
    ss2 >> s2;                // or, use `s = ss.str()`
    std::cout << s2 << std::endl;
    return 0;
}