#include <stdio.h>

#define swap(t, x, y) \
    {                 \
        t tmp = *x;   \
        *x = *y;      \
        *y = tmp;     \
    }

void swapFunc(int x, int y) {
    int tmp = x;
    x = y;
    y = x;
}

void swapFunc2(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main() {
    int x = 1;
    int y = 2;
    swapFunc(x, y);
    printf("x = %d, y = %d\n", x, y);
    swapFunc2(&x, &y);
    printf("x = %d, y = %d\n", x, y);
    swap(int, &x, &y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}