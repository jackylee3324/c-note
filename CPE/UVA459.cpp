#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

// UVA459
// 找出connected components數量

vector<int> g[30];
bool visited[30];

void dfs(int u){
    visited[u] = true;
    for(int v : g[u]){   // 所有與 u 相連的節點，類似foreach
        if(!visited[v])  // 檢查節點 v 是否已經拜訪過
            dfs(v);
    }
}

int main()
{
    string str;
    getline(cin, str);
    int t;
    sscanf(str.c_str(), "%d", &t);

    //cin >> t; // 筆數
    //cin.ignore(); // 吃掉第一行的換行，每次 cin >> 後，如果下一步是 getline，幾乎都要加 cin.ignore();
    cout << endl; //換行

    while (t--)
    {

        for (int i = 0; i < 30; i++)
        {
            g[i].clear();
        }
        for (int i = 0; i < 30; i++)
        {
            visited[i] = 0;
        }


        getline(cin, str);
        int n ;
        n = str[0] - 'A' + 1; // 最大節點
        //cout << "n=" << n << endl;

        while (getline(cin,str))
        {
            if (str == "")
                break;

            int a = str[0] - 'A';
            int b = str[1] - 'A';

            g[a].push_back(b);  // push_back()	在尾端新增元素
            g[b].push_back(a);

        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i);
                count++;    // 計數
            }
        }

        cout << count << endl;
        if (t)
            cout << endl;
    }

    return 0;
}
