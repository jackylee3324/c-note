
# Functions 函式

### 函式宣告

沒有回傳值

有回傳值

```
int main(void) { 
    int x = 10; 
    .... 
    printf("%d\n", increment(&x));
    printf("%d\n", x); 

    return 0; 
} 

//在函式上宣告指標參數之目的，是希望函式中可以有變動同一位址的值，如此一來，呼叫者可以保留函式中變動的結果。
int increment(int *n) { 
    *n = *n + 1; 
    return *n; 
}
```

&emsp;<!--空行-->

### 變數的範圍(Variable Scope)

**global （全域變數）**

**local （區域變數）**
```
#include <stdio.h>

int global1 = 0; // 全域變數

int main() {    
  int local1 = 2, local2 = 3; // 區域變數
  
  global1 = local1 + local2;
  printf("%d \n", global1);  /* 5 */
    
  return 0;
}
```

**靜態變數(Static Variable)**

static變數，是一個區域變數，但不會因為函式執行結束，變數內的資料就不見。

```
#include<stdio.h>
#include <iostream>
using namespace std;
int * even(); //先告訴電腦說我有一個函式
int main()
{
    int *arr; //用來存陣列
    
    arr = even();
    for(int i = 0; i < 5; ++i)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
int * even() // 回傳值是一個指標
{
     static int num[5];
     int even = 0;
     for(int i = 0; i < 5; ++i)
     {
           num[i] = even;
           even += 2;
     }
     return (num); // 直接回傳陣列（指標）回去
}
```
&emsp;<!--空行-->


### 傳遞陣列給函式

```
#include <stdio.h>
#include <stdlib.h>

void printInts(int len, int arr[len]) {
    for(int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};
    printInts(5, arr);

    return 0;
}
```

使用傳遞陣列位址的方式

```
#include <stdio.h>
#include <stdlib.h>

void printInts(int len, int *arr) {
    for(int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};
    printInts(5, arr);

    return 0;
}
```

&emsp;<!--空行-->

### 不定長度引數

透過陣列收集

```
#include <stdio.h>

void foo(int len, double* params);

int main(void) {
    double x = 1.1, y = 2.1, z = 3.9;
    double a = 0.1, b = 0.2, c = 0.3;

    puts("三個參數：");
    foo(3, (double[]) {x, y, z});

    puts("六個參數：");
    foo(6, (double[]) {x, y, z, a, b, c});

    return 0;
}

void foo(int len, double* params) {
    for(int j = 0; j < len; j++) {
        printf("%.1f\n", params[j]);
    }
}
```

使用不定長度引數
```
#include <stdio.h>
#include <stdarg.h>

void foo(int, ...);

int main(void) {
    double x = 1.1, y = 2.1, z = 3.9;
    double a = 0.1, b = 0.2, c = 0.3;

    puts("三個參數：");
    foo(3, x, y, z);

    puts("六個參數：");
    foo(6, x, y, z, a, b, c);

    return 0;
}

void foo(int len, ...) {
    va_list args;
    va_start(args, len);

    for(int j = 0; j < len; j++) {
        printf("%.1f\n", va_arg(args, double));
    }

    va_end(args);
}
```


&emsp;<!--空行-->

### 函式指標

傳回值型態 (*名稱)(參數列);

```
#include <iostream> 
using namespace std; 

int foo(int); 

int main() { 
    int (*fp)(int) = foo; 

    foo(10);  // 顯示 10
    fp(20);   // 顯示 20

    return 0; 
} 

int foo(int n) { 
    cout << "n = " << n << endl; 
    return 0; 
}
```
foo 指定給 fp，等效於 &foo 指定給 fp，在指定之後，fp 儲存了 foo 的位址，在呼叫時，fp(20) 等效於 (*fp)(20)。

&emsp;<!--空行-->

## 巨集(Macro)

C的前置處理器(Preprocessor)有一個#define命令,可用來取代原始程式內的某些字串:
```
#define PI 3.14159
main() {
    double r1 = 3.0L, r2 = 5.0L;
    printf("Circle(3) area = %lf", 2 * PI * r1 * r1);
    printf("Circle(5) area = %lf", 2 * PI * r2 * r2);
}
```
就相當於將程式寫成
```
main() {
    double r1 = 3.0L, r2 = 5.0L;
    printf("Circle(3) area = %lf", 2 * 3.14159 * r1 * r1);
    printf("Circle(5) area = %lf", 2 * 3.14159 * r2 * r2);
}
```
define不但可以做簡單的字串取代,還可以加上參數以完成複雜的字串取代工作
```
#define max(A, B) ((A) > (B) ? (A) : (B))
main() {
     int x, p=3, q=5, r=2, s=7;
     x = max(p+q, r+s);
}
```
上述程式相當於
```
main() {
     int x, p=3, q=5, r=2, s=7;
     x = ((p+q) > (r+s) ? (p+q) : (r+s));
}
```
這種巨集是由preprocessor透過字串取來達成的,和正常的函數呼叫完全不同。在下面的例子中,如果不知道square是巨集的話,就會搞不清楚為何跑出來的結果不正確了
```
#include <stdio.h>

#define square(x) x * x

main() {

    int z = 3;
    printf("%d\n", square(z + 1));

    //x * x
    //z + 1 * z + 1    字串取代
    //3 + 1 * 3 + 1
    //=7               印出來是7而不是16
    
}
```


***


## 練習

&emsp;<!--空行-->

請用函式寫出一個計算正三角形面積（可以查公式）的程式，答案要小數點下3位。

輸入：3

輸出：3.897

```
#include<stdio.h>
#include<math.h> //為了使用sqrt（開根號之意，可以上cplusplus查詢）
void Triangle( int );
int main()
{
 int a;
 scanf("%d", &a);
Triangle(a);
return 0;
}
void Triangle(int a) 
{
 float area = 0;
 area = sqrt(3) / 4 * a * a; // 公式
printf("%.3f\n", area);
 
}
```

