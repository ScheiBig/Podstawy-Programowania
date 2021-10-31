#include <stdio.h>

int main()
{
    int month;

    printf("Input month number: ");
    switch (scanf("%d", &month))
    {
    case 1:
        break;
    default:
        printf("Incorrect input\n");
        return 1;
    }

    switch (month)
    {
    case 1:
        printf("Styczen\n");
        break;
    case 2:
        printf("Luty\n");
        break;
    case 3:
        printf("Marzec\n");
        break;
    case 4:
        printf("Kwiecien\n");
        break;
    case 5:
        printf("Maj\n");
        break;
    case 6:
        printf("Czerwiec\n");
        break;
    case 7:
        printf("Lipiec\n");
        break;
    case 8:
        printf("Sierpien\n");
        break;
    case 9:
        printf("Wrzesien\n");
        break;
    case 10:
        printf("Pazdziernik\n");
        break;
    case 11:
        printf("Listopad\n");
        break;
    case 12:
        printf("Grudzien\n");
        break;
    default:
        printf("Incorrect input\n");
        return 1;
    }

    return 0;
}
