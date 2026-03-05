# Time & Space Complexity(時間複雜度與空間複雜度)


## 演算法

需滿足下列5個性質：
1. Input: 外界至少提供≥0個輸入
2. Output: Algorithm至少產生≥1個輸出結果
3. Definiteness (明確): 每個指令必須是Clear and Unambiguous
4. Finiteness (有限性): Algorithm在執行有限個步驟後，必定終止
5. Effectiveness (有效性): 用紙跟筆即可追蹤Algorithm中執行的過程及結果


## 時間複雜度 Time Complexity

時間複雜度，意思是，電腦執行這個演算法時，需要耗費多少「運算次數」來做計算

## 空間複雜度 Space Complexity

時間複雜度，意思是，電腦執行這個演算法時，所需要耗費的「記憶體空間」來做計算。

1. Big O 為評量演算法的「時間複雜度」和「空間複雜度」的方法
2. Big O 會省略所有係數
3. 「時間複雜度」不以時間，而是以運算次數來計算
4. 「空間複雜度」，以所需要耗費的「記憶體空間」來計算
5. 演算法優劣：O(1) > O(log n) > O(n) > O(n log(n)) > O(n^2) > O(2^n)