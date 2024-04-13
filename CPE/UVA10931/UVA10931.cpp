/*------------------------------------------------*/
// UVA10931 CPE10461
// Parity

// 輸出說明

// 思考處理
// 10進制轉2進制，顯示正確的2進制字串，求和

/*------------------------------------------------*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm> //字串反轉

using namespace std;

string toBinary(int n)
{
    string str;
    while (n != 0)
    {
        if (n % 2 == 0)
        {
            str = str + "0";
        }
        else
        {
            str = str + "1";
        }
        n = n / 2;
    }

    return str;
}

main()
{
    //設定陣列儲存輸入值
    long intputValue[100];
    for (int i = 0; i < 100; i++)
    {
        int temp;

        cin >> intputValue[i];
        if (intputValue[i] == 0)
        {
            break;
        }
    }

    for (int i = 0; i < 100; i++)
    {
        if (intputValue[i] == 0)
        {
            break;
        }
        string str1 = toBinary(intputValue[i]);

        int count = 0;
        for (int i = 0; i < str1.length(); i++)
        {
            if (str1[i] == '1')
            {
                count = count + 1;
            }
        }
        // cout << "str1 " << str1 << endl;

        // 字串反轉，要記起來，
        //reverse(str1.begin(), str1.end());
        
        // 否則自己要做陣列轉換
        string strNew;
        for (int i = str1.length() - 1; i >= 0; i--)
        {
            strNew = strNew + str1[i];
        }

        // cout << "str1 " << str1 << endl;

        cout << "The parity of " << strNew << " is " << count << " (mod 2)." << endl;
    }

    /*
    Sample Input
    1
    2
    10
    21
    0
    Sample Output
    The parity of 1 is 1 (mod 2).
    The parity of 10 is 1 (mod 2).
    The parity of 1010 is 2 (mod 2).
    The parity of 10101 is 3 (mod 2).
    */
}