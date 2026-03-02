#include <stdio.h>
#include <iostream>
int main()
{
    std::cout << "start..." << std::endl;
    int counts = 10;
    int result[counts] = {8, 9, 0, 7, 6, 1, 2, 3, 4, 5};

    //泡泡 
    for (int i = 0; i < counts-1; i++)
    {
        for (int j = 1; j < counts - i; j++)
        {
            if (result[j - 1] < result[j])
            {
                std::swap(result[j - 1], result[j]);
            }
        }
    }

    for (int i = 0; i < counts; i++)
    {
        std::cout << i << " :" << result[i] << std::endl;
    }
}