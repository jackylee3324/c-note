# Hashing

雜湊的特色有以下幾點:

1. 無論原本的內容長短，經過雜湊演算法處理過的值都會是固定長度
2. 經由雜湊處理過的資料無法反推出原本的輸入為何
3. 兩個輸入的內容即使只差一個字， 算出來的結果會會相差非常多
4. 常用的雜湊演算法有MD5和SHA ，後者的安全性更高


## Hash Table

Hash table中文叫作雜湊表，又被稱為關聯式陣列，
是根據key來查詢資料存在哪個記憶體位置的資料結構，而這個key是透過hash function(雜湊函數)計算出來的，搜尋速度為O(1)。


## Collision (碰撞)

不同的 Data，例如 (x,y)，經過 Hashing function 計算後得出相同的 Hashing Address 稱之，也就是 H (x) = H (y)。

## Overflow (溢位)

當 Collision 發生後，且對應的 Bucket 已滿，則稱為 Overflow

## Overflow 處理方法

1. Linear Probing (線性探測)
    * 當 H (x) 發生 overflow 的時候，則探測 (H (x)+i)% B，B 為 Bucket 數，i = 1,2,3,…,B-1，直到有 Bucket 可存 or Table 全滿為止
2. Quadratic Probing (二次方探測)
    * 
    * 雖然二次探測解決了「一大坨數據擠在一起」的 Primary Clustering，但它引發了 Secondary Clustering (次要聚集)：


## 範例考題：
Collision Resolution & Performance AnalysisQuestion: Suppose we have a Hash Table of size $M = 11$ (indices $0$ to $10$). The hash function is $h(k) = k \pmod{11}$. We insert the following keys in order:$\{25, 36, 14, 47, 5, 23\}$

1. Show the final Hash Table if we use Linear Probing.
2. If we use Quadratic Probing with the probe function $f(i) = i^2$ (i.e., $h(k, i) = (h(k) + i^2) \pmod{11}$), what is the index of key $23$?
3. Calculate the Average Number of Probes for a successful search using the result from Linear Probing (Question 1).