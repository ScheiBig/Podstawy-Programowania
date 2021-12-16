#include <stdio.h>

char imie[31] = { 0 };

int main()
{
    printf("Enter your name: ");
    scanf("%30s", imie);

    printf("Witaj %s!\n", imie);

    return 0;
}
