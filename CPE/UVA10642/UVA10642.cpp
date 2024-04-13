/*------------------------------------------------*/
// UVA10642 CPE10447
// Can You Solve It?

// 輸入說明

// 思考處理
// 坐標軸跟一般XY相反
// 觀察邏輯，XY軸增加的趨勢

/*------------------------------------------------*/
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

main()
{
    // 先將輸入載入2維陣列
    // at most 201 lines of inputs.
    int intputSize = 3;
    // cin >> intputSize;

    // int intputValue[intputSize][4] = {0};
    int intputValue[intputSize][4] = {{0, 0, 0, 1}, {0, 0, 1, 0}, {0, 0, 1, 2}};
    for (int i = 0; i < intputSize; i++)
    {
        // cin >> intputValue[i][0] >> intputValue[i][1] >> intputValue[i][2] >> intputValue[i][3];
    }

    for (int i = 0; i < intputSize; i++)
    {
        int X1 = intputValue[i][0];
        int Y1 = intputValue[i][1];
        int X2 = intputValue[i][2];
        int Y2 = intputValue[i][3];

        int count = 0;
        
        // 題目看起來都是從0,0出發
        // X軸
        int X = X2 + Y2 ;                 //必走路線
        int rangeX=(X * (X + 1) / 2)-Y2;  //以X軸來觀察增加的邏輯
        count = X2 + rangeX + Y2;         //扣除Y軸差距
        //cout <<" X2="<<X2<<" Y2="<<Y2<< " X=" << X << " R=" << (X * (X + 1) / 2)-Y2 << endl;
        cout << "Case"  << " " << i << ": " << count << endl;
    }

    /*
    Sample Input
    3
    0 0 0 1
    0 0 1 0
    0 0 0 2
    Sample Output
    Case 1: 1
    Case 2: 2
    Case 3: 3
    */
}