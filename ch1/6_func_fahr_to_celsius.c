#include <stdio.h>

// 函数声明
void fahr2celsius(int lower, int upper, int step);

int main() {
    fahr2celsius(0, 300, 20);
}

// 函数定义
void fahr2celsius(int lower, int upper, int step) {
    int fahr;
    for (fahr = lower; fahr <= upper; fahr += step) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}