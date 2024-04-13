#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

main()
{

    //只會讀掉一個換行或空白
    string str1;
    cin >> str1;
    cin.clear();
    cin.sync();
    cout << "str1=" << str1 << endl;
    

    // 讀入一整行,會讀掉換行,但不會讀入字串裡
    string str2;
    getline(cin, str2);
    cin.clear();
    cin.sync();
    cout << "str2=" << str2 << endl;
}