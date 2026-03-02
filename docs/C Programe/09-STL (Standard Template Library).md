# STL (Standard Template Library) STL容器

1. 序列式容器 (Sequence Containers)

| 容器 (Container) | 英文名稱 | 底層實作 | 隨機存取 `[i]` | 插入/刪除效能 | 最佳使用場景 |
| :--- | :--- | :--- | :---: | :--- | :--- |
| **`vector`** | Vector | 動態陣列 | $O(1)$ | 尾端快，中間慢 ($O(n)$) | **預設首選**。需要高效存取與頻繁尾端操作。 |
| **`list`** | List | 雙向鏈結串列 | $O(n)$ | **任何位置皆 $O(1)$** | 頻繁在中間插入或刪除元素，且不需隨機存取。 |
| **`deque`** | Double-ended Queue | 分段連續陣列 | $O(1)$ | **頭尾皆快 $O(1)$** | 需要在兩端同時進行進出操作（例如雙端隊列）。 |
| **`array`** | Array | 靜態陣列 | $O(1)$ | 不支援增減 | 已知固定長度，取代傳統 C 陣列（較安全、內建 size）。 |
| **`forward_list`**| Forward List | 單向鏈結串列 | $O(n)$ | $O(1)$ (僅限當前位置後) | 極度節省記憶體，僅需單向走訪且頻繁插入刪除。 |

---

2. 有序關聯容器 (Ordered Associative Containers)

這些容器底層使用 **紅黑樹 (Red-Black Tree)**，元素會依據 **Key** 自動排序。

| 容器 (Container) | 英文名稱 | 搜尋/插入效率 | 允許重複 Key | 排序方式 | 最佳使用場景 |
| :--- | :--- | :---: | :---: | :--- | :--- |
| **`set`** | Set | $O(\log n)$ | 否 | 由小到大 | 儲存唯一元素並自動排序。 |
| **`map`** | Map | $O(\log n)$ | 否 | 依 Key 排序 | 快速鍵值查找，且需要走訪有序資料。 |
| **`multiset`** | Multiset | $O(\log n)$ | **是** | 由小到大 | 允許重複元素且需要自動排序。 |
| **`multimap`** | Multimap | $O(\log n)$ | **是** | 依 Key 排序 | 一個鍵對應多個值的有序資料。 |



---

3. 無序關聯容器 (Unordered Associative Containers)
C++11 引入，底層使用 **哈希表 (Hash Table)**，搜尋速度最快，但不保證順序。

| 容器 (Container) | 英文名稱 | 搜尋效率 (平均) | 搜尋效率 (最差) | 核心優勢 | 最佳使用場景 |
| :--- | :--- | :---: | :---: | :--- | :--- |
| **`unordered_set`** | Unordered Set | **$O(1)$** | $O(n)$ | 速度極快 | 僅需快速判斷元素是否存在，不計較順序。 |
| **`unordered_map`** | Unordered Map | **$O(1)$** | $O(n)$ | 速度極快 | 大數據量的快速鍵值查找（最常用於 LeetCode）。 |



---

4. 容器轉接器 (Container Adapters)
對現有容器進行邏輯封裝，限制其操作方式。

| 轉接器 (Adapter) | 邏輯規則 | 預設底層 | 核心操作 | 備註 |
| :--- | :--- | :--- | :--- | :--- |
| **`stack`** | LIFO (後進先出) | `deque` | `push`, `pop`, `top` | 像堆疊盤子，最後放的最先拿。 |
| **`queue`** | FIFO (先進先出) | `deque` | `push`, `pop`, `front` | 像排隊，先到的先處理。 |
| **`priority_queue`**| 優先權佇列 | `vector` | `push`, `pop`, `top` | 每次取出的都是當前最大值。 |