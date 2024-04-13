/*------------------------------------------------*/
// UVA10062 CPE10410
// Tell me the frequencies!

// 輸入說明


// 思考處理
// 輸入字串轉ASCII，計算數量與排序

/*------------------------------------------------*/
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

main()
{

    char input[1001] = {0};
    cin >> input;


    // 字元計算
    int result[128][2];
    for (int j = 0; j < 128; j++)
    {
        result[j][0] = j + 1;
        result[j][1] = 0;
    }

    for (int i = 0; i < 1001; i++)
    {
        if (input[i] >= 32 && input[i] <= 128)
        {
            for (int j = 0; j < 128; j++)
            {
                if ((int)input[i] == result[j][0])
                {
                    
                    result[j][1] = result[j][1] + 1;
                }
            }
        }
    }

    //bobble sort
    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 128 - 1 - i; j++)
        {
            if (result[j][1] > result[j + 1][1])
            {
                int temp = result[j][1];
                result[j][1] = result[j + 1][1];
                result[j + 1][1] = temp;

                int temp2 = result[j][0];
                result[j][0] = result[j + 1][0];
                result[j + 1][0] = temp2;
            }
        }
    }

    for (int i = 0; i < 128; i++)
    {
        if (result[i][1] !=0){
            cout << (int)result[i][0] << " "<< result[i][1]<< endl;
        }
    }
    /*
    Sample Input
    AAABBC
    122333
    Sample Output
    67 1
    66 2
    65 3

    49 1
    50 2
    51 3
    */
}