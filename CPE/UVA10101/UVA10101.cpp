/*------------------------------------------------*/
// UVA10101 CPE10414
// Bangla Numbers

// 輸出說明

// 思考處理

/*------------------------------------------------*/

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void toDo(long long n)
{
    if (n >= 10000000)
    {
        toDo(n / 10000000);
        cout << " kuti";
        n %= 10000000;
    }
    if (n >= 100000)
    {
        toDo(n / 100000);
        cout << " lakh";
        n %= 100000;
    }
    if (n >= 1000)
    {
        toDo(n / 1000);
        cout << " hajar";
        n %= 1000;
    }
    if (n >= 100)
    {
        toDo(n / 100);
        cout << " shata";
        n %= 100;
    }
    if (n>0){
         cout << " " << n;
    }
}

main()
{

    long long input;
    cin >> input;

    toDo(input);
    // string result;
    // int ba[4] = {10000000, 100000, 1000, 100};

    // int position = 0;
    // while (input >= 100)
    // {
    //     if (input / ba[position] > 0)
    //     {

    //     }
    //     position = position + 1;
    //     if (position == 4)
    //     {
    //         position = 0;
    //     }
    // }
}

/*
Sample Input
23764
45897458973958
Sample Output
1. 23 hajar 7 shata 64
2. 45 lakh 89 hajar 7 shata 45 kuti 89 lakh 73 hajar 9 shata 58
*/
