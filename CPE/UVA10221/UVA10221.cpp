/*------------------------------------------------*/
// UVA10221 CPE10424
// Satellites

// 輸入說明
// 衛星到地球表面的距離及衛星間的角度，以求最短的弧長及弦長

// 思考處理
// 需要數學公式 #include <cmath>
// M_PI，沒有使用這個會有計算誤差
// sin()

// 弧長 = 2 * 半徑 * PI * (角度/360)
// 弦距 = sin( 角度/360*PI ) * 半徑 * 2

// 浮點數顯示位元數 printf("%.6f",X1);

// 這題需要多多練習，記住公式，公式不會寫不出來

/*------------------------------------------------*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

main()
{
    double earthRadius = 6440.0;  //地球半徑
    double S;                     //衛星與地球距離
    double angle;
    string unit;

    double X1;
    double X2;

    // cin >> S >> angle >> unit;
    S = 500;
    angle = 30;
    unit = "deg";
    // 1 degree = 60 arc min
    if (unit == "min")
    {
        angle = angle / 60;
    }

    while (angle > 180)
    {
        angle = 360 - angle;
    }

    X1 = 2 * (S + earthRadius) * (angle / 360) * M_PI;
    //X2 = sin(angle / 2 * M_PI / 180.0) * (earthRadius + S) * 2;
    X2 = sin(angle/360 * M_PI) * (earthRadius + S) * 2;
    //cout  << X1 << " " << X2 << endl;
    printf("%.6f %.6f", X1,X2);


    /*
    Sample Input
    500 30 deg
    700 60 min
    200 45 deg
    Sample Output
    3633.775503 3592.408346
    124.616509 124.614927
    5215.043805 5082.035982
    */
}