#include <iostream>
#include <cstring> // C 字串函式

int main() {
    char str1[20] = "Hello";    // 陣列方式
    char str2[] = "World";      // 自動大小
    const char* str3 = "C-style"; // 指標方式

    std::cout << str1 << " " << str2 << " " << str3 << std::endl;
    return 0;
}