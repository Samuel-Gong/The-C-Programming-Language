#include <stdio.h>

/* 结构标记，也就是名称 */
struct point
{
    int x; /* 结构成员 */
    int y;
};

struct rect
{
    struct point pt1;
    struct point pt2;
};

int main() {
    struct point pt;
    printf("%d,%d\n", pt.x, pt.y);
    struct point maxpt = {320, 200};
    double dist, sqrt(double);
    dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
    struct rect screen;
    printf("%d,%d\n", screen.pt1.x, screen.pt1.y);
    printf("%d,%d\n", screen.pt2.x, screen.pt2.y);
    return 0;
}