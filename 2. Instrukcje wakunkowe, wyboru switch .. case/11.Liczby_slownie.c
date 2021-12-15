#include <stdio.h>

char dictionary[11][10] = { "zero", "jeden", "dwa", "trzy", "cztery",
    "piec", "szesc", "siedem", "osiem", "dziewiec", "dziesiec" };

int main()
{
    int num;
    printf("Input your number: ");
    if (scanf("%d", &num) != 1)
    {
        printf("Incorrect input\n");
        return 1;
    }
    else if (num < 0 || num > 10)
    {
        printf("Incorrect input data");
        return 2;
    }
    printf("%s\n", dictionary[num]);
    return 0;
}
