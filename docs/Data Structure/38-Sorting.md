# Sorting

### Bubble Sort 冒泡排序

### Selection Sort 選擇排序

### Insertion Sort 插入排序

### Quick Sort 快速排序

### Merge Sort 合併排序

### Heap Sort 堆積排序

### Bucket Sort 桶排序法

## 排序演算法複雜度整理

| 演算法 | 平均時間複雜度 | 最壞時間複雜度 | 最佳時間複雜度 | 空間複雜度 | 穩定性 |
|--------|----------------|----------------|----------------|------------|--------|
| **Bubble Sort** 冒泡排序 | O(n²) | O(n²) | O(n) | O(1) | 穩定 |
| **Selection Sort** 選擇排序 | O(n²) | O(n²) | O(n²) | O(1) | 不穩定 |
| **Insertion Sort** 插入排序 | O(n²) | O(n²) | O(n) | O(1) | 穩定 |
| **Quick Sort** 快速排序 | O(n log n) | O(n²) | O(n log n) | O(log n) (遞迴) | 不穩定 |
| **Merge Sort** 合併排序 | O(n log n) | O(n log n) | O(n log n) | O(n) | 穩定 |
| **Heap Sort** 堆積排序 | O(n log n) | O(n log n) | O(n log n) | O(1) | 不穩定 |
| **Bucket Sort** 桶排序 | O(n + k) | O(n²) (當元素集中) | O(n + k) | O(n + k) | 穩定 |


時間複雜度 (Time Complexity)：決定排序速度（最好, 平均, 最壞情況）。

空間複雜度 (Space Complexity)：排序過程中是否需要額外空間。