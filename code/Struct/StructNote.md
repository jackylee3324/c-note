
# Struct 結構

### 1. Struct

Struct是一種自訂的資料型態，可以把不同的基本資料型態(int.float.double.char)變數組合，形成新的資料型態。

```
#include <stdio.h>
#include <string.h>

struct students{
    int id;
    char name[20];
    int chinese;
    int english;
};

int main()
{
    struct students one;
    
    one.id = 1;
    strcpy(one.name, "張小美");
    one.chinese = 77;
    one.english = 83;

    printf("學生編號: %d\n", one.id);
    printf("姓名: %s\n", one.name);
    printf("國文成績: %d\n", one.chinese);
    printf("英文成績: %d\n", one.english);

    return 0;
}
```

#### 定義struct

1. 純粹定義struct
```
struct students{
    int id;
    char name[20];
    int chinese;
    int english;
};
```
struct結構宣告
```
struct students someone;
```
2. 定義struct的同時宣告變數
```
struct students{
    int id;
    char name[20];
    int chinese;
    int english;
}someone;
```

3. 定義struct也宣告struct別名
```
struct students{
    int id;
    char name[20];
    int chinese;
    int english;
}
typedef struct students Student;
```
替這個新struct取好Student的別名了
```
Student someone;
```

4. 在定義struct時直接取別名
```
typedef struct{
    int id;
    char name[20];
    int chinese;
    int english;
}Student;
```

&emsp;<!--空行-->

### struct內也可以其他的struct

```
struct Student_Detail {
    int age;
    char *name;
    char *address;
};
struct Student_Data {
    int stuid;
    struct Student_Detail detail;
};
void main() {
    struct Student_Data x;
    x.stuid = 100;
    x.detail.age = 20;
    x.detail.name = "Johnson Lee";
    x.detail.address = "Nation Chi Nan University";
}
```

```
#include <stdio.h>

typedef const char* String;

typedef struct {  
    String id;  
    String name; 
    double balance;
} Account;

typedef struct {  
    Account acct;
    double overdraftlimit;

} CheckingAccount;

int main() { 
    CheckingAccount checking = {
        .acct = {"123-456-789", "Justin Lin", 1000},
        .overdraftlimit = 30000
    };

    printf("%s\n", checking.acct.id);
    printf("%s\n", checking.acct.name);
    printf("%f\n", checking.acct.balance);
    printf("%f\n", checking.overdraftlimit);

    return 0; 
} 
```

&emsp;<!--空行-->

### 用於struct的運算符號

在如下的結構定義裡,next前面的*不可省略,否則就遞迴定義了,Compiler將無法決定struct list的大小。
```
struct list {
    int data;
    struct list *next; // a pointer to struct list
};

struct list listOne, listTwo, listThree;

listOne.next = &listTwo;
listTwo.next = &listThree;
// 以下想要由listOne設定到listThree的data
listOne.next.next.data = 0; // 這不合法, 因為.的左邊必須是struct,不可以是pointer
(*(*listOne.next).next).data = 0; // 這樣寫才對
```
你會發現上面的例子中, 如果struct裡面有pointer to struct, 而我們想要用該pointer來存取結構成員時, 就必須很小心的用*和()來表達。由於結構成員包括指向結構的指標(define a pointer to struct in a struct), 是很常見的事情, 這樣的(*(*listOne.next).next).data語法既難寫又難懂, 因此C語言定義了->運算符號。此符號的左邊是一個pointer to struct, 右邊則是該pointer指到的結構成員。->為第一優先權左結合, 因此

```
(*(*listOne.next).next).data = 0; //這樣寫才對
listOne.next->next->data = 0; // 這樣寫更漂亮
```

&emsp;<!--空行-->

### 動態空間分配
所謂動態空間分配指的是,在執行期間由程式向作業系統或程式庫要求後才分配的空間,這塊記憶體區域稱為Heap(堆積)。C語言的動態空間分配主要透過malloc和free兩函數來處理。這兩個函數的宣告如下:

void *malloc(size_t size);
void free(void *ptr);
透過malloc()所分配出來的空間必須由使用者呼叫free()才能歸還給系統。初學者常犯的錯誤之一,就是忘了用free()歸還空間,這會造成程式佔用太多記憶體,此現象稱為memory leakage。相反的,如果空間已用free()歸還了,卻還試著去使用那塊記憶體,則會發生Segmentation Fault (core dumped)的錯誤。