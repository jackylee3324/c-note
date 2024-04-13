/*------------------------------------------------*/
// UVA299 CPE22811
// Train Swapping

// 輸入說明

// 思考處理
// 泡泡排序次數問題

/*------------------------------------------------*/
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

main()
{
    int inputSize;
    cin >> inputSize;
    int inputValue[inputSize] = {0};
    for (int i = 0; i < inputSize; i++)
    {
        cin >> inputValue[i];
        int train[inputValue[i]];
        for (int j = 0; j < inputValue[i]; j++)
        {
            cin >> train[j];
        }

        int count=0; //排序次數
        for (int i1 = 0; i1 < inputValue[i]; i1++)
        {
            for (int j1 = 0; j1 < inputValue[i] - 1 - i1; j1++)
            {
                if (train[j1] > train[j1 + 1])
                {
                    int temp = train[j1];
                    train[j1] = train[j1 + 1];
                    train[j1 + 1] = temp;
                    count=count+1;
                }
            }
        }
        cout <<"Optimal train swapping takes "<<count<<" swaps." << endl;

    }

    

    /*
    Sample Input
    3
    3
    1 3 2
    4
    4 3 2 1
    2
    2 1
    Sample Output
    Optimal train swapping takes 1 swaps.
    Optimal train swapping takes 6 swaps.
    Optimal train swapping takes 1 swaps.
    */
}