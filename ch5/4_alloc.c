#include <stdio.h>
#include <stddef.h>
#include <string.h>

#define ALLOCSIZE 10000 /* 可用空间大小 */

static char allocbuf[ALLOCSIZE]; /* alloc 使用的存储区 */

static char* allocp = allocbuf;

char* alloc(int n) { /* 返回指向 n 个字符的指针 */

    if (allocbuf + ALLOCSIZE - allocp >= n) { /* 有足够的空闲空间 */
        allocp += n;
        return allocp - n; /* 分配前的指针 p */
    } else {               /* 空闲空间不够 */
        return 0;
    }
}

void afree(char* p) { /* 释放 p 指向的存储区 */
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}