#include <stdio.h>
#include <string.h>

int var;

extern int var2 = 20;

int hello(char* name) {
    printf("%s\n", name);
    return strlen(name);
}