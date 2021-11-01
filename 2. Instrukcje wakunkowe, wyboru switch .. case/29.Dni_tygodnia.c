#include <stdio.h>

int main()
{
    int day;
    printf("Enter number of weekday: ");
    switch (scanf("%d", &day))
    {
    case 1:
        break;
    default:
        printf("Incorrect input\n");
        return 1;
    }
    switch (day)
    {
    case 1:
        printf("poniedzialek\n");
        break;
    case 2:
        printf("wtorek\n");
        break;
    case 3:
        printf("sroda\n");
        break;
    case 4:
        printf("czwartek\n");
        break;
    case 5:
        printf("piatek\n");
        break;
    case 6:
        printf("sobota\n");
        break;
    case 7:
        printf("niedziela\n");
        break;
    default:
        printf("Incorrect input\n");
        return 1;
    }
    return 0;
}
