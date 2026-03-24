# CPE 常用指令


* 輸入格式：2 5 6
```
#include <iostream>
#include <cstdio>

int main()
{
    int a, b, c;

    // 輸入格式：2 5 6
    scanf("%d %d %d", &a, &b, &c);

    printf("%d %d %d\n", a, b, c);

    return 0;
}

```

* 讀取整行字串並解析多個整數
```
#include <iostream>
#include <string>
#include <cstdio>

int main() {
    std::string str;
    std::getline(std::cin, str);   // 讀取整行輸入，例如 "2 5 6"

    int a, b, c;
    sscanf(str.c_str(), "%d %d %d", &a, &b, &c);

    std::cout << a << " " << b << " " << c << std::endl;
    return 0;
}

```

* 讀取整行字串並解析字串
```
#include <iostream>
#include <string>
#include <cstdio>

int main() {
    std::string str;
    std::getline(std::cin, str);   // 讀取整行輸入，例如 "fffffxxxx"

    char buf[105];
    sscanf(str.c_str(), "%s", buf);

    std::cout << buf << std::endl;
    return 0;
}

```