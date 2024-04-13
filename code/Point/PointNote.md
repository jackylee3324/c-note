

# Pointers 指標


指標也算是一種變數，只是裡面存的不是一般的「數字」，而是記憶體位置。

我們可以這樣宣告一個指標變數：
int *p;
int * p;
int* p;


& 憶體位址 （取址）
*取出內容 （取值）

%x 可以印出16進位
printf("The address of num is %x.\n", &num);


陣列arr[i]等同於*(arr+i)

&emsp;<!--空行-->

### Pointers 指標
```
#include<stdio.h>
int main(){
	int x = 38; //宣告變數x並指定初值
	int *p; //宣告指標變數p儲存int變數位址
	p = &x; //指定指標變數p的值是變數x的位址
	printf("變數x的位址 >> %p\n\n", &x);
	printf("指標變數p的值 >> %p\n\n", p);
	printf("指標變數p的位址 >> %p", &p);
	return 0;
}
```

```
#include <iostream>
using namespace std;
int main()
{
    int a1=5;
    int *p=NULL;      
    int **q=NULL;

    int a2;

    printf("\n");
    printf("A ==self adress==\n");
    printf("The address of &a1 is %x.\n", &a1);
    printf("The address of &p is %x.\n", &p);
    printf("The address of &q is %x.\n", &q);

    p=&a1;
    q=&p;

    printf("B ==point adress==\n");
    printf("The address of &a1 is %x.\n", &a1);
    printf("The point address of p is %x.\n", p);
    printf("The point address of q is %x.\n", q);

    printf("Z ==value==\n");
    printf("The value of a1 is %d.\n", a1);
    printf("pointing to the value *p is %d.\n", *p);
    printf("pointing to the value **q is %d.\n", **q);


    //指標也可以像一般變數一樣做運算
    a2 = a1 + 2;    // a2 變成 (5+2) 7
    a2 += a1;       // a2 變成 (7+5) 12
    *p = a2;        // a1 從5變成 12       //取出p內記憶體位址中的值 等於目前a2的值
    (*p)++;         // a1 變成 (12++) 13

    printf("Z1 ==value==\n");
    printf("The value of a1 is %d.\n", a1);
    printf("The value of a2 is %d.\n", a2);
    printf("pointing to the value *p is %d.\n", *p);
    printf("pointing to the value **q is %d.\n", **q);

    return 0;

}
```

### 指標陣列
```
#include <iostream>
using namespace std;
int main()
{

    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = NULL;
    ptr = arr; // 陣列也是一個指標，指向陣列中第一個數，ptr = &arr[0]
    for (int i = 0; i < 5; ++i)
    {
        printf("%d", *(ptr + i));
    }


    //記憶體位址的變化，4個4個跳的，原因是int的佔4bytes記憶體位址
    printf("\n");
    printf("%d %x\n", *ptr, ptr); // 10,    *ptr取值  ptr取指向的位址
    ptr++;
    printf("%d %x\n", *ptr, ptr); // 20
    ptr += 3;
    printf("%d %x\n", *ptr, ptr); // 50
    ptr--;
    printf("%d %x\n", *ptr, ptr); // 40
    ptr -= 2;
    printf("%d %x\n", *ptr, ptr); // 20

    return 0;
}
```

### 函式與指標
```
#include <iostream>
using namespace std;
void swap(int *num1, int *num2); //先告訴電腦說我有一個函式
int main()
{
    int a = 10;
    int b = 25;
    printf("a is %d, b is %d\n", a, b);
    swap(&a, &b); // 分別傳入記憶體位址
    printf("a is %d, b is %d", a, b);
    return 0;
}
void swap(int *num1, int *num2)
{
     int temp;
     temp = *num1;
     *num1 = *num2;
     *num2 = temp;
}
```

### 函式與陣列的關係
```
#include <iostream>
using namespace std;
int sum(int *arr, int element); //先告訴電腦說我有一個函式
int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int total = 0;
    total = sum(arr, 5); // 將回傳值傳到total中
    printf("Total is %d", total);
    return 0;
}
int sum(int *arr, int element) // *arr代表傳入陣列第一個數
{
    int total = 0;
     for(int i = 0; i < element; ++i)
     {
         total += arr[i];
     }
     return (total);
}
```

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

### 命令列引數

```
#include <stdio.h>

int main(int argc, char *argv[]) {
    for(int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    return 0;
}
```
參數 argc 是一個整數，記錄命令列引數的個數，這個數目包括了程式名稱，例如下面的執行指令，argc 將記錄為 5：

prog hello.c -o  -c project.p

每個引數之間以空白作區隔，上面的命令包括程式名稱共會有五個引數，即 "prog"、"hello.c"、"-o"、"-c"、"project.p"。