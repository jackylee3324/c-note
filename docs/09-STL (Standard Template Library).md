# STL (Standard Template Library) STL容器

1. 序列式容器 (Sequence Containers)


### C++ STL 序列式容器 (Sequence Containers) 對照表

| 容器 (Container) | 英文名稱 | 底層實作 | 隨機存取 `[i]` | 插入/刪除效能 | 最佳使用場景 |
| :--- | :--- | :--- | :---: | :--- | :--- |
| **`vector`** | Vector | 動態陣列 | $O(1)$ | 尾端快，中間慢 ($O(n)$) | **預設首選**。需要高效存取與頻繁尾端操作。 |
| **`list`** | List | 雙向鏈結串列 | $O(n)$ | **任何位置皆 $O(1)$** | 頻繁在中間插入或刪除元素，且不需隨機存取。 |
| **`deque`** | Double-ended Queue | 分段連續陣列 | $O(1)$ | **頭尾皆快 $O(1)$** | 需要在兩端同時進行進出操作（例如雙端隊列）。 |
| **`array`** | Array | 靜態陣列 | $O(1)$ | 不支援增減 | 已知固定長度，取代傳統 C 陣列（較安全、內建 size）。 |
| **`forward_list`**| Forward List | 單向鏈結串列 | $O(n)$ | $O(1)$ (僅限當前位置後) | 極度節省記憶體，僅需單向走訪且頻繁插入刪除。 |