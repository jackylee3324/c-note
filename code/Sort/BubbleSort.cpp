#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    //泡泡排序
    int input[5] = {5, 4, 3, 6, 0};
    for (int i = 0; i < 5; i++)
    {
        cout << input[i] << endl;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - 1 - i; j++)
        {
            if (input[j] < input[j + 1])
            {
                int temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] =temp;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << input[i] << endl;
    }
}