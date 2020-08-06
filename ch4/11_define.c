#include <stdio.h>

#define max(A, B) ((A) > (B) ? (A) : (B))

#define square(x) x* x

int main() {
    int i = 2, j = 1;
    int max = max(i++, j);
    printf("i = %d, j = %d, max = %d\n", i, j, max);

    int z = 1;
    int res = square(z + 1);
    printf("res = %d", res);
    return 0;
}