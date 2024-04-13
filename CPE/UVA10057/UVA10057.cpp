/*------------------------------------------------*/
// UVA10057 CPE10409
// A mid-summer night’s dream

// 輸出說明
// 對於每組測資，輸出三個整數。
// 第一個數字是能得到該算式最小值的A。
// 第二個數字是|Xi − A|為最小值的數量。
// 第三行數字是可能有幾種最小值。

// 思考處理
// 這題問什麼不容易懂
/*------------------------------------------------*/
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

main()
{
    int intputSize;
    cin >> intputSize;

    int intput[intputSize];
    // 輸入
    for (int i = 0; i < intputSize; i++)
    {
        cin >> intput[i];
    }

    // 找出需要計算的最大數，
    int max = 1;
    for (int i = 0; i < intputSize; i++)
    {
        if (intput[i] > max)
        {
            max = intput[i];
        }
    }

    // 建立陣列儲存計算數值
    int maxValue[max];
    // 從1開始計算
    for (int m = 0; m < max; m++)
    {
        int value = 0;
        for (int i = 0; i < intputSize; i++)
        {
            // 取絕對值
            value = value + abs((m + 1) - intput[i]);
            // cout << m + 1 << " " << abs((m + 1) - intput[i]) << endl;
        }

        maxValue[m] = value;
    }

    for (int m = 0; m < max; m++)
    {
        // cout << "maxValue=" << maxValue[m] << endl;
    }

    // 1 找出最小A
    int resule1 = 0;

    int minA = maxValue[0];
    for (int m = 0; m < max; m++)
    {
        if (maxValue[m] < minA)
        {
            minA = maxValue[m];
            resule1 = m + 1;
        }
        // cout << m + 1 << "=" << maxValue[m] << endl;
    }

    //cout << "resule1=" << resule1 << endl;

    // 3 找出可能有幾種最小值
    int resule3 = 0;
    for (int m = 0; m < max; m++)
    {
        if (maxValue[m] == minA)
        {
            resule3 = resule3 + 1;
        }
    }
   // cout << "resule3=" << resule3 << endl;

    // 2 找出|Xi − A|為最小值的數量
    int resule2 = 0;

    int xaMin = 0;
    for (int i = 0; i < intputSize; i++)
    {
        int temp = abs(resule1 - intput[i]);
        if (temp < xaMin)
        {
            xaMin = temp;
        }
    }

    for (int i = 0; i < intputSize; i++)
    {
        int temp = abs(resule1 - intput[i]);
        if (temp == xaMin)
        {
            resule2 = resule2 + 1;
        }
    }
    //cout << "resule2=" << resule3 << endl;

    cout << resule1 << " " << resule2 << " " << resule3 << endl;

    /*
    Sample Input
    2
    10
    10
    4
    1
    2
    2
    4
    Sample Output
    10 2 1
    2 2 1
    */
}