#include <stdio.h>

int main()
{
    unsigned int day, month, year;
    printf("Input your date: ");
    scanf("%2u-%2u-%4u", &day, &month, &year);
    printf("%-7s%4.2u\n%-7s%4.2u\n%-7s%4.4u\n",
        "Day:", day,
        "Month:", month,
        "Year:", year);

    return 0;
}