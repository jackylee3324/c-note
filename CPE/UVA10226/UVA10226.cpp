/*------------------------------------------------*/
// UVA10226 CPE10426
// Hardwood Species

// 輸入說明

// 思考處理
// 練習使用map 正向列出，反向列出
/*------------------------------------------------*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

main()
{
    int count;
    cin >> count; // the number of test cases,
    cin.clear();
    cin.sync();
    cout << "\n"; // followed by a blank line

    // 宣告一個 map，塞一些資料
    map<string, int> mapTest;
    string name="A";
    double sum = 0;

    bool isRun=true;
    while (isRun)
    {
        getline(cin, name);
        if (name==""){
            isRun=false;
        }
        else{
        mapTest[name]++;
        sum++;
        }
    }

    // 印出來
    for(auto item :mapTest){
        cout << item.first << " " << (item.second / sum) * 100 << "\n";
    }


    /*
    1
    Red Alder
    Ash
    Aspen
    Basswood
    Ash
    Beech
    Yellow Birch
    Ash
    Cherry
    Cottonwood
    Ash
    Cypress
    Red Elm
    Gum
    Hackberry
    White Oak
    Hickory
    Pecan
    Hard Maple
    White Oak
    Soft Maple
    Red Oak
    Red Oak
    White Oak
    Poplan
    Sassafras
    Sycamore
    Black Walnut
    Willow
    Sample Output
    Ash 13.7931
    Aspen 3.4483
    Basswood 3.4483
    Beech 3.4483
    Black Walnut 3.4483
    Cherry 3.4483
    Cottonwood 3.4483
    Cypress 3.4483
    Gum 3.4483
    Hackberry 3.4483
    Hard Maple 3.4483
    Hickory 3.4483
    Pecan 3.4483
    Poplan 3.4483
    Red Alder 3.4483
    Red Elm 3.4483
    Red Oak 6.8966
    Sassafras 3.4483
    Soft Maple 3.4483
    Sycamore 3.4483
    White Oak 10.3448
    Willow 3.4483
    Yellow Birch 3.4483
    */
}