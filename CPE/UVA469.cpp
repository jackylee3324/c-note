#include <iostream>
#include <cstdio>

// UVA469
// 找出鄰居W數量

char map[105][105];  // 紀錄輸入數據
char used[105][105]; // 紀錄遍歷
int ans[105];        // 紀錄多筆答案數據
int ansCount;

// dfs
void dfs(int x, int y)
{
    if (x < 0 || y < 0 || map[x][y] == 0)
        return;
    if (used[x][y] != 0 || map[x][y] != 'W')
        return;
    used[x][y] = 1; // 標記讀取過
    ans[ansCount]++;

    // 擴散4週數據找尋
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            dfs(x + i, y + j);
}

int main()
{
    int x, y;

    // 初始陣列
    for (int i = 0; i < 105; i++)
    {
        for (int j = 0; j < 105; j++)
        {
            map[i][j] = 0;
        }
    }

    for (int i = 0; i < 105; i++)
    {
        ans[i] = 0;
    }

    ansCount = 0;

    std::string str;
    int n = 0;
    while (std::getline(std::cin, str))
    {
        if (str[0] == '\0')
            break;

        if (str[0] == 'W' || str[0] == 'L')
        {
            sscanf(str.c_str(), "%s", map[n]);
            n++;
        }
        else
        {
            sscanf(str.c_str(), "%d %d", &x, &y);
            // 初始化
            for (int i = 0; i < 105; i++)
            {
                for (int j = 0; j < 105; j++)
                {
                    used[i][j] = 0;
                }
            }

            // ans = 0;
            dfs(x - 1, y - 1); // 對應陣列位置，需要減一

            ansCount = ansCount + 1;
        }
    }

    // printf("AAA-%d\n", ansCount);

    // 測試輸出
    for (int i = 0; i < ansCount; i++)
    {
        printf("%d\n", ans[i]);
    }

    return 0;
}
