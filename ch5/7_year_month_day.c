#include <stdio.h>
#include <stdbool.h>

void month_day(int year, int day_of_year, int *month, int *day_of_month);

int day_of_year(int year, int month, int day);

bool is_leap_year(int year);

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int main() {
    
    return 1;
}

int day_of_year(int year, int month, int day) {
    int index = is_leap_year(year) ? 0 : 1;
    int i;
    for(i = 0; i < month; i++) {
        day += daytab[index][i];
    }
    return day;
}

void month_day(int year, int day_of_year, int *month, int *day_of_month) {
    int i, index;
    index = is_leap_year(year) ? 0 : 1;
    for(i = 0; day_of_year > daytab[index][i]; i++) {
        day_of_year -= daytab[index][i];
    }
    *month = i;
    *day_of_month = day_of_year;
}

bool is_leap_year(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}