#include <stdio.h>

#define square(x) x * x

main() {

    int z = 3;
    printf("%d\n", square(z + 1));

    //x * x
    //z + 1 * z + 1
    //3 + 1 * 3 + 1
    //=7
    
}