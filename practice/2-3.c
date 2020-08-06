// function htoi: convert hexadecimal to integer

#include <stdio.h>
#include <string.h>

int htoi(char* hex);

int main() {
    printf("%d\n", htoi("0x12"));
    printf("%d\n", htoi("12"));
    printf("%d\n", htoi("0X12"));
    printf("%d\n", htoi("0Xab"));
    return 1;
}

int htoi(char* hex) {
    int len = strlen(hex);
    int sum = 0;
    int index = 0;
    if(len >= 3) {
        if(hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {
            index = 2;
        }
    }
    int val;
    for(; index < len; ++index) {
        if(hex[index] >= 'a') {
            val = hex[index] - 'a' + 10;
        }
        else if(hex[index] >= 'A') {
            val = hex[index] - 'A' + 10;
        }
        else {
            val = hex[index] - '0';
        }
        sum  = sum * 16 + val;
    } 
    return sum;
}