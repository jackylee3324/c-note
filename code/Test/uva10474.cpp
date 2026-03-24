#include <iostream>
#include <vector>

//泡泡排序模板(要記，2分鐘寫出來)
void bubbleSort(std::vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false; // 提前結束 flag
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break; // 已排序提前結束
    }
}

//二元搜尋模板(要記，2分鐘寫出來)
int binary_search(const std::vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            return mid; // 找到目標，回傳索引
        }
        else if (nums[mid] < target)
        {
            left = mid + 1; // 往右半邊找
        }
        else
        {
            right = mid - 1; // 往左半邊找
        }
    }

    return -1; // 沒找到
}

int main()
{

    int n;
    int q;

    int caseNum = 0;
    while (std::cin >> n >> q)
    {
         // n 數值陣列數 q找幾個數值
        std::vector<int> a(n); // 建立輸入陣列
        std::vector<int> result(q); // 結果陣列

        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i];
        } 

        bubbleSort(a); // 進行二分搜尋法，需要先排序

        for (int i = 0; i < q; i++)
        {
            std::cin >> result[i];
        }

        caseNum = caseNum + 1;
        std::cout << "CASE# " << caseNum++ << ":\n";

        // 處理查詢結果
        for (int i = 0; i < q; i++)
        {
            int x = result[i];
            int pos = binary_search(a, x);
            if (pos != -1)
                std::cout << x << " found at " << (pos + 1) << "\n";
            else
                std::cout << x << " not found\n";
        }
    }

    return 0;
}
