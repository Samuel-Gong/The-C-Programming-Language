#include <stdio.h>

int main() {
    FILE* fp;
    fp = fopen("in.txt", "r");
    int c;
    while((c = getc(fp)) != EOF) {
        putchar(c);
    }
    return 0;
}