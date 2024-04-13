/*------------------------------------------------*/
// UVA10008 CPE10402
// What's Cryptanalysis?

// 思考處理
// 將字串集中
// 拆解計算字數
// 泡泡排序(常常用到，要背起來)
/*------------------------------------------------*/
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
using std::stoi;

main()
{


    int intputSize;
    cin >> intputSize;
    cin.clear();
    cin.sync();

    string intput[intputSize];
    // 定義字串集合
    string inputAll = "";
    // 輸入字串
    for (int i = 0; i < intputSize; i++)
    {
        cout << "i=" << i << endl;


        //讀取整串文字
        string strTemp;
        getline(cin, strTemp);
        cin.clear();
        cin.sync();
        inputAll = inputAll + strTemp;
    }
    cout << inputAll << endl;

    // 定義英文字，比對使用
    string ENG = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // 儲存 為了方便計算陣列使用數字型態
    // 陣列初始化
    int result[inputAll.length()][2];
    for (int i = 0; i < inputAll.length(); i++)
    {
        result[i][0] = 0;
        result[i][1] = 0;
    }

    for (int i = 0; i < inputAll.length(); i++)
    {
        int c = toupper(inputAll[i]);

        // 篩選是否符合英文字母
        bool isExist = false;
        for (int k = 0; k < ENG.length(); k++)
        {
            int key = toupper(ENG[k]);
            if (c == key)
            {
                isExist = true;
                break;
            }
        }

        if (isExist == true)
        {
            for (int j = 0; j < inputAll.length(); j++)
            {
                if (result[j][0] == 0)
                {
                    result[j][0] = c;
                    result[j][1] = 1;
                    break;
                }
                else if (c == result[j][0])
                {
                    result[j][1] = result[j][1] + 1;
                    break;
                }
            }
        }
    }

    cout << "sort before" << endl;
    for (int i = 0; i < inputAll.length(); i++)
    {
        if (result[i][0] != 0)
        {
            cout << i << " :" << (char)result[i][0] << " :" << result[i][1] << endl;
        }
    }

    // boble sort排序
    for (int i = 0; i < inputAll.length(); i++)
    {
        for (int j = 0; j < inputAll.length() - 1 - i; j++)
        {
            // 由大到小 使用'<'
            if (result[j][1] < result[j + 1][1])
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

    cout << "sort after" << endl;
    for (int i = 0; i < inputAll.length(); i++)
    {
        if (result[i][0] != 0)
        {
            cout << i << " :" << (char)result[i][0] << " :" << result[i][1] << endl;
        }
    }

    /*
    Sample Input
    3
    This is a test.
    Count me 1 2 3 4 5.
    Wow!!!! Is this question easy?
    */
}