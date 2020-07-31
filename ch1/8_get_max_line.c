#include <stdio.h>

const int kMaxLine = 1000;

int getline_myimpl(char line[], int maxline);

void copy(char from[], char to[]);

int main() {
    int len;
    int max;
    char line[kMaxLine];    /* current input line */
    char longest[kMaxLine]; /* longest line saved here */
    max = 0;
    while ((len = getline_myimpl(line, kMaxLine))) {
        if (len > max) {
            max = len;
            copy(line, longest);
        }
    }
    printf("%s", longest);
    return 0;
}

int getline_myimpl(char line[], int maxline) {
    int c, i;
    // 这里 maxline - 1 的目的是为了给 '\0' 留出一个空间
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char from[], char to[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}