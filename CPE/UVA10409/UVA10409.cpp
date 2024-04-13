/*------------------------------------------------*/
// UVA10409 CPE11019
// Die Game

// 輸出說明

// 思考處理
// 這題問什麼不容易懂
// 先想一下數字怎麼跑，拿出盒子標示一下，試著依照input轉看看
/*------------------------------------------------*/
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

main()
{
    // 輸入
    int intputSize;
    cin >> intputSize;
    string intputValue[intputSize];
    // 輸入
    for (int i = 0; i < intputSize; i++)
    {
        cin >> intputValue[i];
    }

    // die初始數值
    int die = 1;
    // 處理
    int cnt = 0;
    while (cnt < intputSize)
    {

        if (die == 1)
        {
            if (intputValue[cnt] == "east")
            {
                die = 3;
            }
            else if (intputValue[cnt] == "west")
            {
                die = 4;
            }
            else if (intputValue[cnt] == "north")
            {
                die = 5;
            }
            else if (intputValue[cnt] == "south")
            {
                die = 2;
            }
        }
        else if (die == 2)
        {
            if (intputValue[cnt] == "east")
            {
                die = 3;
            }
            else if (intputValue[cnt] == "west")
            {
                die = 4;
            }
            else if (intputValue[cnt] == "north")
            {
                die = 1;
            }
            else if (intputValue[cnt] == "south")
            {
                die = 6;
            }
        }
        else if (die == 3)
        {
            if (intputValue[cnt] == "east")
            {
                die = 2;
            }
            else if (intputValue[cnt] == "west")
            {
                die = 5;
            }
            else if (intputValue[cnt] == "north")
            {
                die = 6;
            }
            else if (intputValue[cnt] == "south")
            {
                die = 1;
            }
        }
        else if (die == 4)
        {
            if (intputValue[cnt] == "east")
            {
                die = 5;
            }
            else if (intputValue[cnt] == "west")
            {
                die = 2;
            }
            else if (intputValue[cnt] == "north")
            {
                die = 6;
            }
            else if (intputValue[cnt] == "south")
            {
                die = 1;
            }
        }
        else if (die == 5)
        {
            if (intputValue[cnt] == "east")
            {
                die = 3;
            }
            else if (intputValue[cnt] == "west")
            {
                die = 4;
            }
            else if (intputValue[cnt] == "north")
            {
                die = 6;
            }
            else if (intputValue[cnt] == "south")
            {
                die = 1;
            }
        }
        else if (die == 6)
        {
            if (intputValue[cnt] == "east")
            {
                die = 3;
            }
            else if (intputValue[cnt] == "west")
            {
                die = 4;
            }
            else if (intputValue[cnt] == "north")
            {
                die = 2;
            }
            else if (intputValue[cnt] == "south")
            {
                die = 5;
            }
        }
        cnt++;
    }

    cout << die << endl;

    /*
    Sample Input
    1
    north
    3
    north
    east
    south
    0
    Sample Output
    5
    1
    */
}