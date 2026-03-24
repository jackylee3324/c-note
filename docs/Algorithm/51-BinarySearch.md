# Search


## Binary Search 二分搜尋

1. 須事先由小到大排序過
2. O(log2n)


```

//定義：在排序好的數列裡，找某 target，找到就回傳其 index，否則回傳 -1

int binary_search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1; // array 長度 -1
    while (left <= right) {
        int mid = (left + right) / 2; // 用 int 的性質做無條件捨去
        if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {1,3,4,7,8,10};
    cout << binary_search(nums, 0)  << endl; // -1
    cout << binary_search(nums, 1)  << endl; // 0
    cout << binary_search(nums, 3)  << endl; // 1
    cout << binary_search(nums, 4)  << endl; // 2
    cout << binary_search(nums, 5)  << endl; // -1
    cout << binary_search(nums, 7)  << endl; // 3
    cout << binary_search(nums, 8)  << endl; // 4
    cout << binary_search(nums, 10) << endl; // 5
    cout << binary_search(nums, 11) << endl; // -1
}
```

## UVA10474
```
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

```