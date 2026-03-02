#include <stdio.h>
#include <iostream>

void bubbleSortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n - i; j++) {
            if (arr[j - 1] < arr[j]) {
                std::swap(arr[j - 1], arr[j]);
            }
        }
    }
}


int main()
{
    std::cout << "start..." << std::endl;
    int counts = 10;
    int result[counts] = {8, 9, 0, 7, 6, 1, 2, 3, 4, 5};

    bubbleSortDesc(result, counts);
    /*
    //泡泡 
    for (int i = 0; i < counts - 1; i++)
    {
        for (int j = 1; j < counts - i; j++)
        {
            if (result[j - 1] < result[j])
            {
                std::swap(result[j - 1], result[j]);
            }
        }
    }
    */
    for (int i = 0; i < counts; i++)
    {
        std::cout << i << " :" << result[i] << std::endl;
    }
}