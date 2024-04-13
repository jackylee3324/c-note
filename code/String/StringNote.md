
# 字串

### 1. 字串的宣告

字串是一個字元陣列，最後一個字元以空字元 '\0' 作結尾，

char 字串名稱[字串長度] ＝ “Apple”;

其他種宣告方式：

```
char str1[ 6 ] = "hello";
char str2[] = "starbucks"; // size 10
//一般的陣列宣告也適用，只是要注意會多一項‘\0’
char str3[ 6 ] = {'h', 'e', 'l', 'l', '0', '\0'};
char str4[] = {'s', 't', 'a', 'r', 'b', 'u', 'c', 'k', 's', '\0'};
```


若要得知字串所含字元長度（不包括空字元），則可以使用 strlen 函式：
size_t strlen( const char *str );


如果要進行字串複製，可以使用 strcpy 函式，若要複製字串中若干字元內容，可以使用 strncpy：
char *strcpy( char *restrict dest, const char *restrict src );
char *strncpy( char *restrict dest, const char *restrict src, size_t count );

第一個參數是目的字元陣列，第二個參數是來源字串，strncpy 第三個參數則是要複製的字元長度，

&emsp;<!--空行-->


### 2. 字串的輸入、輸出 (String Input / Output)

輸入(String Input)

**scanf**
```
#include <stdio.h>
#include <string.h>
int main()
{
    char name[20];
    int age;
    printf("Please enter your name and age\n");
    scanf("%s %d", name, &age);
    return 0;
}
```
**fgets**

fgets(陣列（字串）名稱, 想要讀取的數量大小, stdin)

fgets()會在輸出時，自動多加換行\n。
```
#include <stdio.h>
#include <string.h>
int main()
{
    char name[20];
 
    fgets (name, 20, stdin);
    puts(name);
    return 0;
}
```

&emsp;<!--空行-->

輸出（String Output）

**printf**

**puts**


&emsp;<!--空行-->

### 3.string.h

**strlen()**

得到字串長度
```
#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[80];

    puts("input string...");
    scanf("%s", buf);

    size_t length = strlen(buf);
    printf("string length:%lu\n", length);

    return 0;
}
```

strcat() — 合併兩個字串

strncat(str1（被合併的字串）, str2（原本的字串）, n) — 將str2的前n個字母合併到str1上

strcpy() — 複製字串

strncpy(str1, str2, n) — 從第str2中的第n個字母複製到str1上

strcmp() — 比較兩個字串

strchr(str1, c) — 回傳字母 c 在str1上的哪一個位置  當沒找到字母c，就會回傳NULL

strrchr(str1, c) — 倒著找回來字母 c 在str1上的哪一個位子

&emsp;<!--空行-->

**字串轉換成數字**
1. atoi ， ACSII convert to integer
2. atof ， ACSII convert to float
3. atol ， ACSII convert to long integer
```
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */

int main ()
{
    int a;
    char memory[256];
    printf ("Enter a number: ");
    fgets (memory, 256, stdin);
    a = atoi (memory);
    printf ("The value entered is %d. Its double is %d.\n", a, a*2);
    return 0;
}
```