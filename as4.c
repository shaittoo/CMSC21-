#include <stdio.h>

int main() {
    int n;
    printf("n\t2 to the n\n");
    printf("----------------\n");
    for (n = 0; n <= 10; n++) {
        printf("%d\t%d\n", n, 1 << n);
    }
    return 0;
}

