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

## Binary Search Tree (二元搜尋樹)
如果我們再把訂定更多條件，他會成為一個方便搜索的 Binary Search Tree 二元搜尋樹也可以稱為有序二元樹。

#### 特性
* 左子樹上所有節點的值均小於它的根節點的值
* 右子樹上所有節點的值均大於它的根節點的值
* 任意節點的左、右子樹也分別為二元搜尋樹
* 不會出現有重複值的節點

---

## Full Binary Tree (滿二元樹)
* 每一層節點數都是最大節點數量

## Complete Binary Tree (完整二元樹)
* 各層節點全滿，除了最後一層，最後一層節點全部靠左。，

## Perfect Binary Tree
* 符合 Full Binary Tree 與 Complete Binary Tree，也就是所有各層的節點都必須是滿的。

<div align="left">
<img src=./image/36/1.png/ width=80%>
</div>

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
<img src=./image/36/2.png/ width=80%>
</div>