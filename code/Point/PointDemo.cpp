#include <stdio.h>


//main 函式在括號中總是空白的，若要使用命令列引數
//每個引數之間以空白作區隔
int main(int argc, char *argv[]) {
    
    for(int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    return 0;
}