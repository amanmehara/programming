#include <stdio.h>
#include <stdbool.h>

bool isLeapYear(int);

int main()
{
    printf("Is Leap Year? \n");

    int year;
    printf("year = ");
    scanf("%d", &year);

    printf(isLeapYear(year) ? "isLeapYear(%d) -> true" : "isLeapYear(%d) -> false", year);

    return 0;
}

bool isLeapYear(int year)
{
    /*
    A leap year is a year in which an extra day is added to the calendar in order to synchronize it with the seasons.
    There is a leap year every year divisible by 4 except for years which are both divisible by 100 and not divisible by 400.
    */

    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? true : false;
}