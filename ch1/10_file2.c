#include "10_file2.h"
#include <stdio.h>

extern int hello(char*);

extern int var2;

int main() {
    printf("%d\n", var2);
    printf("%d\n", hello("biechen"));
    var = 10;
    printf("%d", var);
    return 1;
}