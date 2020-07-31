#include <stdio.h>

int main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = -20;
    upper = 150;
    step = 20;

    celsius = lower;
    printf("Celsius to Fahrenheit\n");
    while (celsius <= upper) {
        fahr = celsius * 9 / 5 + 32;
        printf("%6.1f\t%4.1f\n", celsius, fahr);
        celsius += step;
    }
    return 1;
}