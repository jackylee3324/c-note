# Graphs

## 要素
* Vertex：節點
* Edge：connection between nodes
* Weighted / Unweighted：節點間連結的值
* Directed / Undirected：連結的方向

<div align="left">
<img src=./image/37/1.png/ width=50%>
</div>


## 常見用來儲存 Graph 的方式有兩種：

Adjacency Matrix

Adjacency List

<div align="left">
<img src=./image/37/2.png/ width=50%>
</div>

## 圖的遍歷 (Graph Traversal)

* 深度優先搜尋 Depth-first Search

```
時間複雜度分析
(1)若使用adjacency lists
 則需走訪O(2*e)經過所有點(2為常數)，故時間複雜度為O(e)
(2)若使用adjacency matrix
 則需走訪(n^2^)格個儲存格，故時間複雜度為O(n^2^)
```

* 廣度優先搜尋 Breadth-first Search

```
時間複雜度分析
(1)若使用adjacency lists:
每個點都會進入Queue(佇列一次)每次delete都會走訪該點的邊，將邊連有連到的頂點插入佇列中
每個點都走訪連至的邊(2E = degree和)，故時間複雜度為O(2*E)，(2為常數)故為O(E)
(2)若使用adjacency matrix:
則需走訪所有儲存空間(n^2^)，故時間複雜度為O(n^2^)
```

## Minmim cost panning trees 最小成本生成樹

* Kruskal’s Algorithm

* Prim’s Algorithm

* Soilin’s Algorithm

## 最短路徑

#### 單一點至所有點的距離(Single Source All Destinations)

* Dijkstra's algo

* Bellmen's algo

#### 所有點至其他點的距離(All Pairs Shortest Paths)

* Floyd-Warshall

* Johnson's algo

## Topological Sort 拓樸排序

* 定義：將 DAG（有向無環圖）中的頂點排成一個線性序列，若存在邊 u -> v，則 u 必須在 v 之前。
* 必要條件：圖必須是「有向無環圖」(DAG)。若有環（Cycle），則無法進行拓樸排序。
* 非唯一性：一個 DAG 可能有多個有效的拓樸序列。

## 拓樸排序演算法

* Kahn's 演算法 (入度法/BFS)

時間複雜度：O(V+E)

* DFS 深度優先搜尋法

時間複雜度：O(V+E)

## AOV 網絡 (Activity On Vertex Network)

* 定義：用頂點表示活動，邊表示活動間的優先順序（ u -> v，表示 u 完成後才能做 v ）。
* 應用：專案管理、課程先修順序。
* 重要指標：
    1. TE (Earliest Time)：源頭到節點的最長路徑。
    2. TL (Latest Time)：最後點倒推回來的最短路徑。
    3. 關鍵路徑：TE=TL 的頂點連線，決定專案總時長。 

