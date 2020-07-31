#include <stdio.h>

int main() {
    char c;
    int nc = 0;
    while ((c = getchar()) != EOF) {
        putchar(c);
        ++nc;
    }
    printf("%d", nc);

    return 1;
}