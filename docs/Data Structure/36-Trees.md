# Trees

## Tree 的基本概念

廣義的 Tree 這種資料結構，其實可以算是一種非封閉性的 Graph。

#### 特性
* 由一個根節點(root) 與多個子節點(child node) 所組成
* 每個 node 的節點數量稱做 degree ，可以有多個子節點
* 每個 node 會記錄他的子節點是誰與在節點上儲存的資料
* 每個 node 只能有一個父節點
* 每一條分支都可以看作一條 Linked List
* 沒有子節點的 node 又稱作為 leaf node
* 樹裡面沒有環路(cycle)

---

## Binary Tree (二元樹)
如果把剛剛的 Tree，限制每一個 node 最多只能有兩個子節點，這時候就可以稱作為 Binary Tree 二元樹。

#### 特性
* 每一個 node 最多只能有兩個子節點
* 子節點有左右之分 (left node, right node)

---

## Binary Search Tree (二元搜尋樹)
如果我們再把訂定更多條件，他會成為一個方便搜索的 Binary Search Tree 二元搜尋樹也可以稱為有序二元樹。

#### 特性
* 左子樹上所有節點的值均小於它的根節點的值
* 右子樹上所有節點的值均大於它的根節點的值
* 任意節點的左、右子樹也分別為二元搜尋樹
* 不會出現有重複值的節點

複雜度分析
<div align="left">
<img src=./image/36/4.png/ width=50%>
</div>

---

## Full Binary Tree (滿二元樹)
* 每個非葉節點恰好有兩個子節點

## Complete Binary Tree (完整二元樹)
* 各層節點全滿，除了最後一層，最後一層節點全部靠左。，

## Perfect Binary Tree (完美二元樹)
* 符合 Full Binary Tree 與 Complete Binary Tree，也就是所有各層的節點都必須是滿的。

<div align="left">
<img src=./image/36/1.png/ width=50%>
</div>


## Balanced Binary Tree (平衡二元樹)

* 任一節點的兩個子樹高度差不超過 1。如：AVL 樹（Adelson‑Velsky and Landis Tree）、紅黑樹（Red‑Black Tree）

---

## Skewed Binary Tree (歪斜樹)

---

## binary tree traversal

* preorder traversal 前序遍歷
理論上的遍歷順序是：根、左子樹、右子樹。根排在前面。
即是depth-first search。

* inorder traversal 中序遍歷
理論上的遍歷順序是：左子樹、根、右子樹。根排在中間。
實際上是採用depth-first search，只不過更動了節點的輸出順序。

* postorder traversal 後序遍歷
理論上的遍歷順序是：左子樹、右子樹、根。根排在後面。
實際上是採用depth-first search，只不過更動了節點的輸出順序。

* level-order traversal 層序遍歷
即是breadth-first search。

<div align="left">
<img src=./image/36/2.png/ width=50%>
</div>


#### 中序如何轉換成前序或後序？記住兩個要點

* 前序就是將運算元移動貼到左括號。例如(A+B) => (+AB)
* 後序就是將運算元移動貼到右括號。例如(A+B) => (AB+)

1. 將 A + B * (C + D) + E / F 轉為前序及後序

<div align="left">
<img src=./image/36/5.png/ width=50%>
</div>


2. 將 + + * A B / - C D – E F G 轉為中序及後序

<div align="left">
<img src=./image/36/6.png/ width=50%>
</div>

---

## binary tree reconstruction

二元樹能得到前序、中序、後序、層序。現在反過來，前序、中序、後序、層序能得到二元樹嗎？

只有一種序，無法重建二元樹

## 四則運算式子，表示成二元樹，然後列出前序、中序、後序。

* 前序就是波蘭表示法，又稱作 prefix 。
* 中序就是原來的四則運算式子、需要括號，又稱作 infix 。
* 後序就是逆波蘭表示法，又稱作 postfix 。

<div align="left">
<img src=./image/36/3.png/ width=50%>
</div>

---

## B樹

B-tree 是一種樹狀的資料結構，他將資料存在節點中且樹中的節點是排序好的

<div align="left">
<img src=./image/36/7.png/ width=50%>
</div>

## B+樹

B+tree 是另一種用來儲存資料的結構，他幾乎跟 B-tree 一樣，唯一的不同是 B+tree 將資料儲存在葉節點 (e.g 沒有子節點的節點)，也就是說在 B+tree 中，所有非葉節點中的值都是從葉節點中複製的，

<div align="left">
<img src=./image/36/8.png/ width=50%>
</div>

## AVL TREE 高度平衡二元搜尋樹

AVL 樹透過頻繁旋轉來使樹達到平衡，使這棵樹可以擁有最小的搜尋成本。

AVL樹的加入與平衡

基本上，AVL樹的加入先以BST(二元搜尋樹)的方式加入，加入之後，重新計算BF(平衡因子)，當大於2時，則需要進行旋轉，共有四種旋轉方式：LL、RR、LR、RL。

<div align="left">
<img src=./image/36/9.png/ width=50%>
</div>

---

## Red Black Tree 紅黑樹

紅黑樹的5大特徵/規則：

1. RBT的每個node非黑即紅
2. Root一定是黑色
3. 每個leaf node(也就是NIL)，一定是黑色
4. 如果某個node是紅色，那他的child必定是黑色。不可以有兩個紅色node相連
5. 在任何一個node上，所有從該node走到任意descendant leaf的路徑上之黑色node數必定相同

時間複雜度
| 動作名稱 | Average  | Worst case |
| -------- | -------- | --------- |
| 查詢     | O(log N) | O(log N)   |
| 新增     | O(log N) | O(log N)   |
| 刪除     | O(log N) | O(log N)   |

## Splay Tree 伸展樹

最近一次搜尋或新增的內容，會被移至樹的 root

時間複雜度
| 動作名稱 | Average  | Worst case |
| -------- | -------- | --------- |
| 查詢     | O(log N) | O(log N)   |
| 新增     | O(log N) | O(log N)   |
| 刪除     | O(log N) | O(log N)   |