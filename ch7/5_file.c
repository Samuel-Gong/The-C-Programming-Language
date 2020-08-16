#include <stdio.h>

int main(int argc, char* argv[]) {
    FILE* fp;
    void filecopy(FILE*, FILE*);
    char *prog = argv[0]; /* 记下程序名，供错误处理用 */
    printf("program: %s\n", prog);

    if(argc == 1){/* 如果没有命令行参数，则复制标准输入 */
        filecopy(stdin, stdout);
    } else {
        while(--argc > 0) {
            if((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n",prog, *argv);
                exit(1);
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    if(ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}

/* filecopy 函数: 将文件 ifp 复制到文件 ofp */
void filecopy(FILE* ifp, FILE* ofp) {
    int c;
    while((c = getc(ifp)) != EOF) {
        putc(c, ofp);
    }
}