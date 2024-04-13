/*------------------------------------------------*/
// UVA10908 CPE10456
// Largest Square

// 輸入說明
// 找出最大正方形的邊的長度

// 思考處理
// 不會的話依照一般邏輯處理
/*------------------------------------------------*/
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

main()
{

    int T; // 幾組測試資料
    //T=1;
    cin >> T;

    int M; // 高度
    int N; // 寬度
    int Q; // 問題數量
    
    // M=7;
    // N=10;
    // Q=4;
    cin >> M >> N >> Q;

    string bolck[M][N];
    // 將輸入字串轉入陣列
    for (int i = 0; i < M; i++)
    {
        string str;
        cin >> str;
        // if (i<3){
        //     str="abbbaaaaaa";
        // }
        // else if (i<5){
        //     str="aaaaaaaaaa";
        // }
        // else
        // {
        //      str="aaccaaaaaa";
        // }
        for (int j = 0; j < str.length(); j++)
        {
            bolck[i][j] = str[j];
        }
    }

    // // 測試列印陣列
    // cout << "test print" << endl;
    // for (int i = 0; i < M; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << bolck[i][j];
    //     }
    //     cout << "" << endl;
    // }

    // 輸入中心點
    //int center[Q][2]={{1,2},{2,4},{4,6},{5,2}};
    int center[Q][2];
    for (int i = 0; i < Q; i++)
    {
        cin >> center[i][0] >> center[i][1];
    }

    cout << M << " " << N << " " << Q << endl;

    for (int i = 0; i < Q; i++)
    {
        int X = center[i][0];
        int Y = center[i][1];
        string value = bolck[X][Y];
        int min = 0;

        // 向上找
        int minTop = 0;
        for (int top = X - 1; top >= 0; top--)
        {
            //cout<<"top="<<top<<endl;
            if (value != bolck[top][Y])
            {
                //cout<<"X="<<X<<" Y="<<Y<<" value="<<value<<" top="<<top<<endl;
                break;
            }
            else
            {
                minTop = minTop + 1;
            }
        }
        min = minTop;

        // 向下找
        int minDown = 0;
        for (int top = X + 1; top < M; top++)
        {
            if (value != bolck[top][Y])
            {
                break;
            }
            else
            {
                minDown = minDown + 1;
            }
        }
        if (min > minDown)
        {
            min = minDown;
        }

        //向左找
        int minLeft = 0;
        for (int left = Y - 1; left >= 0; left--)
        {
            if (value != bolck[X][left])
            {
                break;
            }
            else
            {
                minLeft = minLeft + 1;
            }
        }
        if (min > minLeft)
        {
            min = minLeft;
        }

        //向右找
        int minRight = 0;
        for (int right = Y + 1; right < N; right++)
        {
            if (value != bolck[X][right])
            {
                break;
            }
            else
            {
                minRight = minRight + 1;
            }
        }
        if (min > minRight)
        {
            min = minRight;
        }
        // 求出數量要轉成邊長
        cout << min * 2 + 1 << endl;
    }

    /*
    Sample Input
    1
    7 10 4
    abbbaaaaaa
    abbbaaaaaa
    abbbaaaaaa
    aaaaaaaaaa
    aaaaaaaaaa
    aaccaaaaaa
    aaccaaaaaa
    1 2
    2 4
    4 6
    5 2
    Sample Output
    7 10 4
    3
    1
    5
    1
    */
}