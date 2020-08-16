#include "syscalls.h"
#include <stdio.h>

/* 将输入复制到输出 */
int main() {
    char buf[BUFSIZE];
    int n;
    /* 从标准输入读入 */
    while((n = read(0, buf, BUFSIZE)) > 0) {
        /* 写到标准输出 */
        write(1, buf, n);
    }
    return 0;
}