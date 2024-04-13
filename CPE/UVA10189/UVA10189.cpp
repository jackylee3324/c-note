/*------------------------------------------------*/
// UVA10189
// CPE10418
// Minesweeper

// 輸入說明

// 思考處理
// 了解問題，利用迴圈

/*------------------------------------------------*/
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

main()
{
    int row;
    int col;
    cin >> row >> col;

    char intputValue[row][col] ;
    char result[row][col] ;
    for (int i = 0; i < row; i++)
    {
        string value;
        cin >> value;
        for (int j = 0; j < col; j++)
        {
            intputValue[i][j] = value[j];
        }
    }

    // 初始
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = '0';
        }
    }

    // 先給炸彈值
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (intputValue[i][j] == '*')
            {
                result[i][j] = intputValue[i][j];
            }
        }
    }

    //跑1圈給初計算+1
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (result[i][j] == '*')
            {
                ///
                int count = 0;
                int x1 = i - 1;
                int x2 = i + 1;
                int y1 = j - 1;
                int y2 = j + 1;

                for (int pi = x1; pi <= x2; pi++)
                {
                    for (int pj = y1; pj <= y2; pj++)
                    {
                        if (pi >= 0 && pi < row && pj >= 0 && pj < col)
                        {
                            if (result[pi][pj] != '*')
                            {
                                int countTemp = result[pi][pj];
                                countTemp = countTemp + 1;
                                result[pi][pj] = countTemp;
                            }
                        }
                    }
                }
                ///
            }
        }
    }

    //列印結果
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << result[i][j];
        }
        cout << endl;
    }

    /*
    Sample Input
4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0
Sample Output
Field #1:
*100
2210
1*10
1110
Field #2:
**100
33200
1*100
    */
}