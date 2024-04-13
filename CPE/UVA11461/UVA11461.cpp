/*------------------------------------------------*/
// UVA11461 CPE10480
// Square Numbers

// 輸入說明
// 給定兩個數字 a 和 b，你需要找出有多少個平方數
// 是否在 a 和 b 之間

// 思考處理
// 這題簡單寫過就會
/*------------------------------------------------*/
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

main()
{
    // 先將輸入載入2維陣列
    // at most 201 lines of inputs.
    int intputSize = 201;
    int intputValue[intputSize][2] = {0};
    for (int i = 0; i < intputSize; i++)
    {
        cin >> intputValue[i][0] >> intputValue[i][1];
        if (intputValue[i][0] == 0 && intputValue[i][1] == 0)
        {
            break;
        }
    }


    for (int i = 0; i < intputSize; i++)
    {
        int valueStart = intputValue[i][0];
        int valueEnd = intputValue[i][1];

        if (valueStart == 0 && valueEnd == 0)
        {
            break;
        }
        else
        {
            int count = 0;

            for (int j = valueStart; j <= valueEnd; j++)
            {
                //判斷相乘數值是否在範圍內
                int value = j * j;
                if (value >= valueStart && value <= valueEnd)
                {
                    count = count + 1;
                }
            }
            cout << count << endl;

            //cout << intputValue[i][0] << " " << intputValue[i][1] << " " << count << endl;
        }
    }

    /*
    Sample Input
    1 4
    1 10
    0 0
    Sample Output
    2
    3
    */
}