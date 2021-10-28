#include <stdio.h>

int main()
{
    int points;

    printf("Input the number of points: ");
    if (scanf("%d", &points) != 1 || points < 0 || points > 20)
    {
        printf("Incorrect input\n");
        return 1;
    }
    int ocena;
    if (points <= 10) ocena = 2;
    else if (points <= 13) ocena = 3;
    else if (points <= 16) ocena = 4;
    else ocena = 5;

    printf("ocena %d\n", ocena);

    return 0;
}
