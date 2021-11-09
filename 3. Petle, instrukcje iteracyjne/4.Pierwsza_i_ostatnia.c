#include <stdio.h>

int main()
{
    unsigned long long number;
    printf("Input your number: ");
    if (scanf("%llu", &number) != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    int t = (int) (number % 10);
    int last_digit = t == 10 ? 0 : t;

    unsigned long long first_digit = number;
    while (first_digit >= 10)
    {
        first_digit /= 10;
    }
    printf("First digit: %d\n", (int) first_digit);
    printf("Last digit: %d\n", last_digit);

    return 0;
}