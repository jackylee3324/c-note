/*------------------------------------------------*/
// UVA10235 CPE10428
// Simply Emirp

// 思考處理
// 題目一定要看過，了解題目
// 123
/*------------------------------------------------*/
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

main()
{
    int intput;
    cin >> intput;

    // 輸入數值，質數的判斷，
    // 質數只能是1或是自己整除，如果有其他數字可以整除，判斷不是質數
    bool isPrime = true;
    for (int i = 2; i < intput; i++)
    {
        if (intput % i == 0)
        {
            isPrime = false; // 不是質數
            break;
        }
    }

    // 反轉數字
    string s = to_string(intput);
    // 建立陣列給值
    char c1[s.length()];
    for (int i = 0; i < s.length(); i++)
    {
        c1[i] = s[s.length() - 1 - i];
    }

    int emirp = stoi(c1);
    // cout <<"emirp="<< emirp << endl;

    // 反轉質數的判斷，
    bool isEmirp = true;
    for (int i = 2; i < intput; i++)
    {
        if (emirp % i == 0)
        {
            isEmirp = false; // 反轉不是質數
            break;
        }
    }


    // 顯示結果
    if (isPrime == false)
    {
        cout << intput << " is not prime." << endl;
    }
    else if (isEmirp == false)
    {
        cout << intput << " is prime." << endl;
    }
    else if (isEmirp == true)
    {
        cout << intput << " is emirp." << endl;
    }

    /*
    Sample Input
    17
    18
    19
    179
    199
    Sample Output
    17 is emirp.
    18 is not prime.
    19 is prime.
    179 is emirp.
    199 is emirp.
    */
}