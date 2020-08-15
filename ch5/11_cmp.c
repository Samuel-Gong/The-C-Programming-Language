#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000    /* 待排序的最大行数 */
char *lineptr[MAXLINES]; /* 指向文本行的指针 */

int readlines(char *lineptr[], int nlines);
int writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

int main(int argc, char *argv[]) {
    int nlines;      /* 读入的输入行数 */
    int numeric = 0; /* 若进行数值排序，则 numeric 的值为 1 */

    if (argc > 1 && strcmp(argv[1], "-n") == 0) numeric = 1;
    if ((nlines == readlines(lineptr, MAXLINES)) >= 0) {
        qsort((void **)lineptr, 0, nlines - 1,
              (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("intput too big to sort\n");
        return 1;
    }
}

void qsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0) swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1, comp);
    qsort(v, last + 1, right, comp);
}

/* numcpm 函数: 按数值顺序比较字符串 s1 和 s2 */
int numcmp(char *s1, char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2){
        return -1;
    }
    else if (v1 > v2){
        return 1;
    }
    else{
        return 0;
    }
}

void swap(void *v[], int i, int j) {
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}